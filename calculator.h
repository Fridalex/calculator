#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stack>
#include <math.h>
#include <iomanip>
#ifndef CALCULATOR_H
#define CALCULATOR_H

using namespace std;

class operands
{
    double value;
    char sign;

public:
    operands(double a)
    {
        value=a;
    }
    operands(char a)
    {
        value=10000001;
        sign= a;
    }
    operands(int a)
    {
        value=a;
    }
    operands()
    {}
    void put_value(double a)
    {
        value=a;
    }
    void put_sign(char a)
    {
        value=10000001;
        sign=a;
    }
    double get_value()
    {
        return value;
    }
    char get_sign()
    {
        return sign;
    }
};
class calculator
{
    vector<operands> a;
    vector<operands> res;
public:
    vector<operands> parser(const string s);
    vector<operands> poliz(vector<operands> a);
    double executer(vector<operands> a);
    void calculate(string s);

};
#endif // CALCULATOR_H
