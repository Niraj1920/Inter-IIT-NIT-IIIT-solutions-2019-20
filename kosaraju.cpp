#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector <int> adj[], stack <int> &s, vector <int> &visited){
    for(int i = 0; i < adj[v].size(); i++){
        if(!visited[adj[v][i]]){
            visited[adj[v][i]] = true;
            dfs(adj[v][i], adj, s, visited);
        }
    }
    s.push(v);
}

void reverse_edges(int V, vector <pair <int, int> > &edges, vector <int> adj[]){
    for(int i = 0; i < V; i++)
        adj[i].clear();
    for(int i = 0; i < edges.size(); i++)
        adj[edges[i].second].push_back(edges[i].first);
}

void putha_dfs(int v, vector <int> adj[], vector <int> &visited, int a, vector <vector <int> > &S_C){
    for(int i = 0; i < adj[v].size(); i++){
        if(!visited[adj[v][i]]){
            visited[adj[v][i]] = true;
            S_C[a].push_back(adj[v][i]);
            putha_dfs(adj[v][i], adj, visited, a, S_C);
        }
    }
}

int strong_components(int V, vector <pair <int, int> > &edges, vector <int> adj[]){
    int E = edges.size();
    vector <int> visited(V, false);
    stack <int> s;
   
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, adj, s, visited);
        }
    }
   
    reverse_edges(V, edges, adj);
    fill(visited.begin(), visited.end(), false);
   
    vector <vector <int>> S_C(V);
    int a = 0;
    while(!s.empty()){
        int x = s.top();
        s.pop();
        if(visited[x])
            continue;
       
        visited[x] = true;
        S_C[a].push_back(x);
        for(int i = 0; i < adj[x].size(); i++){
            if(!visited[adj[x][i]]){
                putha_dfs(adj[x][i], adj, visited, a, S_C);
                visited[adj[x][i]] = true;
                S_C[a].push_back(adj[x][i]);
            }
        }
        a++;
    }
    /*for(int i = 0; i < a; i++){
        for(int j = 0; j < S_C[i].size(); j++){
            cout << S_C[i][j] << " ";
        }
        cout << endl;
    }*/
    return a;
}

int main() {
int T;
cin >> T;
while(T--){
   int V, E;
   cin >> V >> E;
   vector <pair <int, int>> edges(E);
   vector <int> adj[V];
   
   for(int i = 0; i < E; i++){
       cin >> edges[i].first >> edges[i].second;
       adj[edges[i].first].push_back(edges[i].second);
   }
   
   int res = strong_components(V, edges, adj);
   cout << res << endl;
}
return 0;
}
