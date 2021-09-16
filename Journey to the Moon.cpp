#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
 
class Solution
{
    public:

    void dfs(int n,vector<int>astronaut[], int start, int &size, bool *vis)
    {
        vis[start] = true;
        size+=1;
        for(auto x: astronaut[start])
        {
            if(!vis[x])
            {
                //cout<<x<<" ";
                dfs(n,astronaut,x,size,vis);
            }
        }
        //cout<<endl;
        
    }

    int journeyToMoon(int n, vector<int> astronaut[]) 
    {
        bool vis[n];
        for(int i=0;i<n;i++)
            vis[i] = false;

        int cnt=0;
        vector<int> componentsize;

        // for(int i=0;i<n;i++)
        //     componentsize[i] = 0;

        int size;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                size=0;
                dfs(n,astronaut,i,size,vis);
                componentsize.pb(size);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        int res=0;

        // for(int i=0;i<cnt;i++)
        //     cout<<componentsize[i]<<" ";
        // cout<<endl;

        for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<cnt;j++)
                res += componentsize[i]*componentsize[j];
        }
        for(int i=0;i<cnt;i++)
            res -=componentsize[i]*componentsize[i];

        return res/2;
    }
};

int32_t main()
{
    int n,p;
    cin>>n>>p;

    vector<int>astronaut[n];
    for(int i=0;i<p;i++)
    {
        int u,v;
        cin>>u>>v;
        astronaut[u].push_back(v);
        astronaut[v].push_back(u);
    }
    Solution obj;
    cout << obj.journeyToMoon(n,astronaut);
}