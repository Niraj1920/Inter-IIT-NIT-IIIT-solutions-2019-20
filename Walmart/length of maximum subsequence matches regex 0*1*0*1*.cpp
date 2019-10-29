#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string bin;
    cin>>bin;
    
    int n = bin.length();
    vector<vector<int>> dp(5, vector<int>(n+1, 0));
    vector<int> row{0, 1, 0, 1};
    
    for(int i=1; i<=4; i++){
        for(int j=1; j<=n; j++){
            if(row[i-1] == bin[j-1]-'0')
                dp[i][j] = max(dp[i][j-1]+1, dp[i-1][j]);
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    /*for(int i=0; i<=4; i++){
        for(int j=0; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[4][n]<<endl;
    return 0;
}
