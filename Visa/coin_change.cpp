#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,c;
	cin>>n>>c;
	vector<int> coins;
	for(int i=0;i<c;i++)
	{
		int temp;
		cin>>temp;
		coins.push_back(temp);
	} 
	vector<int> dp(n+1,0);
	dp[0]=1;
	for(int i=0;i<c;i++)
	{
		for(int j=coins[i];j<=n;i++)
			dp[j]+=dp[j-coins[i]];
	}
	cout<<"\nno_way:"<<dp[n];
	return 0;
}