/*
You are given N points on a positive number line. You have to put them in different jars. Each jar can have at most C points and difference b/w any two points in a jar cannot exceed K.
Find minimum number of jars required. (20 MARKS)

*/
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n, c, k;
    cin>>n>>c>>k;
    int x=0;//jars
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int len = sizeof(ar)/sizeof(ar[0]);
    sort(ar, ar+len);
    for(int i=0; i<n; i++){
        cout<<ar[i]<< " ";
    }cout<<endl;
    int p = 0;
    for(int i=0; i<n; i++){
        int minpoint = i;
        p = 0;
        while(ar[i] - ar[minpoint] <= k && p++ <= c){
            cout<<ar[i]<<" ";
            i++;
        }
        cout<<endl;
        x++;
        i--;
    }
    cout<<"jars required: "<<x<<endl;
    return 0;
}
