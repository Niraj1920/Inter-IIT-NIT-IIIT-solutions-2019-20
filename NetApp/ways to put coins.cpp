/*
Given infinite coins, and 3 pockets, we have to put the coins in 3 pockets, such that the sum of all coins is in the range [X,Y] inclusive. Find number of ways to put the coins. Input will be range X,Y
Input: [4,5]      [X=4, Y=5]
Output: 9  (3+6)
total coins = 4. Number of ways = 3
	{1,1,2} {1,2,1} {2,1,1}
total coins = 5. No of ways = 6
	{1,1,3} {1,3,1} {3,1,1} {1,2,2} {2,1,2} {2,2,1}

*/

//try to solve for k pockets.....
#include <iostream>
#include <bits/stdc++>
using namespace std;

int main()
{
    int x, y;
    cin>>x>>y;
    for(int i=x; i<=y; i++){
        ways += (i-1)*)(i-2)/2;
    }
    cout<<ways;
    return 0;
}
