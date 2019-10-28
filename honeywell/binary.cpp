#include<bits/stdc++.h>
using namespace std;

void pos_of_1(int n)
{
	stack<int> s;
	while(n>0)
	{
		if(n&1)
		{
			s.push(1);
		}
		else
			s.push(0);
		n=n>>1;
	}
	int count=1;
	while(!s.empty())
	{
		if(s.top()==1)
			cout<<count<<" ";
		count++;
		s.pop();
	}
}


int main()
{
	int n;
	cin>>n;
	pos_of_1(n);
	return 0;
}
