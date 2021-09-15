bool wordboggle(int index,int size,string word, vector<vector<char> >& board,
                    int m,int n, int row,int col, vector<vector<bool>>&vis)
    {
        if(index==size)
            return true;
        if(row<0 || row==m || col<0 || col==n)
            return false;
        
        if(vis[row][col] || word[index]!=board[row][col])
            return false;
        
        vis[row][col]=true;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if(i==0 && j==0)
                    continue;
                if(wordboggle(index+1,size,word,board,m,n,row+i,col+j,vis))
                    return true;
            }
        }
        vis[row][col] = false;  //backtrack
        return false;
    }
    
    
    bool searchword(string word, vector<vector<char> >& board, int m ,int n)
    {
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(word[0]==board[i][j])
                {
                    if(wordboggle(0,word.size(),word,board,m,n,i,j,vis))
                        return true;
                }
            }
        }
        return false;
    }


	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) 
	{
	    vector<string>res;
	    int m=board.size(); int n=board[0].size();
	    for(int i=0;i<dictionary.size();i++)
	    {
	        if(searchword(dictionary[i],board,m,n))
	            res.push_back(dictionary[i]);
	    }
	    return res;
	}
