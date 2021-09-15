bool issafe(int grid[N][N],int row, int col, int num)
    {
        for(int i=0;i < 9;i++)
        {
            if(grid[row][i]==num) return false;
            
            if(grid[i][col]==num) return false;
            
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3]==num) return false;
            
        }
            
        return true;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int num=1;num<=9;num++)
                    {
                        if(issafe(grid,i,j,num))
                        {
                            grid[i][j] = num;
                            
                            if(SolveSudoku(grid) == true)
                                return true;
                            else
                                grid[i][j]=0;
                        }
                    }
                    return false;
                } 
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i < N;i++)
        for(int k=0;k < N;k++)
        cout<<grid[i][k]<<" "; 
    }
