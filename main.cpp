#include "calculator.h"

using namespace std;
int main()
{
    string s;
    cin>>s;
    calculator a;
    try
    {
        a.calculate(s);
    }
    catch (char c)
    {
        cout<<"встретился недопустимый символ "<<c;
    }
    catch (const char *source)
    {
        cout<<source;
    }
   /* for (int i=0;i<a.size();i++)
        if (a[i].get_value()==10000001)
            cout<<a[i].get_sign()<<" ";
        else
            cout<<a[i].get_value()<<" ";
    cout<<"\n";
    for (int i=0;i<res.size();i++)
        if (res[i].get_value()==10000001)
            cout<<res[i].get_sign()<<" ";
        else
            cout<<res[i].get_value()<<" ";*/
}
