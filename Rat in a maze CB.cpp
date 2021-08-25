#include<bits/stdc++.h>
using namespace std;
#define int             long long



void solve(vector<vector<char>>&maze, int i, int j, int row, int col, vector<vector<int>>&vis)
{
    if(i==row-1 && j==col-1)     //base - when rat reaches the rightmost bottom
    {
        vis[i][j]=1;
        for(int i=0;i<row;i++)     //result
        {
            for(int j=0;j<col;j++)
            {
            cout<<vis[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    
    if(j+1<col && (vis[i][j+1] == 0) && (maze[i][j+1]=='O') )  //right
    {
        vis[i][j] = 1;
        solve(maze,i,j+1,row,col,vis);
        vis[i][j] = 0;
    }

    if(i+1<row && (vis[i+1][j] == 0) && (maze[i+1][j]=='O') )  //down
    {
        vis[i][j] = 1;
        solve(maze,i+1,j,row,col,vis);
        vis[i][j] = 0;
    }
    return;
}


int32_t main()
{
    int row,col;   //initialise
    cin>>row>>col;
    vector<vector<char>>maze(row,vector<char>(col));
    
    for(int i=0;i<row;i++) // input
    {
        for(int j=0;j<col;j++)
        {
            cin>>maze[i][j];
        }
    }

    vector<vector<int>>vis(row,vector<int>(col,0));  //visited matrix
    
	if(maze[0][0] == 'O' && maze[row-1][col-1]=='O')
		solve(maze,0,0,row,col,vis);
	else
		cout<<"-1";
    return 0;
}

// ** dont know in the case when the solution doesnt exist