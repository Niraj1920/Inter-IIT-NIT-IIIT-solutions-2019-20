#include <iostream>
#include <bits/stdc++.h>
#include <string>
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
            if(isPalindrome(temp)){
                cout<<temp<<" "<<++count<<endl;
            } 
        }
    }
    cout<<count<<endl;
    return 0;
}
