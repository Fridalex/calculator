#include "calculator.h"
vector<operands> calculator::parser(const string s)
{
    int unminus=0;
    int i=0;
    while (i<s.length())
    {
        switch (s[i])
        {
            case ')':
            case '+':
            case '/':
            case '*':
            case '(':
            {
                if (s[i]!='(')
                    unminus=1;
                else
                    unminus=0;
                char c=s[i];
                operands buf(c);
                a.push_back(buf);
                i++;
                break;
            }
            case '-':
            {
                if (unminus==0)
                {
                    char c='U';
                    unminus=1;
                    operands buf(c);
                    a.push_back(buf);
                    i++;
                    break;
                }
                else
                {
                    char c='-';
                    operands buf(c);
                    a.push_back(buf);
                    i++;
                    break;
                }
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                unminus=1;
                char c[11];
                for (int j=0;j<11;j++)
                    c[j]='\0';
                int q=0;
                while (s[i]>='0' && s[i]<='9')
                {
                    c[q]=s[i];
                    q++;
                    i++;
                }
                if (s[i]=='.' || s[i]==',')
                {
                    c[q]='.';
                    q++;
                    i++;
                    while (s[i]>='0' && s[i]<='9')
                    {
                        c[q]=s[i];
                        q++;
                        i++;
                    }
                    double number;
                    number=atof(c);
                    operands buf(number);
                    a.push_back(buf);
                }
                else
                {
                    double number;
                    number=atof(c);
                    operands buf(number);
                    a.push_back(buf);
                }
                break;

            }
            case ' ':
            {
                i++;
                break;
            }
            default:
               throw s[i];
        }
    }
    return a;
}
vector<operands> calculator::poliz(vector<operands> a)
{
    stack<operands> help;
    for (int i=0;i<a.size();i++)
    {
        if (a[i].get_value()!=10000001)
            res.push_back(a[i]);
        else
        {
            switch (a[i].get_sign())
            {
                case '(':
                {
                    help.push(a[i]);
                    break;
                }
                case ')':
                {
                    operands buf;
                    buf=help.top();
                    while (!help.empty())
                    {
                        if (buf.get_sign()!='(')
                        {
                            res.push_back(buf);
                            help.pop();
                            if (help.empty())
                                throw "неправильно расставлены скобки";
                            buf=help.top();
                        }
                        else
                        {
                            help.pop();
                            break;
                        }
                    }
                    break;
                }
                case '-':
                case '+':
                {
                    while (!help.empty() )
                    {
                        operands buf=help.top();
                        if (buf.get_sign()=='(')
                            break;
                        else
                            res.push_back(buf);
                        help.pop();
                    }
                    help.push(a[i]);
                    break;
                }
                case '*':
                case '/':
                {
                    while (!help.empty() )
                    {
                        operands buf=help.top();
                        if (buf.get_sign()=='(')
                            break;
                        else
                        if (buf.get_sign()=='/' || buf.get_sign()=='*' || buf.get_sign()=='U')
                            res.push_back(buf);
                        else
                            break;
                        help.pop();
                    }
                    help.push(a[i]);
                    break;
                }
                case 'U':
                {
                    while (!help.empty() )
                    {
                        operands buf=help.top();
                        if (buf.get_sign()=='(')
                            break;
                        else
                        if (buf.get_sign()=='U')
                            res.push_back(buf);
                        else
                            break;
                        help.pop();
                    }
                    help.push(a[i]);
                    break;
                }
            }
        }

    }
    while (!help.empty())
    {
        operands buf=help.top();
        if (buf.get_sign()=='(')
            throw "Неправильно расставлены скобки";
        else
            res.push_back(buf);
        help.pop();
    }
    return res;
}
double calculator::executer(vector<operands> a)
{
    stack<double> help;
    for (int i=0;i<a.size();i++)
    {
        if (a[i].get_value()!=10000001)
            help.push(a[i].get_value());
        else
        {
            double c,b;
            if (help.empty())
                throw "неправильно расставлены знаки";
            c=help.top();
            help.pop();
            if (a[i].get_sign()!='U')
            {
                if (help.empty())
                    throw "неправильно расставлены знаки";
                b=help.top();
                help.pop();
            }
            switch (a[i].get_sign())
            {
                case '+':
                {
                    c=c+b;
                    help.push(c);
                    break;
                }
                case '-':
                {
                    b=b-c;
                    help.push(b);
                    break;
                }
                case '*':
                {
                    c=c*b;
                    help.push(c);
                    break;
                }
                case '/':
                {
                    if (c!=0)
                        b=b/c;
                    else
                        throw "деление на 0 невозможно";
                    help.push(b);
                    break;
                }
                case 'U':
                {
                    c=-c;
                    help.push(c);
                    break;
                }
            }
        }

    }
    double res=help.top();
    if (res>0)
    {
         res=round(res*100)/100;
         cout << fixed << setprecision(2)<< res << endl;
         return res;
    }
    else
    {
        res=- round(-res*100)/100;
        cout<< fixed << setprecision(2)<< - round(-res*100)/100 << endl;
        return res;
    }
}
void calculator::calculate(string s)
{
    parser(s);
    poliz(a);
    executer(res);
}
