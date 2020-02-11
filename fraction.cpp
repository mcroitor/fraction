#include "fraction.h"

//additional
#include <sstream>

namespace mc {

    long long gcd(long long a, long long b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    long long abs(long long p) {
        return (p < 0) ? -p : p;
    }

    long long sign(long long p) {
        return (p < 0) ? -1 : 1;
    }

    // realization

    const double fraction::EPS = 0.000001;

    fraction::fraction()
    : numerator_(0), denominator_(1) {
    }

    fraction::fraction(const fraction& orig)
    : numerator_(orig.numerator_), denominator_(orig.denominator_) {
    }

    fraction::fraction(const long long n, const long long d) {
        numerator_ = n;
        denominator_ = d;
        normalize();
    }

    fraction::fraction(const double p) {
        numerator_ = p / fraction::EPS;
        denominator_ = 1. / fraction::EPS;
        normalize();
    }

    fraction::fraction(const long long n)
    : numerator_(n), denominator_(1) {
    }

    fraction::fraction(const int n)
    : numerator_(n), denominator_(1) {
    }

    fraction fraction::operator=(const fraction& orig) {
        numerator_ = orig.numerator_;
        denominator_ = orig.denominator_;
        return * this;
    }

    fraction::~fraction() {
    }

    void fraction::normalize() {
        long long tmp = gcd(mc::abs(numerator_), mc::abs(denominator_));
        long long sign = mc::sign(numerator_) * mc::sign(denominator_);
        numerator_ = sign * mc::abs(numerator_) / tmp;
        denominator_ = mc::abs(denominator_) / tmp;
    }

    std::string fraction::to_string() const {
        std::ostringstream strout;
        strout << numerator_ << " / " << denominator_;
        return strout.str();
    }

    double fraction::value() const {
        return double(numerator_) / denominator_;
    }

    long long fraction::numerator() const {
        return numerator_;
    }

    long long fraction::denominator() const {
        return denominator_;
    }

    //operators

    void fraction::operator*=(const fraction& p) {
        numerator_ *= p.numerator_;
        denominator_ *= p.denominator_;
        normalize();
    }

    void fraction::operator/=(const fraction& p) {
        numerator_ *= p.denominator_;
        denominator_ *= p.numerator_;
        normalize();
    }

    void fraction::operator+=(const fraction& p) {
        numerator_ = numerator_ * p.denominator_ + p.numerator_*denominator_;
        denominator_ *= p.denominator_;
        normalize();
    }

    void fraction::operator-=(const fraction& p) {
        numerator_ = numerator_ * p.denominator_ - p.numerator_*denominator_;
        denominator_ *= p.denominator_;
        normalize();
    }

    fraction operator+(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp += p2;
        return tmp;
    }

    fraction operator-(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp -= p2;
        return tmp;
    }

    fraction operator*(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp *= p2;
        return tmp;
    }

    fraction operator/(const fraction& p1, const fraction& p2) {
        fraction tmp = p1;
        tmp /= p2;
        return tmp;
    }

    bool operator==(const fraction& p1, const fraction& p2) {
        return abs(p1 - p2) < EPS;
    }

    bool operator!=(const fraction& p1, const fraction& p2) {
        return !(p1 == p2);
    }

    bool operator<(const fraction& p1, const fraction& p2) {
        return p1.value() < p2.value();
    }

    bool operator<=(const fraction& p1, const fraction& p2) {
        return !(p2 < p1);
    }

    bool operator>(const fraction& p1, const fraction& p2) {
        return p2 < p1;
    }

    bool operator>=(const fraction& p1, const fraction& p2) {
        return !(p1 < p2);
    }

    std::istream& operator>>(std::istream& in, fraction& p) {
        long long n, d;
        char fix; // is a slash sign
        in >> n >> fix >> d;
        p = fraction(n, d);
        return in;
    }

    std::ostream& operator<<(std::ostream& out, const fraction& p) {
        out << p.to_string();
        return out;
    }

    // additional functions

    fraction reduce(const fraction& p) {
        fraction result = p;
        fraction tmp = p;
        while (tmp.denominator() == p.denominator()) {
            tmp = fraction(tmp.numerator() - 1, tmp.denominator());
        }
        if (tmp == p && tmp.denominator() < result.denominator()) {
            result = tmp;
        }
        tmp = p;
        while (tmp.denominator() == p.denominator()) {
            tmp = fraction(tmp.numerator() + 1, tmp.denominator());
        }
        if (tmp == p && tmp.denominator() < result.denominator()) {
            result = tmp;
        }
        tmp = p;
        while (tmp.denominator() == p.denominator()) {
            tmp = fraction(tmp.numerator(), tmp.denominator() + 1);
        }
        if (tmp == p && tmp.denominator() < result.denominator()) {
            result = tmp;
        }
        tmp = p;
        while (tmp.denominator() == p.denominator()) {
            tmp = fraction(tmp.numerator(), tmp.denominator() - 1);
        }
        if (tmp == p && tmp.denominator() < result.denominator()) {
            result = tmp;
        }
        return result;
    }

    fraction sqrt(const fraction& p) {
        fraction result = 1;
        size_t count = 0;
        while (result * result != p) {
            result = (result + p / result) / 2;
            result = reduce(result);
            std::cout << count << " : " << result << std::endl; 
            ++ count;
            if(count > 4){
                break;
            }
        }
        return result;
    }

    fraction abs(const fraction& p) {
        return fraction(abs(p.numerator()), abs(p.denominator()));
    }
}