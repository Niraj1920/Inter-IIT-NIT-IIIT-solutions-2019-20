//Input = "My name is khan"
//Output = "My%20name%20is%20khan"

#include <iostream>
using namespace std;

string urlify(string s){
    string res, temp;;
    for(int i=0; i<s.length(); i++){
        
        if(s[i] != ' '){
            temp += s[i];
        }
        else{
            res += temp + "%20";
            temp = "";
        }
    }
    res += temp;
    return res.substr(0, res.length());
}
int main()
{
    string s = "My nam is khan";
    
    cout<<urlify(s)<<endl;
    return 0;
}
