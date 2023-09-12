#ifndef FRACTION_H
#define FRACTION_H

#include <cstdint>
#include <iostream>
#include <string>

namespace mc {

    class fraction {
        long long numerator_, denominator_;

        void normalize();
    public:
        const static double EPS;

        fraction() = default;
        fraction(const fraction&);
        fraction(const long long, const long long);
        fraction(const double);
        fraction(const long long);
        fraction(const int);
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
    
    const static fraction EPS = fraction(fraction::EPS);

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
    
    fraction reduce(const fraction&);
    fraction abs(const fraction&);
    fraction sqrt(const fraction&);

    std::istream& operator>>(std::istream&, fraction&);
    std::ostream& operator<<(std::ostream&, const fraction&);
}

#endif /* FRACTION_H */

