#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "aaa";
    string t = "$";
    int l = 0;
    while(l < a.length()){
        t += '#';
        t += a[l];
        l++;
    }
    t += "#@";
    //cout<<a<<endl;
    //cout<<t<<endl;
    vector<int> p(t.length(), 0);
    
    int c = 0, r = 0;
    for(int i=1; i<t.length(); i++){
        int mirr = 2*c - i;
        if(i < r)
            p[i] = min(r-i, p[mirr]);
        
        while(t[i + (1 + p[i])] == t[i - (1 + p[i])])
            p[i]++;
            
        if(i + p[i] > r){
            c = i; 
            r = i + p[i];
        }
    }
    /*for(int i=0; i<p.size(); i++)
        cout<<p[i]<<" ";
        cout<<endl;*/
        
    int allpal = a.length();
    for(int i=0; i<p.size(); i++){
        allpal += p[i]/2;
    }
    
    cout<<allpal<<endl;
    return 0;
}
