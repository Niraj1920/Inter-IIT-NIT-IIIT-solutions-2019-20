/*
Q) There is a source (S) and destination (D) and a spacecraft has to go from S to D. There are N number of wormholes in between

which has following properties:

 Each wormhole has an entry and an exit.
 Each wormhole is bi-directional i.e. one can enter and exit from any of the ends.
The time to cross the wormhole is given and the spacecraft may or may not use the wormhole to reach D.
The time taken to travel outside wormhole between two points (x1, y1) and (x2, y2) is given by a formula |x1 - x2| + |y1 - y2| where, (x1, y1) and (x2, y2) are the coordinates of two points.

The coordinates of S and D are given and we have to find the minimum time to reach D from S.

Note: It’s not mandatory to consider all the wormholes


Example : source=(0,0), destination(100,100), wormholes=3


coordinates are:

(1,2),(120,120) Cost = 5

(4,5),(120,100) Cost = 21

(6,8),(150,180) Cost = 23

Sample output=48


Explanation:

Cost from (0,0) to (1,2) is 3

Cost of wormhole 1 is 5

Cost from (120,120) to (100,100) is 40

So, total 48    
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define INT_MAX 1<<30;
int worm[10][5];
int cost(int Sx, int Sy, int Dx, int Dy){
    int ansx = Sx>Dx ? (Sx-Dx) : (Dx-Sx);
    int ansy = Sy>Dy ? (Sy-Dy) : (Dy-Sy);
    return ansx + ansy;
}

void path(int Sx, int Sy, int Dx, int Dy, int dist, int &min_dist, bool visited[]){
    min_dist = min(min_dist, cost(Sx, Sy, Dx, Dy) + dist);
    for(int i=0; i<3; i++){
        if(visited[i] == false){
            visited[i] = true;
            int temp_dist = cost(Sx, Sy, worm[i][0], worm[i][1]) + dist + worm[i][4];
            path(worm[i][2], worm[i][3], Dx, Dy, temp_dist, min_dist, visited);
            temp_dist = cost(Sx, Sy, worm[i][2], worm[i][3]) + dist + worm[i][4];
            path(worm[i][0], worm[i][1], Dx, Dy, temp_dist, min_dist, visited);
            visited[i] = false;
        }
    }
}
int main()
{
    int Sx, Sy, Dx, Dy;
    cin>>Sx>>Sy>>Dx>>Dy;
    
    int n;
    cin>>n;
    
    for(int i=0; i<n ;i++){
        for(int j=0; j<5; j++){
            cin>>worm[i][j];
        }
    }

    int min_dist = INT_MAX;
    bool visited[n] = {false};
    path(Sx, Sy, Dx, Dy, 0, min_dist, visited);
    cout<<min_dist<<endl;
    return 0;
}
