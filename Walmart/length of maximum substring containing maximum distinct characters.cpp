#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int smallestSubstring_minDistinctChar(string s){
    int distinct = 0;
    int n = s.length();
    int ar[26];
    memset(ar, -1, sizeof(ar));
    
    for(int i=0; i<n; i++){
        if(ar[s[i] - 'a'] == -1){
            distinct++;
            ar[s[i] - 'a'] = 0;
        }
    }
    int i=0, j = 0, current = 0, minLen = INT_MAX;;
    while(i<n){
        if(ar[s[i]-'a'] == 0){
            current++;
            ar[s[i]-'a']++;
        }
        else{
            ar[s[i]-'a']++;
        }
        if(current == distinct){
            while(ar[s[j]-'a'] > 1){
                j++;
                ar[s[j]-'a']--;
            }
            int current_len = i-j+1;
            if(minLen>current_len)
                minLen = current_len;
        }
        i++;
    }
    return  minLen;
}
int main(){
    
    string s = "aaaaaaa";
    cout<<smallestSubstring_minDistinctChar(s)<<endl;
    return 0;
}
