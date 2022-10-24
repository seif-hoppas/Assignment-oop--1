#include "bits/stdc++.h"
using namespace std;

void punc()
{
    string sentence = "";// declaring empty string to store input
    char ch;
    bool flag = true;
    while (flag) 
    {
        ch = getchar();// getchar to prompt the user to enter input
        if(ch == '\n'){sentence+=' ';}// if its a break line store it as space
        else if(ch == '.'){flag = false;sentence+='.';}// if its '.' end the input
        else {sentence+=ch;}
    }
    string empty = "";// declaring empty string to store the final sentence
    for(int i=0; i<sentence.size(); i++) 
    {
        if(i == 0){empty += toupper(sentence[i]);}// output the first charcater upper case
        else if(sentence[i] == ' ')
        {
            while(sentence[i] == ' ')// removing extra spaces
            {
                i++;
                continue;
            }
            empty += ' ';
            i--;
        }else
        {
            empty += tolower(sentence[i]);// output the sentence in lowercase
        }
    }
    cout << empty << endl;
}

int main()
{
    punc();
    return 0;
}
// the    Answer to life, the    Universe, and everything IS 42.