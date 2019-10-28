#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2)
{
	return (p1.first==p2.first)? p1.second<p2.second : p1.first<p2.first;
}


int activity_selection(vector<pair<int,int>> jobs, int n)
{
	sort(jobs.begin(),jobs.end(), comp);
	for(auto i:jobs)
		cout<<i.first<<" "<<i.second;
	int count=1,curr=0;
	for(int i=1;i<n;i++)
	{
		if(jobs[i].first>=jobs[curr].second)
		{
			curr=i;
			count++;
		}
	}
	return count;
}



int main()
{
	int n;
	cin>>n;
	vector<pair<int,int>> jobs(n);
	for(int i=0;i<n;i++)
	{
		cin>>jobs[i].first>>jobs[i].second;
	}
	cout<<activity_selection(jobs,n);
	return 0;
}