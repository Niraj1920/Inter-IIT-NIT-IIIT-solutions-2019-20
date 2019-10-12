/////////

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int f[n];
    for(int i=0; i<n; i++){
        cin>>f[i];
    }
    int left, right, jumps[n] = {0};
    for(int i=0; i<n; i++){
        left = max(i - f[i], 0);
        right = min(i + f[i] +1, n);
        jumps[left] = max(jumps[left], right);
        cout<<jumps[left]<<" ";
    }cout<<endl;
    
    
    int next_right = 0, taps = 1;
    right = jumps[0];
    for(int i=0; i<n; i++){
        next_right = max(next_right, jumps[i]);
        if(i == right){
            taps++;
            right = next_right;
        }
        
    }
    cout<<taps<<endl;
    return 0;
}
