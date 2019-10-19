/*
4. Given 3 arrays f1, f2, candies. f1[i] and f2[i] are friends who love to eat candies[i]. Thus there will be groups of friends who love
a particular candy. (Same person can like multiple candies). Find the largest friend group who like the same candy and return the 
maximum
of f1*f2 among all such groups, f1 and f2 are friends who like same candy.

Sol - Construct m graphs if there are m candies. Each graph has n friends. Find the largest connected component(s) in all graphs. 
Let us say there are 3 such components of length 6. Return max(f1*f2) among all 3 groups.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> f1(n), f2(n), candy(n);
	for(int i=0;i<n;i++)
		cin>>f1[i];
	for(int i=0;i<n;i++)
		cin>>f2[i];
	for(int i=0;i<n;i++)
		cin>>candy[i];

	map<int,set<int>> group;
	for(int i=0;i<n;i++)
	{
		group[candy[i]].insert(f1[i]);
		group[candy[i]].insert(f2[i]);
	}
	set<pair<int,int> > mul;
	int x=0;
	for(auto it=group.begin();it!=group.end();++it)
	{
		int c=0,prod=1;;
		for(auto itr=it->second.rbegin();itr!=it->second.rend();--itr)
		{
			prod*=(*itr);
			c++;
			if(c==2)
				break;
		}
		mul.insert({(it->second).size(),prod});
		int s=(it->second).size();
		x=max(x,s);
	}
	int ans=0;
	auto it=mul.rbegin();
	// for(auto it =mul.end();it!=mul.begin();--it)
	// {
	// 	if((*it).first==x)
	// 		ans=maxm(ans,(*it).second);
	// }
	cout<<(*it).second<<endl;
	return 0;
}
