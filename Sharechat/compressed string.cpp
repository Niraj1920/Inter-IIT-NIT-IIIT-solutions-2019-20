/*
Given a string of lowercase letters, output the compressed form of the string. Compressed form of a string 'aaabccdde' is : a3bc2d2e.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string compressedString(string str){
    int len = str.length();
    string res = "";
    res += str[0];
    int temp =1;
    for(int i=1; i<len; i++){
        
        //res += str[i];
        while(str[i-1] == str[i] && i<len){
            temp++;
            i++;
        }
        if(str[i-1] != str[i]){
            if(temp > 1)    res += to_string(temp);
            temp = 1;
            res += str[i];
        }
    }
    if(temp > 1)    res += to_string(temp);
    return res;
}

int main()
{
    string str;
    cin>>str;
    string res = compressedString(str);
    cout<<res;
    return 0;
}
