//Minimum adjacent swaps required to make a string palindrome.
//input:"strings to check and a zero for ending input"
//maann
//namna
//0

#include <bits/stdc++.h>
using namespace std;
int main(){ 
    string s;
    while(1){
        cin>>s;
        if(s=="0")
        	return 0;
        long long i,j,k,n=s.length();
        j=n-1; 
	long long sum=0,x,y,ans=0,c=0;
        int a[26]={0};
        for(i=0;i<n;i++)
        	a[s[i]-'a']++;
        
        for(i=0;i<26;i++)
        	if(a[i]&1)
        		c++;
        if(c>1){
            cout<<"Impossible\n";
            continue;
        }
        i=0;j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                x=j;
                y=i;
                long long c1=0,c2=0;
                while(s[x]!=s[i]){
                    x--;
                    c1++;
                }
                while(s[y]!=s[j]){
                    y++;
                    c2++;
                }
                if(c1<c2){
                    sum+=c1;
                    for(k=x;k<j;k++)
                    swap(s[k],s[k+1]);
                }
                else{   
                    sum+=c2;
                    for(k=y;k>i;k--)
                    swap(s[k],s[k-1]);
                }
            }
        }
        cout<<sum<<endl;       
    }
}
