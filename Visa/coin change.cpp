/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued
coins. The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}
. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer
'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. 
The third line contains an integer 'N' denoting the cents.

Output:
Print number of possible ways to make change for N cents.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 ≤ A[i] ≤ 300

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5
*/
#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> ar, int n){
    int m = ar.size(), x, y;
    vector<vector<int>> dp(n+1, vector<int>(m, 0));
    for(int i=0; i<m; i++)  dp[0][i] = 1;
    
    for(int i=1; i<=n; i++){
        
        for(int j= 0; j<m; j++){
            if(i-ar[j] >= 0)    
                x = dp[i-ar[j]][j];
            else    
                x = 0;
            
            if(j >= 1)
                y = dp[i][j-1];
            else
                y = 0;
                
            dp[i][j] = x + y;
        }
    }
    return dp[n][m-1];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int m;
	    cin>>m;
	    vector<int> ar(m, 0);
	    for(int i=0; i<m; i++)  cin>>ar[i];
	    int n;
	    cin>>n;
	    cout<<coinChange(ar, n)<<endl;
	}
	return 0;
}
