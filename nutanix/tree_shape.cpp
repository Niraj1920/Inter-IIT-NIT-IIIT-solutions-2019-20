#include<bits/stdc++.h>
using namespace std;

bool check(string s, string t)
{
	for(int i=s.size();--i)
	{
		string tir(t.substr(0,i));
		reverse(tir.begin(),tir.end());
		if(s.substr(0,i) == tir && s.substr(i)==t.substr(i))
			return true;
	}
	return false;
}

int main()
{
	string s,t;
	cin>>s>>t;
	string sr(s);
	string tr(t);
	reverse(sr.begin(),sr.end());
	reverse(tr.begin(),tr.end());
	if(s==t)
	{
		cout<<"/";
		return 0;
	}
	if(s==tr)
	{
		cout<<"\\";
		return 0;
	}
	if(check(s,t)) 
	{
		cout<<"<";
		return 0;
	}
	if(check(sr,t))
	{
		return ">";
		return 0;
	}
	if(check(sr,tr))
	{
		return "^";
		return 0;
	}
	cout<<"#";
	return 0;
}
