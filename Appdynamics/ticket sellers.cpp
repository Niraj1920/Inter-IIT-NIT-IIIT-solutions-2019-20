/*
There are N ticket sellers each of whom has a certain amount of tickets. The price of a ticket is the number of tickets remaining with the ticket seller. They can sell a total of K tickets. Find the maximum amount they can earn by selling K tickets.

Input:
The first line of the input consists of a single integer T denoting the number of test cases. Each of the test case consists of two lines. First line of each test case consists of two integers N and K. The next line contains space separated N integers A[0], A[1], …, A[N-1] where A[i] denotes the number of ticket with ith ticket seller.

Output:
For each test case, print in a new line, the maximum amount they can earn by selling K tickets. Print your answer modulo 109 + 7​

Constraints:
1 <= T <= 103
1 <= N <= 105
1 <= Ai, K <= 106

Example:
Input:
2
5 3
4 3 6 2 4
6 2
5 3 5 2 4 4
Output:
15
10
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;  //test cases
	cin>>t;
	while(t--){
	    int s, c;   //seller    customer
	    cin>>s>>c;
	    vector<int> tc(s, 0);  //ticket count
	    map<int , int, greater<int>> m;
	    for(int i=0; i<s; i++){
	        cin>>tc[i];
	        m[tc[i]] += 1;
	    }
	    auto it = m.begin();
	    int cost = 0;
	    for(it; it != m.end(); it++){
	        while(c > 0 && it->second>0){
	            cost += it->first;
	            //cout<<cost<<" ";
	            it->second--;
	            m[it->first-1] += 1;
	            c--;
	        }
	    }
	    cout<<cost<<endl;
	}
	return 0;
}
