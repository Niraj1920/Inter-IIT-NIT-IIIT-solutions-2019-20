/*
Given an array of size N  and Q queries, where each query consists of two integers L and R and K, return the K-step sum within the range L
and R. For example for the array [1, 2, 3, 4, 5, 6, 7], if a query is L=2, R=6 and K=2, then the numbers 1, 3, 5, 7 are a part of the
2 step sequence and among these, only 3 and 5 lie within the range(array indexing starting from 1). So the required sum = 8.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int k_stepSum(vector<int> ar, int l, int r, int k){
    int i = l, sum = 0;
    while(i % k != 1){
        i++;
    }
    for(i; i<=r; i=i+k){
        sum += ar[i];
    }
    return sum;
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
        int l, r, k;
        cin>>l>>r>>k;
        int res = k_stepSum(ar, l, r, k);
        cout<<res<<endl;
    }
}
