/*
Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an nteger n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the sum.

Output:
Count all the subsets of given array with sum equal to given sum.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5

Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10

Output:
3
3
*/
#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, sum;
	    cin>>n;
	    int ar[n];
	    for(int i=0; i<n; i++){
	        cin>>ar[i];
	    }
	    cin>>sum;
	    int dp[n+1][sum+1];
        for(int i=0; i<=n; i++)  dp[i][0] = 1;
        for(int j=1; j<=sum; j++)  dp[0][j] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(j < ar[i-1] ) dp[i][j] = dp[i-1][j];
                else    dp[i][j] = dp[i-1][j] + dp[i-1][j-ar[i-1]];
            }
        }
        
        /*for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }*/
        cout<< dp[n][sum]<<endl;
	}
	return 0;
}
