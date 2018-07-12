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
    const bool& getSign() const;
    BigInteger absolute() const;
    void operator = (const BigInteger& b);
    bool operator == (const BigInteger& b) const;
    bool operator != (const BigInteger& b) const;
    bool operator > (const BigInteger& b) const;
    bool operator < (const BigInteger& b) const;
    bool operator >= (const BigInteger& b) const;
    bool operator <= (const BigInteger& b) const;
    BigInteger& operator ++(); // prefix
    BigInteger  operator ++(int); // postfix
    BigInteger& operator --(); // prefix
    BigInteger  operator --(int); // postfix
    BigInteger operator + (const BigInteger& b) const;
    BigInteger operator - (const BigInteger& b) const;
    BigInteger operator * (const BigInteger& b) const;
    BigInteger operator / (const BigInteger& b) const;
    BigInteger operator % (const BigInteger& b) const;
    BigInteger& operator += (const BigInteger& b);
    BigInteger& operator -= (const BigInteger& b);
    BigInteger& operator *= (const BigInteger& b);
    BigInteger& operator /= (const BigInteger& b);
    BigInteger& operator %= (const BigInteger& b);
    BigInteger& operator [] (int n);
    BigInteger operator -() const; // unary minus sign
    operator std::string(); // for conversion from BigInteger to std::string
};

