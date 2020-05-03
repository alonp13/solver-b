#include <iostream>
#include <complex>
using namespace std;

namespace solver 
{
    class RealVariable
    {
        public:

        double m_a,m_b,m_c;


        RealVariable(): m_a(0),m_b(1),m_c(0){};
        RealVariable(double a, double b, double c): m_a(a),m_b(b),m_c(c){};

        RealVariable& operator * (double coe) const;
        RealVariable& operator * (const RealVariable& other) const;
        friend RealVariable& operator * (double coe, const RealVariable& other);

        RealVariable& operator + (double coe);
        RealVariable& operator + (const RealVariable& other);
        friend RealVariable& operator + (double coe, const RealVariable& other);
        
        RealVariable& operator - (double coe);
        RealVariable& operator - (const RealVariable& other);
        friend RealVariable& operator - (double coe, const RealVariable& other);

        RealVariable& operator / (double coe);
        friend RealVariable& operator / (double coe, const RealVariable& other);

        RealVariable& operator == (double coe) const;
        RealVariable& operator == (const RealVariable& other) const;
        friend RealVariable& operator == (double coe, const RealVariable& other);

        RealVariable& operator ^ (int pow);

    };

    class ComplexVariable
    {
        public:

        std::complex<double> m_a,m_b,m_c;


        ComplexVariable(): m_a(std::complex<double>(0,0)),m_b(std::complex<double>(1,0)),m_c(std::complex<double>(0,0)){};
        ComplexVariable(std::complex<double> a, std::complex<double> b, std::complex<double> c):
            m_a(a),m_b(b),m_c(c){};

        ComplexVariable& operator * (std::complex<double> cmplx_coe);
        ComplexVariable& operator * (double coe);
        ComplexVariable& operator * (const ComplexVariable& other);
        friend ComplexVariable& operator * (std::complex<double> cmplx_coe, const ComplexVariable& other);
        friend ComplexVariable& operator * (double coe, const ComplexVariable& other);

        ComplexVariable& operator + (double coe);
        ComplexVariable& operator + (const ComplexVariable& other);
        ComplexVariable& operator + (std::complex<double> cmplx_coe);
        friend ComplexVariable& operator + (std::complex<double> cmplx_coe, const ComplexVariable& other);
        friend ComplexVariable& operator + (double coe, const ComplexVariable& other);
        
        ComplexVariable& operator - (double coe);
        ComplexVariable& operator - (const ComplexVariable& other);
        ComplexVariable& operator - (std::complex<double> cmplx_coe);
        friend ComplexVariable& operator - (std::complex<double> cmplx_coe, const ComplexVariable& other);
        friend ComplexVariable& operator - (double coe, const ComplexVariable& other);

        ComplexVariable& operator / (double coe);
        ComplexVariable& operator / (std::complex<double> cmplx_coe);
        friend ComplexVariable& operator / (std::complex<double> cmplx_coe, const ComplexVariable& other);
        friend ComplexVariable& operator / (double coe, const ComplexVariable& other);

        ComplexVariable& operator == (double coe);
        ComplexVariable& operator == (const ComplexVariable& other);
        ComplexVariable& operator == (std::complex<double> cmplx_coe);
        friend ComplexVariable& operator == (std::complex<double> cmplx_coe, const ComplexVariable& other);
        friend ComplexVariable& operator == (double coe, const ComplexVariable& other);

        ComplexVariable& operator ^ (int pow);
    };
    double solve(const RealVariable& rv);
    std::complex<double> solve(const ComplexVariable& cv);
    
};