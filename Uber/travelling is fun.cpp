#include <bits/stdc++.h>

using namespace std;
int findparent(int x,vector<int>& parent)
{
    if(x==parent[x])
        return x;
    else
        parent[x]=findparent(parent[x],parent);
    return parent[x];
}
void unionfind(vector<int>& parent,int i,int j)
{
    int x=findparent(i,parent);
    int y=findparent(j,parent);
    parent[y]=x;
}
vector <int> connectedCities(int n, int g, vector <int> originCities, vector <int> destinationCities) {
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++)
        parent[i]=i;
       
    for(int i=g+1;i<=n;i++)
    {
        for(int j=2*i;j<=n;j+=i)
        {
            unionfind(parent,i,j);
        }
    }
    vector<int> ans(originCities.size(),0);
    for(int i=0;i<originCities.size();i++)
    {
        if(findparent(originCities[i],parent)==findparent(destinationCities[i],parent))
            ans[i]=1;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int g;
    cin >> g;
    int originCities_cnt;
    cin >> originCities_cnt;
    vector<int> originCities(originCities_cnt);
    for(int originCities_i = 0; originCities_i < originCities_cnt; originCities_i++){
    cin >> originCities[originCities_i];
    }
    int destinationCities_cnt;
    cin >> destinationCities_cnt;
    vector<int> destinationCities(destinationCities_cnt);
    for(int destinationCities_i = 0; destinationCities_i < destinationCities_cnt; destinationCities_i++){
    cin >> destinationCities[destinationCities_i];
    }
    vector <int> res = connectedCities(n, g, originCities, destinationCities);
    for (ssize_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i != res.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
