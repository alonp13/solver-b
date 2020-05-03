#include "solver.hpp"
#include <stdexcept>
#include <cmath>
using namespace solver;

/*
    ComplexVariable Class implemention:
*/

// Operator *:
ComplexVariable& ComplexVariable::operator * (std::complex<double> cmplx_coe)
{
    ComplexVariable * res = new ComplexVariable(m_a*cmplx_coe,m_b*cmplx_coe,m_c*cmplx_coe);
    return *res;
}

ComplexVariable& ComplexVariable::operator * (double coe)
{
    std::complex<double> cmplx_coe = std::complex<double>(coe,0);
    ComplexVariable tmp(m_a,m_b,m_c);
    ComplexVariable * res = &(tmp * cmplx_coe);
    return *res;
}

ComplexVariable& ComplexVariable::operator * (const ComplexVariable& other)
{
    std::complex<double> zero = std::complex<double>(0,0);
    // Handle the power > 2
    if(m_a * other.m_a != zero || (m_a * other.m_b + m_b * other.m_a) != zero)
    {
        throw runtime_error("Power cannot be greater then 2!");
    }
    std::complex<double> a = m_a*other.m_c + m_b*other.m_b + m_c * other.m_a;
    std::complex<double> b = m_b * other.m_c + m_c * other.m_b;
    std::complex<double> c = m_c * other.m_c;

    ComplexVariable * res = new ComplexVariable(a,b,c);
    return *res;
}

ComplexVariable& solver::operator * (std::complex<double> cmplx_coe, const ComplexVariable& other) // friend
{
    ComplexVariable * res = new ComplexVariable(other.m_a*cmplx_coe,other.m_b*cmplx_coe,other.m_c*cmplx_coe);
    return *res;  
}

ComplexVariable& solver::operator * (double coe, const ComplexVariable& other) //friend
{
    std::complex<double> cmplx_coe = std::complex<double>(coe,0);
    ComplexVariable tmp(other.m_a,other.m_b,other.m_c);
    ComplexVariable * res = &(tmp * cmplx_coe);
    return *res;    
}

// Operator +:
ComplexVariable& ComplexVariable::operator + (std::complex<double> cmplx_coe)
{
    ComplexVariable * res = new ComplexVariable(m_a,m_b,m_c+cmplx_coe);
    return *res;    
}

ComplexVariable& ComplexVariable::operator + (double coe)
{
    ComplexVariable * res = new ComplexVariable(m_a,m_b,m_c+coe);
    return *res; 
}

ComplexVariable& ComplexVariable::operator + (const ComplexVariable& other)
{
    ComplexVariable * res = new ComplexVariable(m_a+other.m_a,m_b+other.m_b,m_c+other.m_c);
    return *res; 
}

ComplexVariable& solver::operator + (std::complex<double> cmplx_coe, const ComplexVariable& other) //friend
{
    ComplexVariable * res = new ComplexVariable(other.m_a,other.m_b,other.m_c+cmplx_coe);
    return *res;    
}

ComplexVariable& solver::operator + (double coe, const ComplexVariable& other) //friend
{
    ComplexVariable * res = new ComplexVariable(other.m_a,other.m_b,other.m_c+coe);
    return *res;    
}

// Operator ==:
ComplexVariable& ComplexVariable::operator == (std::complex<double> cmplx_coe)
{
    ComplexVariable * res = new ComplexVariable(m_a,m_b,m_c-cmplx_coe);
    return *res; 
}

ComplexVariable& ComplexVariable::operator == (double coe)
{
    ComplexVariable * res = new ComplexVariable(m_a,m_b,m_c-coe);
    return *res; 
}

ComplexVariable& ComplexVariable::operator == (const ComplexVariable& other)
{
    ComplexVariable * res = new ComplexVariable(m_a-other.m_a,m_b-other.m_b,m_c-other.m_c);
    return *res; 
}

ComplexVariable& solver::operator == (std::complex<double> cmplx_coe, const ComplexVariable& other) //friend
{
    ComplexVariable * res = new ComplexVariable(other.m_a,other.m_b,other.m_c-cmplx_coe);
    return *res; 
}

ComplexVariable& solver::operator == (double coe, const ComplexVariable& other) //friend
{
    ComplexVariable * res = new ComplexVariable(other.m_a,other.m_b,other.m_c-coe);
    return *res; 
}

// Operator -:
ComplexVariable& ComplexVariable::operator - (double coe)
{
    ComplexVariable * res = new ComplexVariable(m_a,m_b,m_c-coe);
    return *res;     
}

ComplexVariable& ComplexVariable::operator - (const ComplexVariable& other)
{
    ComplexVariable * res = new ComplexVariable(m_a-other.m_a,m_b-other.m_b,m_c-other.m_c);
    return *res; 
}

ComplexVariable& ComplexVariable::operator - (std::complex<double> cmplx_coe)
{
    ComplexVariable * res = new ComplexVariable(m_a,m_b,m_c-cmplx_coe);
    return *res; 
}

ComplexVariable& solver::operator - (std::complex<double> cmplx_coe, const ComplexVariable& other) //friend
{
    ComplexVariable * res = new ComplexVariable(-other.m_a,-other.m_b,cmplx_coe-other.m_c);
    return *res; 
}

ComplexVariable& solver::operator - (double coe, const ComplexVariable& other) //friend
{
    ComplexVariable * res = new ComplexVariable(-other.m_a,-other.m_b,coe-other.m_c);
    return *res;    
}

// Operator /:
ComplexVariable& ComplexVariable::operator / (double coe)
{
    if(coe == 0)
    {
        throw runtime_error("Cannot divide by 0!");
    }

    ComplexVariable * res = new ComplexVariable(m_a/coe,m_b/coe,m_c/coe);
    return *res; 
}

ComplexVariable& ComplexVariable::operator / (std::complex<double> cmplx_coe)
{
    if(cmplx_coe == std::complex<double>(0,0))
    {
        throw runtime_error("Cannot divide by 0!");
    }

    ComplexVariable * res = new ComplexVariable(m_a/cmplx_coe,m_b/cmplx_coe,m_c/cmplx_coe);
    return *res; 
}

ComplexVariable& solver::operator / (std::complex<double> cmplx_coe, const ComplexVariable& other) //friend
{
    std::complex<double> zero = std::complex<double>(0,0);
    if(other.m_a == zero || other.m_b == zero || other.m_c == zero)
    {
        throw runtime_error("Cannot divide by 0!");
    }
    ComplexVariable * res = new ComplexVariable(cmplx_coe/other.m_a,cmplx_coe/other.m_b,cmplx_coe/other.m_c);
    return *res; 
}

ComplexVariable& solver::operator / (double coe, const ComplexVariable& other) //friend
{
    std::complex<double> zero = std::complex<double>(0,0);
    if(other.m_a == zero || other.m_b == zero || other.m_c == zero)
    {
        throw runtime_error("Cannot divide by 0!");
    }
    ComplexVariable * res = new ComplexVariable(coe/other.m_a,coe/other.m_b,coe/other.m_c);
    return *res; 
}

// Operator ^:
ComplexVariable& ComplexVariable::operator ^ (int pow)
{
        ComplexVariable * res;
    if(pow < 0 || pow > 2 || (m_a != std::complex<double>(0,0) && pow > 1))
    {
        throw runtime_error("Power cannot be greater then 2 or less then 0!");
    }

    if(pow == 0)
    {
        res = new ComplexVariable(0,0,1);
        return *res;   
    }
    else if(pow == 1)
    {
        res = new ComplexVariable(m_a,m_b,m_c);
        return *res;         
    }
    else
    {
        ComplexVariable x(m_a,m_b,m_c);
        ComplexVariable y(m_a,m_b,m_c);
        res = &(x*y);
        return *res;         
    }  
}


// Solve:
std::complex<double> solver::solve(const ComplexVariable& cv)
{
    std::complex<double> zero = std::complex<double>(0,0);
        if(cv.m_a == zero && cv.m_b == zero && cv.m_c == zero)
    {
        throw runtime_error("Infinite Solutions!");
    }

    if(cv.m_a == zero) 
    {
        if(cv.m_b == zero) 
        {
            throw runtime_error("No Solution!");
        }
        return (-cv.m_c)/cv.m_b;
    }

    std::complex<double> delta = pow(cv.m_b,2) - 4.0*cv.m_a*cv.m_c;

    return ((-cv.m_b) + sqrt(delta)) / (2.0*cv.m_a);
}

