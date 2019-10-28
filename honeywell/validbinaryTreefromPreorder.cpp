#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> pre,int n)
{
	stack<int> s;
	int root=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(pre[i]<root)
			return false;
		while(!s.empty() && s.top()<pre[i])
		{
			root=s.top();
			s.pop();
		}
		s.push(pre[i]);
	}
	return true;
}


int main()
{
	int n;
	cin>>n;
	vector<int> pre(n);
	for(int i=0;i<n;i++)
		cin>>pre[i];
	if(check(pre,n))
		cout<<"true";
	else
		cout<<"false";
}
