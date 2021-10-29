int orangesRotting(vector<vector<int>>& grid) 
    {
        //1.Initialisation
        int n=grid.size();
        int m=grid[0].size();
        static int dx[4]={-1,0,1,0};  //for x directions
        static int dy[4]={0,1,0,-1};  //for y directions 
        
        queue<pair<int,int>>q; //for storing the indices
        
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==2)   //multi source BFS will be storing the rottenoranges in q only at first.
        q.push({i,j});
          
        int timer=-1;   //because we already have in initial stage as 2s in the queue but we want to find out for rest of them 
        while(q.size())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                int x=q.front().first; 
                int y=q.front().second;
            
                for(int i=0;i<4;i++)
                {
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==1 )
                    {
                        q.push({newx,newy});
                        grid[newx][newy] = 2;
                    }    
                }
                q.pop();
            }
            timer++;
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
                if(grid[i][j]==0)
                    cnt++;
            }
        }
        if(cnt==(n*m))
            return 0;
        return timer;
    }
