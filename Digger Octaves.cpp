#include<bits/stdc++.h>
using namespace std;
#define w(x)            int x; cin>>x; while(x--)
 
bool dfs(vector<vector<char>>grid, int i,int j,int n,int cnt)
{
    static int di[4]={0 , 0 , -1 , 1};
    static int dj[4]={-1 , 1 , 0 , 0};
    if(cnt==7)
        return true;
    
    // if(grid[i][j]=='.')
    //     return false;

    grid[i][j]='.';

    for(int ind=0;ind<4;ind++)
    {
        int newx=i+di[ind];
        int newy=j+dj[ind];
        
        if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]=='X' )
            return dfs(grid,newx,newy,n,cnt+1);
    }
    grid[i][j]='X';

    return false;
}



int32_t main()
{
    w(t)
    {
        int n;cin>>n;
        vector<vector<char>>grid(n,vector<char>(n,'X'));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vector<vector<bool>>vis(n,vector<bool>(n,false));
                int cnt=0;
                // if(grid[i][j]=='X')
                if(dfs(grid,i,j,n,cnt))
                {
                    ans++; 
                }
            }
        }
        cout<<ans<<endl;
    }

}