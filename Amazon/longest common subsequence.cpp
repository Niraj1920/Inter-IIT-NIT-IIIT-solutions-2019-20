/*LONGEST COMMON SUB-SEQUENCE
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .
Output:
For each test case print the length of longest  common subsequence of the two strings .
Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100
Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC
Output:
3
2
*/
#include <iostream>
#include <vector>
using namespace std;

int lcs(string str1, string str2, int strlen1, int strlen2){
    vector<vector<int>> dp(strlen1+1, vector<int>(strlen2+1, 0));
    for(int i=0; i<=strlen1; i++){
        for(int j=0; j<=strlen2; j++){
            if(i == 0 || j == 0)    dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])   dp[i][j] = dp[i-1][j-1] + 1;
            else if(str1[i-1] != str2[j-1])   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[strlen1][strlen2];
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int strlen1, strlen2;
	    cin>>strlen1>>strlen2;
	    string str1, str2;
	    cin>>str1;
	    cin>>str2;
	    int res = lcs(str1, str2, strlen1, strlen2);
	    cout<<res<<endl;
	}
	return 0;
}
