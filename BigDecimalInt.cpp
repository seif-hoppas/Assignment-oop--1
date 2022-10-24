//
// Created by pc on 10/6/2022.
//

#include "BigDecimalInt.h"
#include <bits/stdc++.h>
using namespace std;

BigDecimalInt::BigDecimalInt(){}
BigDecimalInt::BigDecimalInt(string str){
    regex reg("^[+-]?[0-9]+$");//check if the input is valid
    if(regex_match(str,reg)){//if the input is valid
        if(str[0]=='-'){//if the input is negative
            op=false;//add the sign to op
            str.erase(0,1);//remove the sign
        }
        else if(str[0]=='+'){//if the input is positive
            op=true; //add the sign to op
            str.erase(0,1);//remove the sign
        }
        decStr=str;//add the input to decStr
    }
    else{//if the input is not valid
        cout<<"Invalid input"<<endl;
        exit(1);
    }
}
int BigDecimalInt::size(){
    cout << decStr.size() << endl;//print the size of the input
}
int BigDecimalInt::sign(){
    if(op){//if the input is positive
        return 1;
    }else{//if the input is negative
        return 0;
    }
}
BigDecimalInt::BigDecimalInt(int n):BigDecimalInt(to_string(n)){//convert the int to string and call the constructor

}
bool BigDecimalInt::operator< (BigDecimalInt anotherDec){
    if(decStr.size() < anotherDec.decStr.size()){//if the size of the first input is less than the size of the second input
        if(anotherDec.op){//if the second input is positive
            return true;
        }else{//if the second input is negative
            return false;
        }

    }else if(decStr.size() > anotherDec.decStr.size()){//if the size of the first input is greater than the size of the second input
        if(op){//if the first input is positive
            return false;
        }else{//if the first input is negative
            return true;
        }

    }
    if(op && anotherDec.op){//if both inputs are positive
        int i = 0 , j=0;
        while (i < decStr.size()    && j < anotherDec.decStr.size()) {//loop until the end of the inputs
            if (decStr[i] > anotherDec.decStr[j]){//if the first input is greater than the second input
                return false;
            }
            else if (decStr[i] < anotherDec.decStr[j]){//if the first input is less than the second input
                return true;
            }
            i++;
            j++;
        }

    }
    else if(!op && !anotherDec.op){//if both inputs are negative
        int i = 0 , j=0;
        while (i < decStr.size()    && j < anotherDec.decStr.size()) {//loop until the end of the inputs
            if (decStr[i] > anotherDec.decStr[j]){//if the first input is greater than the second input
                return true;
            }
            else if (decStr[i] < anotherDec.decStr[j]){//if the first input is less than the second input
                return false;
            }
            i++;
            j++;
        }

    }
    else if(op && !anotherDec.op){//if the first input is positive and the second input is negative
        return false;
    }
    else{//if the first input is negative and the second input is positive
        return true;

    }
}
bool BigDecimalInt::operator> (BigDecimalInt anotherDec){
    if(decStr.size() < anotherDec.decStr.size()){//if the size of the first input is less than the size of the second input
        if(anotherDec.op){//if the second input is positive
            return false;
        }else{
            return true;
        }

    }else if(decStr.size() > anotherDec.decStr.size()){//if the size of the first input is greater than the size of the second input
        if(op){//if the first input is positive
            return true;
        }else{
            return false;
        }

    }
    if(op && anotherDec.op){//if both inputs are positive
        int i = 0 , j=0;
        while (i < decStr.size()    && j < anotherDec.decStr.size()) {//loop until the end of the inputs
            if (decStr[i] > anotherDec.decStr[j]){//if the first input is greater than the second input
                return true;
            }
            else if (decStr[i] < anotherDec.decStr[j]){//if the first input is less than the second input
                return false;
            }
            i++;
            j++;
        }

    }
    else if(!op && !anotherDec.op){//if both inputs are negative
        int i = 0 , j=0;
        while (i < decStr.size()    && j < anotherDec.decStr.size()) {//loop until the end of the inputs
            if (decStr[i] > anotherDec.decStr[j]){//if the first input is greater than the second input
                return false;
            }
            else if (decStr[i] < anotherDec.decStr[j]){//if the first input is less than the second input
                return true;
            }
            i++;
            j++;
        }

    }
    else if(op && !anotherDec.op){//if the first input is positive and the second input is negative
        return true;
    }
    else{//if the first input is negative and the second input is positive
        return false;

    }
}
ostream& operator<<(ostream& out,BigDecimalInt temp) {//print the input
    if (!temp.op){//if the input is negative
        out << '-' << temp.decStr;//print the sign and the input
    }
    else//if the input is positive
        out << '+' << temp.decStr;

    return out;
}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){


    string str1=decStr,str2=anotherDec.decStr,str="";
    if(op && anotherDec.op || !op && !anotherDec.op){//if both inputs are positive or both inputs are negative
        if((anotherDec< *this) && !op && !anotherDec.op){//if the first input is less than the second input and both inputs are negative
            swap(str1,str2);//let the first string is the bigger one
        }
        else if( anotherDec>*this){//if the first input is greater than the second input
            swap(str1,str2);//let the first string is the bigger one
        }
        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;

        int carry = 0;

        for (int i = n2 - 1; i >= 0; i--) {

            int sub = ((str1[i + diff] - '0') - (str2[i] - '0')//subtract the second input from the first input
                       - carry);//subtract the carry from the subtraction
            if (sub < 0) {//if the subtraction is less than zero
                sub = sub + 10;
                carry = 1;
            }
            else
                carry = 0;

            str.push_back(sub + '0');
        }
        // Add remaining digits of str2[]
        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str1[i] == '0' && carry) {
                str.push_back('9');
                continue;
            }
            int sub = ((str1[i] - '0') - carry);
            if (i > 0 || sub > 0) // remove preceding 0's
                str.push_back(sub + '0');
            carry = 0;

        }

        reverse(str.begin(), str.end());
        BigDecimalInt obj(str);
        if((anotherDec< *this)){//if the first input is less than the second input
            obj.op= true;//make the sign of the output positive
        }else{
            //if the first input is greater than the second input
            obj.op=false;
            //make the sign of the output negative

        }
        return obj;

    }else{
        if (str1.length() > str2.length())
            swap(str1, str2);

        string str = "";

        int n1 = str1.length(), n2 = str2.length();

        reverse(str1.begin(), str1.end());//reverse the first string to make the subtraction easier
        reverse(str2.begin(), str2.end());//reverse the second string to make the subtraction easier

        int carry = 0;
        for (int i=0; i<n1; i++)//loop until the end of the first string to get the subtraction
        {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');

            carry = sum/10;
        }
        // Add remaining digits of str2[]

        for (int i=n1; i<n2; i++)//loop until the end of the second string to get the subtraction

        {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        // Add remaining carry
        if (carry)//if there is a carry
            str.push_back(carry+'0');//add the carry to the output

        // reverse resultant string
        reverse(str.begin(), str.end());
        BigDecimalInt obj(str);
        if((anotherDec< *this) ){//if the first input is less than the second input
            obj.op=true;//make the sign of the output positive
        }else{//if the first input is greater than the second input
            obj.op=false;//make the sign of the output negative

        }
        return obj;
    }


}
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec){
    string str1 = decStr, str2 = anotherDec.decStr,str="";
    if(op && anotherDec.op || !op && !anotherDec.op){//if both inputs are positive or both inputs are negative
        if (str1.length() > str2.length())//if the first input is greater than the second input
            swap(str1, str2);

        int n1 = str1.length(), n2 = str2.length();

        reverse(str1.begin(), str1.end());//reverse the first string to make the addition easier
        reverse(str2.begin(), str2.end());//reverse the second string to make the addition easier

        int carry = 0;
        for (int i=0; i<n1; i++)//loop until the end of the first string to get the addition
        {
            // Do school mathematics, compute sum of current digits and carry
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');

            carry = sum/10;
        }

        for (int i=n1; i<n2; i++)//loop until the end of the second string to get the addition
        {
            // Do school mathematics, compute sum of current digits and carry
            int sum = ((str2[i]-'0')+carry);//
            str.push_back(sum%10 + '0');
            carry = sum/10;//to get the carry
        }

        // Add remaining carry
        if (carry)
            str.push_back(carry+'0');

        // reverse resultant string
        reverse(str.begin(), str.end());
        BigDecimalInt obj(str);
        if(!anotherDec.op){//if the second input is negative
            obj.op=false;//make the sign of the output negative
        }else{//if the second input is positive
            obj.op=true;//make the sign of the output positive
        }
        return obj;


    }else{
        if(str1.size()<=str2.size()){
            swap(str1,str2);
        }
        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;

        int carry = 0;

        for (int i = n2 - 1; i >= 0; i--) {
            // Do school mathematics, compute difference of current digits and carry
            int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                       - carry);
            if (sub < 0) {
                sub = sub + 10;//go jump to the next digit
                carry = 1;
            }
            else
                carry = 0;//if there is no carry

            str.push_back(sub + '0');//add the subtraction to the output
        }

        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str1[i] == '0' && carry) {
                str.push_back('9');
                continue;
            }
            int sub = ((str1[i] - '0') - carry);//subtract the carry from the first input
            if (i > 0 || sub > 0) // remove preceding 0's
                str.push_back(sub + '0');
            carry = 0;

        }

        reverse(str.begin(), str.end());
        BigDecimalInt obj(str);
        //if the first input is greater than the second input and the size of the first input equals the size of the second input
        if((anotherDec< *this) && str1.size()==str2.size()){
            obj.op= false;
            //make the sign of the output negative

        }else if(!(anotherDec< *this)&& str1.size()==str2.size()){//if the first input is less than the second input and the size of the first input equals the size of the second input
            obj.op=true;
            //make the sign of the output positive

        }else{
            //if the first size of the first input is greater than the size of the second input and the first input is positive
            if(str1.size()>str2.size()&&op){
                //make the sign of the output positive
                obj.op=true;
            }

            else if(str1.size()>str2.size()&&!op){//if the first size of the first input is greater than the size of the second input and the first input is negative
                //make the sign of the output negative
                obj.op=false;
            }

            else if(str1.size()<str2.size()&&anotherDec.op){//if the first size of the first input is less than the size of the second input and the second input is positive
                //make the sign of the output postive
                obj.op=true;
            }
            //if the first size of the first input is less than the size of the second input and the second input is negative
            else{
                //make the sign of the output negative
                obj.op=false;
            }
        }
        return obj;

    }

}
bool BigDecimalInt::operator==(BigDecimalInt anotherDec){
    return (decStr==anotherDec.decStr);
}

