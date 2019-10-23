/*
Write a method to replace all the spaces in a string S with ‘%20’. You may assume that the string has sufficient space (or allocated memory) at the end to hold the additional characters,

Note: The leading and trailing spaces should be trimmed off and not replaced by %20.

Input:
The first line of input contains an integer T denoting the number of test cases. The T test cases follow. Each test case contains two lines of input. The first line contains a string S. The next line contains an integer K that denotes the length of the S with whitespace included.

Output:
For each testcase, in a new line, print the string with spaces replaced by "%20".

Constraints:
1 <= T <= 1000
1 <= |S|+ K <= 1000

Example:
Input:
2
Mr John Smith
13
Mr Benedict Cumberbatch  
25

Output:
"Mr%20John%20Smith"
"Mr%20Benedict%20Cumberbatch
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	char ch[10];
	while(t--){
    	cin.getline(ch,10);
    	
    	char s[1000];
    	cin.getline(s,1000);
    	
    	int k;
    	cin>>k;
    	
    	int count = 0;
    	for(int i=0; i<k; i++){
    	    if(s[i] == ' ') count++;
    	}
    	
    	int j = k - count - 1 + 3*count, i = k - 1;
    	s[j+1] = '\0';
    	while(i >= 0){
    	    while(s[i] != ' '){
    	        s[j] = s[i];
    	        i--;
    	        j--;
    	    }
    	    s[j--] = '0';
    	    s[j--] = '2';
    	    s[j--] = '%';
    	    i--;
    	}
    	cout<<s<<endl;
	}
	return 0;
}
