#include <iostream>
#include <complex>
using namespace std;
namespace solver 
{
    class Equation
    {
        public:
            //Should be Private:
            double m_a;
            double m_b;
            double m_c;
            //
        
            Equation(): m_a(0) , m_b(0), m_c(0) {};
            Equation(double a,double b,double c): m_a(a),m_b(b),m_c(c){};

            Equation& operator+(const Equation other) const;
            Equation& operator+(double c) const;
//            Equation& operator+(const RealVariable rv) const;
            
    };


    class RealVariable
    {
        public:

            // double m_coe;
            // int m_pow;
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
        RealVariable& operator / (const RealVariable& other);
        friend RealVariable& operator / (double coe, const RealVariable& other);

        RealVariable& operator == (double coe) const;
        RealVariable& operator == (const RealVariable& other) const;
        friend RealVariable& operator == (double coe, const RealVariable& other);

        RealVariable& operator ^ (int pow);

        // double getReal() const;
    };

    class ComplexVariable
    {
        private:

            double m_real;
            double m_img;

        public:

        ComplexVariable(): m_real(0), m_img(0){};
        ComplexVariable(double real,double img): m_real(real),m_img(img){};


        // ComplexVariable& operator + (double coe);
        // ComplexVariable& operator + (const ComplexVariable& other);
        // ComplexVariable& operator + (std::complex<double> cmplx_coe);
        // friend ComplexVariable& operator + (std::complex<double> cmplx_coe, const ComplexVariable& other);
        // friend ComplexVariable& operator + (double coe, const ComplexVariable& other);
        
        // ComplexVariable& operator - (double coe);
        // ComplexVariable& operator - (const ComplexVariable& other);
        // ComplexVariable& operator - (std::complex<double> cmplx_coe);
        // friend ComplexVariable& operator - (std::complex<double> cmplx_coe, const ComplexVariable& other);
        // friend ComplexVariable& operator - (double coe, const ComplexVariable& other);

        // ComplexVariable& operator * (double coe);
        // ComplexVariable& operator * (const ComplexVariable& other);
        // ComplexVariable& operator * (std::complex<double> cmplx_coe);
        // friend ComplexVariable& operator * (std::complex<double> cmplx_coe, const ComplexVariable& other);
        // friend ComplexVariable& operator * (double coe, const ComplexVariable& other);

        // ComplexVariable& operator / (double coe);
        // ComplexVariable& operator / (const ComplexVariable& other);
        // ComplexVariable& operator / (std::complex<double> cmplx_coe);
        // friend ComplexVariable& operator / (std::complex<double> cmplx_coe, const ComplexVariable& other);
        // friend ComplexVariable& operator / (double coe, const ComplexVariable& other);

        // ComplexVariable& operator == (double coe);
        // ComplexVariable& operator == (const ComplexVariable& other);
        // ComplexVariable& operator == (std::complex<double> cmplx_coe);
        // friend ComplexVariable& operator == (std::complex<double> cmplx_coe, const ComplexVariable& other);
        // friend ComplexVariable& operator == (double coe, const ComplexVariable& other);

        // ComplexVariable& operator ^ (int pow);
    };
  //  double solve(const Equation& eq);
    double solve(const RealVariable& rv);
//    std::complex<double> solve(const ComplexVariable& cv);
    
};