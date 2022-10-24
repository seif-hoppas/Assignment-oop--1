#include <bits/stdc++.h>
#include "BigDecimalInt.h"

using namespace std;
void test1()
{
    BigDecimalInt num1("-1134");
    BigDecimalInt num2("6561");
    BigDecimalInt num100 = num1 + num2;


    BigDecimalInt num3("56465464");
    BigDecimalInt num4("-6546546");
    BigDecimalInt num101 = num3 + num4;

    BigDecimalInt num5("321321");
    BigDecimalInt num6("987645");
    BigDecimalInt num102 = num5 + num6;

    BigDecimalInt num7("-2163321");
    BigDecimalInt num8("-5454541");
    BigDecimalInt num103 = num7 + num8;

    cout << num100 << endl; // 5427
    cout << num101 << endl; //49918918
    cout << num102 << endl; //1308966
    cout << num103 << endl; // -7617862
}
void test2()
{
    BigDecimalInt num1("-1941");
    BigDecimalInt num2("-9431");
    BigDecimalInt num100 = num1 - num2;


    BigDecimalInt num3("2171");
    BigDecimalInt num4("3691");
    BigDecimalInt num101 = num3 - num4;

    BigDecimalInt num5("-4");
    BigDecimalInt num6("3");
    BigDecimalInt num102 = num5 - num6;

    BigDecimalInt num7("1664546");
    BigDecimalInt num8("-3213212");
    BigDecimalInt num103 = num7 - num8;

    cout << num100 << endl; // 7490
    cout << num101 << endl; // -1520
    cout << num102 << endl; // -7
    cout << num103 << endl; // 4877758
}
void test3()
{
    BigDecimalInt n1("321321");
    BigDecimalInt n2("321");
    cout << (n1 > n2) << endl; // 1

    BigDecimalInt n3("123456");
    BigDecimalInt n4("923456");
    cout << (n3 > n4) << endl; // 0

    BigDecimalInt n5("-10000");
    BigDecimalInt n6("-1");
    cout << (n5 > n6) << endl; // 0
}


int main(){
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("-600");
    BigDecimalInt num3(10);
    BigDecimalInt num5 = num3 + num1;
    BigDecimalInt num6("123456789012345678901234567890");
    BigDecimalInt num7("+113456789011345678901134567890");
    BigDecimalInt num8("-200000000000000000000000000000");
//    BigDecimalInt num4 = num6 + num1;
//    BigDecimalInt num0 = num7 - num1;
//    cout << "num4 = " << num4 << endl;
//    cout << "num0 = " << num0 << endl;
    //
    test1();
    test2();
    test3();


}
