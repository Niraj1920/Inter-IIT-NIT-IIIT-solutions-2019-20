#include<bits/stdc++.h>
using namespace std;


int overlapping_pair(string str1,string str2, string &str)
{
	int max_length=INT_MIN;
	int len1=str1.length();
	int len2=str2.length();
	for(int i=1;i<=min(len1,len2);i++)
	{
		if(str1.compare(len1-i,i,str2,0,i)==0)
		{
			if(max_length<i)
			{
				max_length=i;
				str=str1+str2.substr(i);
			}
		}
	}

	for(int i=1;i<min(len1,len2);i++)
	{
		if(str1.compare(0,i,str2,len2-i,i)==0)
		{
			if(max_length<i)
			{
				max_length=i;
				str=str2+str1.substr(i);
			}
		}
	}
	return max_length;
}



string findshortest(vector<string> &input,int &len)
{
	while(len!=1)
	{
		int max_size=INT_MIN;
		int l,r;
		string resStr;
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				string str;
				int res=overlapping_pair(input[i],input[j],str);
				if(max_size<res)
				{
					max_size = res;
					resStr.assign(str);
					l=i,r=j;
				}
			}
		}
		len--;
		if(max_size == INT_MIN)
		{
			input[0] += input[len];
		}
		else
		{
			input[l]=resStr;
			input[r]=input[len];
		}
	}
	return input[0];
}

int main()
{
	string arr[] = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"}; 
    int len = sizeof(arr)/sizeof(arr[0]); 
    vector<string> input(5);
    for(int i=0;i<5;i++)
    	input[i]=arr[i];
  
    cout << "The Shortest Superstring is "
         << findshortest(input, len); 
  
    return 0; 
}

