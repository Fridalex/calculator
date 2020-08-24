#include <calculator.h>
#include <gtest/gtest.h>

TEST (test001,test_parser)
{
    calculator test;
    string s="1*3+6/7.21-((2-123)*7.23)";
    vector<operands> expected,res=test.parser(s);
    expected.push_back(1.00);
    expected.push_back('*');
    expected.push_back(3.00);
    expected.push_back('+');
    expected.push_back(6.00);
    expected.push_back('/');
    expected.push_back(7.21);
    expected.push_back('-');
    expected.push_back('(');
    expected.push_back('(');
    expected.push_back(2.00);
    expected.push_back('-');
    expected.push_back(123.00);
    expected.push_back(')');
    expected.push_back('*');
    expected.push_back(7.23);
    expected.push_back(')');
    for (int i=0;i<16;i++)
        if (res[i].get_value()==10000001)
            ASSERT_EQ(res[i].get_sign(),expected[i].get_sign());
        else
            ASSERT_EQ(res[i].get_value(),expected[i].get_value());
}
TEST (test002,test_poliz)
{
    calculator test;
    vector<operands> a;
    a.push_back(1.00);
    a.push_back('*');
    a.push_back(3.00);
    a.push_back('+');
    a.push_back(6.00);
    a.push_back('/');
    a.push_back(7.21);
    a.push_back('-');
    a.push_back('(');
    a.push_back('(');
    a.push_back(2.00);
    a.push_back('-');
    a.push_back(123.00);
    a.push_back(')');
    a.push_back('*');
    a.push_back(7.23);
    a.push_back(')');
    vector<operands> expected,res=test.poliz(a);
    expected.push_back(1.00);
    expected.push_back(3.00);
    expected.push_back('*');
    expected.push_back(6.00);
    expected.push_back(7.21);
    expected.push_back('/');
    expected.push_back('+');
    expected.push_back(2.00);
    expected.push_back(123.00);
    expected.push_back('-');
    expected.push_back(7.23);
    expected.push_back('*');
    expected.push_back('-');
    for (int i=0;i<13;i++)
        if (res[i].get_value()==10000001)
            ASSERT_EQ(res[i].get_sign(),expected[i].get_sign());
        else
            ASSERT_EQ(res[i].get_value(),expected[i].get_value());
}
TEST (test003,test_executer)
{
    calculator test;
    vector<operands> a;
    a.push_back(1.00);
    a.push_back(3.00);
    a.push_back('*');
    a.push_back(6.00);
    a.push_back(7.21);
    a.push_back('/');
    a.push_back('+');
    a.push_back(2.00);
    a.push_back(123.00);
    a.push_back('-');
    a.push_back(7.23);
    a.push_back('*');
    a.push_back('-');
    double expected=878.66,res=test.executer(a);
    ASSERT_EQ(res,expected);
}
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

