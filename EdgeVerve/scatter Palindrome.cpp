#include <iostream>
#include <bits/stdc++.h>
#include <string>
//this is for all possible su
using namespace std;
bool isPalindrome(string temp){
    int i=0, j=temp.length()-1;
    while(i<=j){
        if(temp[i] != temp[j])  return false;
        else{
            i++; j--;
        }
    }
    return true;
}
//this is for scatter palindrome
bool canbePalindrome(string temp){
    int a[26] = {0};
    for(int i=0; i<temp.length(); i++){
        //cout<<temp[i]-97<<" ";
        a[temp[i]-97]++;
    }
    //cout<<endl;
    int count = 0;
    for(int i=0; i<26; i++){
        //cout<<a[i]<<" ";
        if(a[i]%2 == 1) count++;
    }//cout<<endl;
    if(count > 1)   return false;
    return true;
}
int main()
{
    //brute force method...
    int count = 0;
    string s, t = "";
    cin>>s;
    for(int i=0; i<s.length(); i++){
        for(int j=1; j<=s.length()-i; j++){
            string temp = s.substr(i, j);
            //cout<<temp<<endl;
            if(iscanbePalindrome(temp)){
                count++;
                //cout<<temp<<" "<<++count<<endl;
            } 
        }
    }
    cout<<count<<endl;
    return 0;
}
