/*
Q2. You are given two strings s and t. |s|>=|t|  You need to determine whether t can be concatenated multiple times to obtain s. 
Also if this is possible to do then you need to output the smallest string x such that both s and t can be obtained from x by some number
of concatenations.
Sol. Can be done using KMP

*/
//using z algorithm...
#include <iostream>
using namespace std;

int main()
{
    string s, t;
    cin>>s;
    cin>>t;
    //isConcatenated(s, t);
    string z_str = t + "$" + s;
    int z_len = z_str.length();
    int z_arr[z_len] = {0};
    //cout<<z_str<<endl;
    
    z_arr[0] = 0;
    int l = 0, r = 0, k;
    for(int i=1; i<z_len; i++){
        if(i > r){
            l = i;
            r = i;
            while(r<z_len && z_str[r] == z_str[r-l]){
                r++;
            }
            z_arr[i] = r-l;
            r--;
        }
        else{
            k = i - l;
            if(z_arr[k] < r - i + 1){
                z_arr[i] = z_arr[k];
            }
            else{
                l = i;
                while(r < z_len && z_str[r] == z_str[r-l]){
                    r++;
                }
                z_arr[i] = r-l;
                r--;
            }
        }
    }
    //for(int i=0; i<z_len; i++){
    //    cout<<z_arr[i]<<" ";
    //}
    //cout<<endl;
    
    for(int i=t.length()+1; i<z_len; i+=t.length()){
        if(z_arr[i] != t.length()){
            cout<<i<<"can't form s from t"<<endl;
            return -1;  //t can't be concate to form s
        }
    }
    //cout<<"possible"<<endl;
    //reached here means s can be formed by cancatinating t
    //now search for x which can form t by concatenation
    int x_len = 0;
    for(int i=t.length()+2; i<z_len; i++){
        if(z_arr[t.length()+1] == z_arr[i]){
            x_len = i - t.length() - 1;
            break;
        }
    }
    //cout<<x_len;
    for(int i=0; i<x_len; i++){
        cout<<t[i];     //prints if found x
    }
    
    return 0;
}
