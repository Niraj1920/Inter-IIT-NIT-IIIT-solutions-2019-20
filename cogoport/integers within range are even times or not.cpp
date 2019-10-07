/*
 Given an array of size N  and Q queries, where each query consists of two integers L and R, representing left and right indices in the 
array, tell whether all the integers present within these two ranges are present even number of times or not. Brute force will not work
here. For each prefix if we store XOR , then by checking if prefix XOR is 0 or not gives the answer. But what if array contain 0??.
Hi there, for the case of zero you can make a similar prefix array of number of zeroes then counting the number of zeroes in a range
is trivial.

//***Fails here************-> The solution with xor is incorrect as it is possible for 3 numbers to have xor = 0 e.g. 1^2^3 = 0.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int isEvenCount(vector<int> ar, int l, int r){
    vector<int> xor_ar(ar.size(), 0), zero_ar(ar.size(), 0);
    xor_ar[1] = ar[1];
    (ar[1] == 0) ? zero_ar[1] = 1 : zero_ar[1] = 0;
    for(int i=2; i<ar.size(); i++){
        xor_ar[i] = xor_ar[i-1] ^ ar[i];
        (ar[i] == 0) ? zero_ar[i] = zero_ar[i-1]+1 : zero_ar[i] = zero_ar[i-1];
    }
    /*for(int i=0; i<ar.size(); i++){
        cout<<xor_ar[i]<<" ";
    }cout<<endl;
    for(int i=0; i<ar.size(); i++){
        cout<<zero_ar[i]<<" ";
    }cout<<endl;*/
    
    if(l == 1){
        if(zero_ar[r] % 2 == 0 && xor_ar[r] == 0)
            return 1;
    }
    else{
        if(zero_ar[r] - zero_ar[l-1] % 2 == 0 && xor_ar[r] ^ xor_ar[l-1] == 0)
            return 1;
    }
    return 0;
}
int main()
{
    int n, q;
    cin>>n;
    vector<int> ar(n+1, 0);
    for(int i=1; i<=n; i++){
        cin>>ar[i];
    }
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        int res = isEvenCount(ar, l, r);
        cout<<res<<endl;
    }
}
