#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
void solve(vector<vector<int>>&grid,int x,int y,int n,vector<vector<bool>>&visited,string path)
{
    if(x==n-1 && y==n-1)
    {
        cout<<path<<" ";
        return;
    }
    if(x<0 || y<0 || x>=n || y>=n || grid[x][y]==0 || visited[x][y]==true)
    {
        return;
    }
    visited[x][y]=true;
    solve(grid,x-1,y,n,visited,path+"T");
    solve(grid,x+1,y,n,visited,path+"D");
    solve(grid,x,y-1,n,visited,path+"L");
    solve(grid,x,y+1,n,visited,path+"R");
    visited[x][y]=false;
}
int main()
{
    int n,num;
    cout<<"Enter grid size(n-squared): ";
    cin>>n;
    vector<vector<int>>grid;
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    cout << "Enter the grid values (0 for obstacle, 1 for path):\n";
    for(int i=0;i<n;i++)
    {
        vector<int>v;
        for(int j=0;j<n;j++)
        {   cin>>num;
            v.push_back(num);
        }
        grid.push_back(v);
    }
    cout<<"your input grid is:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<"Possible paths:"<<endl;
    solve(grid,0,0,n,visited,"");
    return 0;
}
