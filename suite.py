import os
import subprocess

def run(*params):
    proc = subprocess.Popen(list(params), shell=False, stdout=subprocess.PIPE)
    bytes_string, err = proc.communicate()
    return str(bytes_string, 'utf-8').strip()


def expect(source, expected_result):
    f = open('TEMP.cal','w')
    f.write(source)
    f.close()

    actual_result  = run('./calam', 'TEMP.cal')
    print('source: ' + source)
    if actual_result != expected_result:
        print('FAILED:')
        print('expected result : ' + expected_result)
        print('actual result   : ' + actual_result)
        print('')

    os.remove('TEMP.cal')


expect(r'true', 'true')
expect(r'not true', 'false')
expect(r'not false', 'true')
expect(r'true and false', 'false')
expect(r'true and true', 'true')
expect(r'true or false', 'true')
expect(r'false or false', 'false')
expect(r'2+4', '6')
expect(r'2<4', 'true')
expect(r'2>4', 'false')
expect(r'2<=4', 'true')
expect(r'2>=4', 'false')
expect(r'n=10; m=5; n-m+1', '6')
expect(r'(1+2)-3', '0')
expect(r'1.0', '1.000000')
expect(r'1.0 + 2.3', '3.300000')
expect(r'1.0 * 2.3', '2.300000')
expect(r'm = 3; x = 7; b = -2; m*x+b', '19')
expect(r'm = 3; x = 7; b = -2; b+m*x', '19')
expect(r'm = 3; x = 7; b = -2; -b+m*x', '23')
expect(r'm = 3; x = 7; b = -2; -b + -m*x', '-19')
expect(r'a = 3; b = 5; -a+b', '2')
expect(r'a = 3; b = 5; -(a+b)', '-8')
expect(r'"abc"','"abc"')
expect(r'"abc" + "def"','"abcdef"')
expect(r'[1,2,3]','[1,2,3,]')
expect(r'[1,2,3] + [4,5,6]','[1,2,3,4,5,6,]')
expect(r'3 * [3]','[3,3,3,]')
expect(r'2 * 3 * [3]','[3,3,3,3,3,3,]')
expect(r'z=(x=1); z.x', '1')
expect(r'(x=1).x', '1')
expect(r'x=1', '(x=1,)')
expect(r'{}()', '()')
expect(r'{x}(x=1)', '1')
expect(r'(y=7)::{x+y}(x=1)', '8')
expect(r'(t=0)::{t=t+1}[3,4,5].t', '3')
expect(r'(true: {3}, false: {4}) 1<2 ()', '3')
expect(r'f = {23}; 1+f()', '24')
