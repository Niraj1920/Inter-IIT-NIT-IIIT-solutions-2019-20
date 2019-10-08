/*Given a string S of lowercase letters, find out the size of smallest possible substring of S which contains all the distinct letters of S
at least once.*/
//same question as shortest substring...
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int shortestSubstring(string str){
    int len = str.length(), distinct = 0;
    vector<int> freq(26, -1);
    for(int i=0; i<len; i++){
        freq[str[i] - 'a'] = 0;
    }
    for(int i=0; i<len; i++){
        if(freq[i] == 0)    distinct++;
    }
    int temp = 0, min_len = INT_MAX;
    for(int i=0, j=0; i<len; i++){
        if(freq[str[i] - 'a'] == 0) {
            freq[str[i] - 'a']++;
            temp++;
        }
        else{
            freq[str[i] - 'a']++;
        }
        //cout<<temp<<" "<<distinct<<" "<<i<<" "<<j<<endl;//aabcbcdbca
        if(temp == distinct){
            while(freq[str[j] - 'a'] > 1){
                freq[str[j] - 'a']--; 
                j++; 
            } 
            int len_window = i - j + 1; 
            if(min_len > len_window){ 
                min_len = len_window; 
            } 
        }
    }
    return min_len;
}

int main()
{
    string str;
    cin>>str;
    int res = shortestSubstring(str);
    cout<<res;
    return 0;
}
