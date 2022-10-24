//
// Created by pc on 10/6/2022.
//
#include <bits/stdc++.h>
using namespace std;
#ifndef UNTITLED39_BIGDECIMALINT_H
#define UNTITLED39_BIGDECIMALINT_H


class BigDecimalInt {
private:
    string decStr;
    bool op=true;
    int sze=0;
public:
public:
    BigDecimalInt();
    BigDecimalInt(string str);

    int size();

    int sign();


    BigDecimalInt(int n);


    bool operator< (BigDecimalInt anotherDec);

    bool operator> (BigDecimalInt anotherDec);

    friend ostream& operator<<(ostream& out,BigDecimalInt temp);

    BigDecimalInt operator- (BigDecimalInt anotherDec);


    BigDecimalInt operator+ (BigDecimalInt anotherDec);

    BigDecimalInt &operator= (BigDecimalInt &anotherDec);

    bool operator==(BigDecimalInt anotherDec);

};




#endif //UNTITLED39_BIGDECIMALINT_H
