/*
Given a string s and an array roll where roll[i] represents rolling first roll[i] characters in string. 
We need to apply every roll[i] on string and output final string. 
Rolling means increasing ASCII value of character, like rolling ‘z’ would result in ‘a’, rolling ‘b’ would result in ‘c’, etc.
*/

#include<bits/stdc++.h>
using namespace std;

char rol(char c,int n)
{
	n=n%26;
	int pos=c-'a';
	char res='a' + (pos+n)%26;
	return res;
}

string rollstring(vector<int> roll,string s)
{
	int len=s.length();
	vector<int> to_roll(len,0);
	int n=roll.size();
	for(int i=0;i<n;i++)
	{
		to_roll[0]++;
		if(roll[i]>=len)
			continue;
		else
			to_roll[roll[i]]--;
	}
	string output="";
	output+=rol(s[0],to_roll[0]);
	for(int i=1;i<len;i++)
	{
		to_roll[i]=to_roll[i]+to_roll[i-1];
		char temp=s[i];
		output += rol(s[i],to_roll[i]);
	}
	return output;
}




int main()
{
	string input;
	cin>>input;
	int n;
	cin>>n;
	vector<int> roll;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		roll.push_back(temp);
	}

	cout<<"\nresult: "<<rollstring(roll,input)<<endl;
	return 0;
}