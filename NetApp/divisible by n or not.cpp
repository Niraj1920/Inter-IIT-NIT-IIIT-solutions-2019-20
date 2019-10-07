/*
Given a number represented in binary as a string( length <=100). Return 1 if divisible by 6 else return 0
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MOD 6 //checking divisibility by 6

int main()
{
    string binary;
    cin>>binary;
    int rem = 0;
    for(int i=0; i<binary.length(); i++){
        if(binary[i] == '1'){
            rem = (rem*2 + 1) % MOD;
        }
        else{
            rem = (rem*2) % MOD;
        }
    }
    //cout<<"rem = "<<rem<<endl;
    (rem == 0) ? cout<<"Yes! Divisible" : cout<<"Not Divisible";
    return 0;
}
