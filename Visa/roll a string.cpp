/*
Given a string s and an array roll where roll[i] represents rolling first roll[i] characters in string. 
We need to apply every roll[i] on string and output final string. 
Rolling means increasing ASCII value of character, like rolling ‘z’ would result in ‘a’, rolling ‘b’ would result in ‘c’, etc.
*/

#include <iostream>
#include <vector>
using namespace std;

void roll_string(string &s, vector<int> a){
    vector<int> temp(a.size(), 0);
    for(int i=0; i<a.size(); i++){
        if(a[i] > 0)    temp[0] += 1;
        if(a[i]>=0 && a[i]<a.size()) temp[a[i]] += -1;
    }
    for(int i=1; i<a.size(); i++){
        temp[i] += temp[i-1];
    }
    for(int i=0; i<s.length();i++){
        s[i] = (s[i] - 'a' + temp[i])%26 + 'a';
    }
    cout<<s<<endl;
    return;
}
int main()
{
    int n;//len of string
    cin>>n;
    string s;
    vector<int> a(n, 0);
    
    cin>>s;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    roll_string(s, a);
    return 0;
}
