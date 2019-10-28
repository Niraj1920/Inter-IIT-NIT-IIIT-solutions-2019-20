#include<bits/stdc++.h>
using namespace std;



int main()
{
	char s[100];
	cin.getline(s,100);
	cout<<s;
	int MAX_size=INT_MIN;
	int i=0;
	string temp="",max_string;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			int curr_size=temp.size();
			if(curr_size%2==0 && curr_size > MAX_size)
			{
				max_string=temp;
				MAX_size=curr_size;
			}
			temp="";
		}
		else
		{
			temp+=s[i];
		}
		i++;
	}
	if(max_string.length()==0)
		cout<<"-1";
	else
		cout<<max_string;
	return 0;
}