#include <string>
#define MAX 10000 // for std::strings

class BigInteger
{
private:
    std::string number;
    bool sign;
public:
    BigInteger(); // empty constructor initializes zero
    BigInteger(std::string s); // "std::string" constructor
    BigInteger(std::string s, bool sin); // "std::string" constructor
    BigInteger(int n); // "int" constructor
    void setNumber(std::string s);
    const std::string& getNumber() const;
    std::string toString() const;
    double toDouble() const;
    size_t toSizeT() const;
    void setSign(bool s);
    const bool& getSign();
    BigInteger absolute(); // returns the absolute value
    void operator = (BigInteger b);
    bool operator == (BigInteger b);
    bool operator != (BigInteger b);
    bool operator > (BigInteger b);
    bool operator < (BigInteger b);
    bool operator >= (BigInteger b);
    bool operator <= (BigInteger b);
    BigInteger& operator ++(); // prefix
    BigInteger  operator ++(int); // postfix
    BigInteger& operator --(); // prefix
    BigInteger  operator --(int); // postfix
    BigInteger operator + (BigInteger b);
    BigInteger operator - (BigInteger b);
    BigInteger operator * (BigInteger b);
    BigInteger operator / (BigInteger b);
    BigInteger operator % (BigInteger b);
    BigInteger& operator += (BigInteger b);
    BigInteger& operator -= (BigInteger b);
    BigInteger& operator *= (BigInteger b);
    BigInteger& operator /= (BigInteger b);
    BigInteger& operator %= (BigInteger b);
    BigInteger& operator [] (int n);
    BigInteger operator -(); // unary minus sign
    operator std::string(); // for conversion from BigInteger to std::string
private:
    bool equals(BigInteger n1, BigInteger n2);
    bool less(BigInteger n1, BigInteger n2);
    bool greater(BigInteger n1, BigInteger n2);
    std::string add(std::string number1, std::string number2);
    std::string subtract(std::string number1, std::string number2);
    std::string multiply(std::string n1, std::string n2);
    std::pair<std::string, long long> divide(std::string n, long long den);
    std::string toString(long long n);
};

