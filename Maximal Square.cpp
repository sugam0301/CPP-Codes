int maximalSquare(vector<vector<char>>& matrix) 
    {
        int dp[301][301];
        memset(dp,0,sizeof(dp));
        
        int r = matrix.size();
        int c= matrix[0].size();
        
        
        
        int largest=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j])) ;
                    if(largest < dp[i][j])
                        largest = dp[i][j];
                }
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return largest*largest;
    }
};
