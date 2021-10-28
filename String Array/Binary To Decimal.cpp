#include <iostream>
#include <string>
using namespace std;
 
// Function to convert binary to decimal
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

string viceVersa(){
  int n = 100;
 string s1="";
 while(n) {
 	s1 += (n%2) + '0';
    n /= 2;
 }
    reverse(s1.begin(),s1.end());
    }