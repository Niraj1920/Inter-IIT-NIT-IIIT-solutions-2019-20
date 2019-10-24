#include<bits/stdc++.h>
using namespace std;

int smallest(string s)
{
	int n=s.length();
	if(n<=1)
		return n;
	set<char> st;
	string T="";
	for(int i=0;i<n;i++)
	{
		if(st.find(s[i])==st.end())
		{
			st.insert(s[i]);
			T+=s[i];
		}
	}

	vector<int> v1(256,0);
	vector<int> v2(256,0);
	int m = T.length();
	for(int i=0;i<m;i++)
		v2[T[i]]++;
	int count=0,start=0,in=-1,len=n;

	for(int i=0;i<n;i++)
	{
		v1[s[i]]++;
		if(v2[s[i]]!=0 && v1[s[i]]<=v2[s[i]])
			count++;
		if(count==m)		
		{
			while(v1[s[start]]>v2[s[start]] || v2[s[start]]==0)
			{
				if(v1[s[start]] > v2[s[start]])
				{	v1[s[start]]--;
					start++;
				}
			}
			int l=i-start+1;
			if(l<len)
			{
				in=start;
				len=l;
			}
		}
	}
	return len;

}




int main()
{
	string s;
	cin>>s;

	cout<<smallest(s);

	return 0;
}