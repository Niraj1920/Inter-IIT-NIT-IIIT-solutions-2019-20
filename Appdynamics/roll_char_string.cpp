/*
Given a string s and an array roll where roll[i] represents rolling first roll[i] characters in string. 
We need to apply every roll[i] on string and output final string. 
Rolling means increasing ASCII value of character, like rolling ‘z’ would result in ‘a’, rolling ‘b’ would result in ‘c’, etc.
*/

#include <iostream>
using namespace std;
void roll_str(string &s, int roll[], int n){
    int temp[n] = {0};
    for(int i=0; i<n; i++){
        temp[0] += 1;
        if(roll[i] < n && roll[i] >= 0) temp[roll[i]] += -1;
    }
    for(int i=1; i<n; i++){
        temp[i] += temp[i-1];
    }
    for(int i=0; i<n; i++){
        s[i] = (s[i] - 'a' + temp[i])%26 + 'a';
    }
    cout<<s<<endl;
    return;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int roll[n];
	    for(int i=0; i<n; i++)  cin>>roll[i];
	    roll_str(s, roll, n);
	    
	}
	return 0;
}
