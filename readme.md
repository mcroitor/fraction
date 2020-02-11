# fraction

Simple C++ class `fraction` provides manipulations with N/D fractions.

## compiling

just make it: `make`

## testing

for testing _catch_ library is used. `make test` is enough.
## Interface:
```C++
namespace mc {
    class fraction {
    public:
        fraction();
        fraction(const fraction&);
        fraction(const long long, const long long);
        fraction(const double);
        fraction(const long long);
        fraction operator=(const fraction&);
        virtual ~fraction();

        std::string to_string() const;
        long long numerator() const;
        long long denominator() const;
        double value() const;

        void operator+=(const fraction&);
        void operator-=(const fraction&);
        void operator*=(const fraction&);
        void operator/=(const fraction&);
    };

    bool operator==(const fraction&, const fraction&);
    bool operator!=(const fraction&, const fraction&);
    bool operator<(const fraction&, const fraction&);
    bool operator<=(const fraction&, const fraction&);
    bool operator>(const fraction&, const fraction&);
    bool operator>=(const fraction&, const fraction&);

    fraction operator+(const fraction&, const fraction&);
    fraction operator-(const fraction&, const fraction&);
    fraction operator*(const fraction&, const fraction&);
    fraction operator/(const fraction&, const fraction&);

    std::istream& operator>>(std::istream&, fraction&);
    std::ostream& operator<<(std::ostream&, const fraction&);
}
```
