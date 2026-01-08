#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <exception>
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>

using BI = boost::multiprecision::cpp_int;

// Forward declarations for custom exceptions
class bad_solve_err : public std::exception {
public:
    explicit bad_solve_err(const char* msg) : message(msg) {}
    const char* what() const noexcept override { return message; }
private:
    const char* message;
};

class hack_err : public std::exception {
public:
    explicit hack_err(const char* msg) : message(msg) {}
    const char* what() const noexcept override { return message; }
private:
    const char* message;
};

// Public key structure
struct PublicKey {
    BI e;
    BI N;
};

class wienerAttack {
private:
public:
    wienerAttack();
    ~wienerAttack();

    static std::pair<BI, BI> solveQuadratic(const BI& sum_pq, const BI& N);

    struct Fraction {
        BI numerator;
        BI denominator;

        Fraction(const BI& num, const BI& denom);
        bool operator==(const Fraction& other) const;
        friend std::ostream& operator<<(std::ostream& ofs, const Fraction& fraction);
    };

    class ContinuedFraction {
    public:
        static std::vector<BI> calcCoeffs(const Fraction& fr);
        static std::vector<Fraction> convergentsCF(const std::vector<BI>& coefficients);
    };

    struct HackRes {
        BI decrypt_exp;
        BI phi;
        std::vector<Fraction> convergents;
    };

    static HackRes hack(const PublicKey& key);
};