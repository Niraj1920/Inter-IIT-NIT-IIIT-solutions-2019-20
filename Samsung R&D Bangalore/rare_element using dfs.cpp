#include<iostream>
using namespace std;
typedef struct point
{
    int x,y;
}point;

void dfs(point loc,point rare, int dist,int path[100][100],bool visited[100][100],int &mindist, bool &valid)
{
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};

    if(loc.x==rare.x && loc.y==rare.y)
    {
        if(mindist > dist)
            mindist=dist;

        valid = true;
        return;
    }

    for(int i=0;i<4;i++)
    {
        //cout<<"hi";
        //cout<<loc.x<<" "<<loc.y;
        if(loc.x+dx[i]>=0 && loc.x+dx[i]<4 && loc.y+dy[i]>=0 && loc.y+dy[i] <4 && path[loc.x+dx[i]][loc.y+dy[i]] && !visited[loc.x+dx[i]][loc.y+dy[i]])
        {
            point temp;
            temp.x = loc.x+dx[i];
            temp.y = loc.y+dy[i];
            visited[loc.x+dx[i]][loc.y+dy[i]]=true;
            dfs(temp,rare,dist+1,path,visited,mindist,valid);
            visited[loc.x+dx[i]][loc.y+dy[i]]=false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int path[100][100];
    bool visited[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>path[i][j];
            visited[i][j]=false;
        }
    }
    int rare_count;
    cin>>rare_count;
    point rare_points[rare_count];
    for(int i=0;i<rare_count;i++)
    {
        cin>>rare_points[i].x>>rare_points[i].y;
            
    }

    int final_dist=1<<30;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(path[i][j])
            {
                point loc;
                loc.x=i;
                loc.y=j;
                bool valid;
                int maxdist=-1;
                for(int k=0;k<rare_count;k++)
                {
                    int mindist=1<<30;
                    valid==false;
                    //cout<<"check";
                    dfs(loc,rare_points[k],0,path,visited,mindist,valid);
                    if(!valid)
                        break;
                    else
                    {
                        if(mindist>maxdist)
                            maxdist=mindist;
                    }
                }
                if(valid)
                {
                    if(final_dist>maxdist)
                        final_dist=maxdist;
                }
            }
        }
    }
    cout<<"\nmindist:"<<final_dist<<endl;
    return 0;
}
