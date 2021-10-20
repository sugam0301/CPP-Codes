int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();

        int dp[r][c];
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<r;i++)
        {
            if(obstacleGrid[i][0]==1)
                break;
            dp[i][0] = 1;
        }
        
        for(int i=0;i<c;i++)
        {
            if(obstacleGrid[0][i]==1)
                break;
            dp[0][i] = 1;
        }
        
        
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(obstacleGrid[i][j]==1)
                    continue;
                dp[i][j] = 0;
                
                if(dp[i][j-1]!=-1)
                    dp[i][j] = dp[i][j-1];
                if(dp[i-1][j]!=-1)
                    dp[i][j] = dp[i-1][j] + dp[i][j];
                                        
            }
        }
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        if(dp[r-1][c-1]==-1)
            return 0;
        
        return dp[r-1][c-1];
    }
