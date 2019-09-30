/*
Given d dice each with f faces, numbered from 1 to f, find the number of ways to get sum s.
s is the summation of values on each face when all the dice are thrown.
*/
//Alter method can be using bactracking
//Solution using dp..
#include <iostream>
#include <vector>
using namespace std;
int findWays(int d, int f, int s) {
    vector<vector<int>> dp(d+1, vector<int>(s+1, 0));
    for(int i=1; i<=f && i<=s; i++){
        dp[1][i] = 1;
    }
    for(int i=2; i<=d; i++){
        for(int j=1; j<=s; j++){
            for(int k=1; k<=f && k<j; k++){
                dp[i][j] += dp[i-1][j-k];
            }
        }
    }
    for(int i=0; i<=d; i++){
        for(int j=0; j<=s; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    return dp[d][s];
}

int main()
{
    int d, f, s;
    cin>>d>>f>>s;
    
   int ways = findWays(d, f, s);
   cout<<ways;
   
    return 0;
}
