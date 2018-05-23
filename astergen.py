import sys
import json

with open(sys.argv[1]) as f:
    s = f.read()
    config = json.loads(s)

classes = config["classes"]
functions = config["functions"]
baseClass = config["baseType"]
returnType = config["returnType"]

back_declaration_template = "virtual ReturnType back_foo(Secondary*);"

back_definition_template = ""
if returnType == "void":
    back_definition_template = "ReturnType Primary::back_foo(Secondary* _) { _->foo(this); }"
else:
    back_definition_template = "ReturnType Primary::back_foo(Secondary* _) { return _->foo(this); }"

declaration_template = "virtual ReturnType foo(Secondary*);"

definition_template = ""
if returnType == "void":
    definition_template = "ReturnType Primary::foo(Secondary* _) { _->back_foo(this); }"
else:
    definition_template = "ReturnType Primary::foo(Secondary* _) { return _->back_foo(this); }"

body_template = "ReturnType Primary::foo(Secondary* _)\n{\n    defaultCode\n}\n"
forward_declaration_template = "class Primary;"

class_declaration_template = """
class Primary : public Base
{
public:
definitions
};""".replace("Base", baseClass)

base_class_declaration_template = """
class Base
{
public:
definitions
};""".replace("Base", baseClass)

class_declarations = []


def make_macro():
    prototypes = []
    for foo in functions:
        prototypes.append(declaration_template \
            .replace("ReturnType", returnType) \
            .replace("Secondary", baseClass) \
            .replace("foo", foo)) \

        for secondary in classes:
            prototypes.append( back_declaration_template \
                .replace("ReturnType", returnType) \
                .replace("foo", foo) \
                .replace("Secondary", secondary) )

        for secondary in classes:
            prototypes.append( declaration_template \
                .replace("ReturnType", returnType) \
                .replace("foo", foo) \
                .replace("Secondary", secondary) )

    return "    " + "\\\n    ".join(prototypes)


macroName = config["macro"]

def make_base_class_declaration():
    prototypes = []
    for foo in functions:
        prototypes += [declaration_template \
            .replace("ReturnType", returnType) \
            .replace("Secondary", baseClass) \
            .replace("foo", foo) \
            .replace(";", " = 0;")]

        for secondary in classes:
            prototypes.append( back_declaration_template \
                .replace("ReturnType", returnType) \
                .replace("foo", foo) \
                .replace("Secondary", secondary) \
                .replace(";", " = 0;") )

    return base_class_declaration_template \
        .replace("definitions", "    " + "\n    ".join(prototypes) )


def make_primary_class_declarations():
    declarations = []
    for primary in classes:
        declarations.append(class_declaration_template \
            .replace("definitions", macroName) \
            .replace("Primary", primary)
            )
    return "\n".join(declarations)


def make_class_declarations():
    return make_base_class_declaration() + "\n"\
        + make_primary_class_declarations()


def make_level_one_source():
    bodies = []
    for foo in functions:
        for primary in classes:
            bodies.append(definition_template \
                .replace("ReturnType", returnType) \
                .replace("foo", foo) \
                .replace("Primary", primary) \
                .replace("Secondary", baseClass))

            for secondary in classes:
                bodies.append(back_definition_template \
                    .replace("ReturnType", returnType) \
                    .replace("foo", foo) \
                    .replace("Primary", primary) \
                    .replace("Secondary", secondary))
    return "\n".join(bodies)

defaultCode = config["defaultCode"]

def make_source():
    bodies = []
    for foo in functions:
        for primary in classes:
            for secondary in classes:
                bodies.append(body_template \
                    .replace("ReturnType", returnType) \
                    .replace("foo", foo) \
                    .replace("Primary", primary) \
                    .replace("Secondary", secondary) \
                    .replace("defaultCode", defaultCode))
    return "\n".join(bodies)


def make_forward_declarations():
    declarations = [forward_declaration_template \
            .replace("Primary", baseClass)]
    for c in classes:
        declarations.append(forward_declaration_template.replace("Primary", c))
    return "\n".join(declarations)


headerName = config["header"]
sourceName = config["source"]
namespaceName = config["namespace"]

with open(headerName, "w") as f:
    headerOnceConstant = headerName.replace(".","_")
    f.write("#ifndef _" + headerOnceConstant + "_\n")
    f.write("#define _" + headerOnceConstant + "_\n\n")
    f.write("namespace " + namespaceName + "\n{\n")
    f.write(make_forward_declarations() + "\n\n")
    f.write("#define " + macroName + " \\\n" + make_macro() + "\n\n")
    f.write(make_class_declarations() + "\n\n")
    f.write("\n}\n")
    f.write("\n#endif\n")


with open(sourceName, "w") as f:

    f.write("#include \"" + headerName + "\"\n")
    f.write("namespace " + namespaceName + "\n")
    f.write("{\n")

    f.write(make_source() + "\n")
    f.write(make_level_one_source() + "\n\n")

    f.write("}")




