// bool issafe(vector<vector<int>>&board, int row, int col,int n)
//     {
//         //upper diag
//         for(int i=row,j=col; i>=0 and j>=0; i--,j--)
//         if(board[i][j]==1)
//         return false;
    
//         //lower diag
//         for(int i=row,j=col;i<n and j>=0; i++,j--)
//         if(board[i][j]==1)
//         return false;
        
//         //same row to the left
//         for(int i=col ; i>=0 ;i--)
//         if(board[row][i]==1)
//         return false;
        
//         return true;
//     }



//     void solve(int col,vector<vector<int>>&board, vector<vector<int>>&res, int n)
//     {
//         //base conditon
//         if(col==n)
//         {
//             vector<int>v;
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<n;j++)
//                 {
//                     if(board[i][j]==1)
//                         v.push_back(j+1);
//                 }
//             }
//             res.push_back(v);
//             return;
//         }
        
//         for(int row=0;row<n;row++)
//         {
//             if(issafe(board,row,col,n))
//             {
//                 board[row][col] = 1;
//                 solve(col+1,board,res,n);
//                 board[row][col] = 0;
//             }
//         }
        
//     }


//     vector<vector<int>> nQueen(int n) 
//     {
//         vector<vector<int>>res;
//         vector<vector<int>>board(n,vector<int>(n,0));
//         solve(0,board,res,n);
//         sort(res.begin(),res.end());
//         return res;
//     }




//METHOD 2 .....it is quite efficient

void solve(int col,vector<vector<int>>&board, vector<vector<int>>&res,
               vector<int>lower_diag,vector<int>&upper_diag,vector<int>&rows,int n)
    {
        //base conditon
        if(col==n)
        {
            vector<int>v;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==1)
                        v.push_back(j+1);
                }
            }
            res.push_back(v);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(upper_diag[row-col+n-1]==0 && lower_diag[row+col]==0 &&
                rows[row]==0)
            {
                board[row][col] = 1;
                lower_diag[row+col]=1;
                upper_diag[row-col+n-1]=1;
                rows[row]=1;
                solve(col+1,board,res,lower_diag, upper_diag,rows,n);
                lower_diag[row+col]=0;
                upper_diag[row-col+n-1]=0;
                rows[row]=0;
                board[row][col] = 0;
            }
        }
        
    }


    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>>res;
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<int>lower_diag(2*n-1 ,0), upper_diag(2*n -1, 0), rows(n,0);
        
        solve(0,board,res,lower_diag,upper_diag,rows,n);
        sort(res.begin(),res.end());
        return res;
    }

