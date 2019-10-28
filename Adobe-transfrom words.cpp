#include<bits/stdc++.h>
using namespace std;
int findcost(string s,string tmp,map<string,vector<string>> hash)
{
	int count=0,minm=INT_MAX;
	for(int j=0;j<hash[tmp].size();j++)
	{
		count=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]!=hash[tmp][j][i])
				count++;
		}
		minm=min(count,minm);
	}
	return minm;
}
int main()
{
	string s;
	cin>>s;
	int n;
	cin>>n;
	vector<string> dict(n);
	for(int i=0;i<n;i++)
		cin>>dict[i];
	map<string,vector<string>> hash;
	for(int i=0;i<n;i++)
	{
		string tmp=dict[i];
		sort(tmp.begin(),tmp.end());
		hash[tmp].push_back(dict[i]);
	}
	int l=s.length();

	vector<int> dp(l+1,INT_MAX);
		dp[0]=1;
	for(int i=1;i<=l;i++)
	{
		string temp=s.substr(0,i);
		string tmp=temp;
		sort(tmp.begin(),tmp.end());
		if(hash.find(tmp)!=hash.end())
			dp[i] = findcost(temp,tmp,hash);
		for(int j=1;j<i;j++)
		{
			if(dp[j]!=INT_MAX)
			{
				string temp=s.substr(j,i-j);
				string tmp=temp;
				sort(tmp.begin(),tmp.end());
				if(hash.find(tmp)!=hash.end())
					dp[i]=min(dp[i],dp[j]+findcost(temp,tmp,hash));
			}
		}
	}
	// for(int i=0;i<=l;i++)
	// 	cout<<dp[i]<<" ";
	if(dp[l]!=INT_MAX)
		cout<<dp[l]<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
