#include "solver.hpp"
#include <stdexcept>
#include <cmath>
using namespace solver;

/*
    RealVariable Class implemention:
*/

// Operator *:
RealVariable& RealVariable::operator * (double coe) const
{
    RealVariable * res = new RealVariable(coe*m_a,coe*m_b,coe*m_c);
    return *res;
}

RealVariable& RealVariable::operator * (const RealVariable& other) const
{
    // Handle the power > 2
    if(m_a * other.m_a != 0 || (m_a * other.m_b + m_b * other.m_a) != 0)
    {
        throw runtime_error("Power cannot be greater then 2!");
    }
    double a = m_a*other.m_c + m_b*other.m_b + m_c * other.m_a;
    double b = m_b * other.m_c + m_c * other.m_b;
    double c = m_c * other.m_c;

    RealVariable * res = new RealVariable(a,b,c);
    return *res;
}


RealVariable& solver::operator * (double coe, const RealVariable& other) //friend
{
    RealVariable * res = new RealVariable(coe*other.m_a,coe*other.m_b,coe*other.m_c);
    return *res;
}

// Operator +:
RealVariable& RealVariable::operator + (double coe)
{
    RealVariable * res = new RealVariable(m_a,m_b,coe+m_c);
    return *res;
}

RealVariable& RealVariable::operator + (const RealVariable& other)
{
    RealVariable * res = new RealVariable(m_a+other.m_a,m_b+other.m_b,m_c+other.m_c);
    return *res;
}

RealVariable& solver::operator + (double coe, const RealVariable& other)
{
    RealVariable * res = new RealVariable(other.m_a,other.m_b,coe+other.m_c);
    return *res;
}

// Operator ==:
RealVariable& RealVariable::operator == (double coe) const
{
    RealVariable * res = new RealVariable(m_a,m_b,m_c-coe);
    return *res;
}

RealVariable& RealVariable::operator == (const RealVariable& other) const
{
    RealVariable * res = new RealVariable(m_a-other.m_a,m_b-other.m_b,m_c-other.m_c);
    return *res;
}


RealVariable& solver::operator == (double coe, const RealVariable& other)
{
    RealVariable * res = new RealVariable(other.m_a,other.m_b,other.m_c-coe);
    return *res;
}

// Operator -:
RealVariable& RealVariable::operator - (double coe)
{
    RealVariable * res = new RealVariable(m_a,m_b,m_c-coe);
    return *res;
}

RealVariable& RealVariable::operator - (const RealVariable& other)
{
    RealVariable * res = new RealVariable(m_a-other.m_a,m_b-other.m_b,m_c-other.m_c);
    return *res;
}

RealVariable& solver::operator - (double coe, const RealVariable& other)
{
    RealVariable * res = new RealVariable(-other.m_a,-other.m_b,coe-other.m_c);
    return *res;
}

// Operator /:
RealVariable& RealVariable::operator / (double coe)
{
    if(coe == 0)
    {
        throw runtime_error("Cannot divide by 0!");
    }

    RealVariable * res = new RealVariable(m_a/coe,m_b/coe,m_c/coe);
    return *res;   
}

RealVariable& solver::operator / (double coe, const RealVariable& other)
{
    if(other.m_a == 0 || other.m_b == 0 || other.m_c == 0)
    {
        throw runtime_error("Cannot divide by 0!");
    }

    RealVariable * res = new RealVariable(coe/other.m_a,coe/other.m_b,coe/other.m_c);
    return *res;   
}

// Operator ^:
RealVariable& RealVariable::operator ^ (int pow)
{
    RealVariable * res;
    if(pow < 0 || pow > 2 || (m_a != 0 && pow > 1))
    {
        throw runtime_error("Power cannot be greater then 2 or less then 0!");
    }

    if(pow == 0)
    {
        res = new RealVariable(0,0,1);
        return *res;   
    }
    else if(pow == 1)
    {
        res = new RealVariable(m_a,m_b,m_c);
        return *res;         
    }
    else
    {
        RealVariable x(m_a,m_b,m_c);
        RealVariable y(m_a,m_b,m_c);
        res = &(x*y);
        return *res;         
    }  
}

// Solve:
double solver::solve(const RealVariable& rv)
{
    if(rv.m_a == 0 && rv.m_b == 0 && rv.m_c == 0)
    {
        throw runtime_error("Infinite Solutions!");
    }

    if(rv.m_a == 0) 
    {
        if(rv.m_b == 0) 
        {
            throw runtime_error("No Solution!");
        }
        return (-rv.m_c)/rv.m_b;
    }

    double delta = pow(rv.m_b,2) - 4*rv.m_a*rv.m_c;

    if(delta < 0) 
    {
        throw runtime_error("No Solution!");
    }

    return ((-rv.m_b) + sqrt(delta)) / (2*rv.m_a);
    
}
