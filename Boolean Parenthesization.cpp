int solve(int n,string &s,int i,int j, int istrue)
{
        if(i>j)  //BC 1- length of negative number , not possible
            return 0;
            
        if(i==j)   //base conditions  - if only length string is available 
        {
            if(istrue==1)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        
    int ans=0;
    if (dp[i][j][istrue] != -1)
            return dp[i][j][istrue]%1003;
        
    for(int k=i+1 ; k<j ;  k=k+2)
    {
        int lf, lt, rt, rf;
        if (dp[i][k - 1][1] == -1)
        {
            lt = solve(n,s, i, k - 1, 1);
        } // Count no. of T in left partition
        else {
            lt = dp[i][k - 1][1];
        }
 
        if (dp[k + 1][j][1] == -1)
        {
            rt = solve(n,s, k + 1, j, 1);
        } // Count no. of T in right partition
        else
        {
            rt = dp[k + 1][j][1];
        }
 
        if (dp[i][k - 1][0] == -1)
        {
            // Count no. of F in left partition
            lf = solve(n,s, i, k - 1, 0);
        }
        else
        {
            lf = dp[i][k - 1][0];
        }
 
        if (dp[k + 1][j][0] == -1)
        {
            // Count no. of F in right partition
            rf = solve(n,s, k + 1, j, 0);
        }
        else
        {
            rf = dp[k + 1][j][0];
        }
            
            
            //try out diff comb of left and right subtrees wrt the operators in between them
            if(s[k] == '|')
            {
                if(istrue == 1)
                    ans+= (lf*rt + lt*rf + lt*rt);
                else
                    ans+= lf*rf;
            }
            else if(s[k] == '^')
            {
                if(istrue == 1)
                    ans+= (lf*rt + lt*rf);
                else
                    ans+= (lf*rf + lt*rt);
            }
            else if(s[k] == '&')
            {
                if(istrue == 1)
                    ans+=  (lt*rt);
                else
                    ans+= (lf*rf + lf*rt + lt*rf);
            }
            dp[i][j][istrue] = ans%1003;
        }
    return ans%1003;
}


    int dp[201][201][2];
    int countWays(int N, string S)
    {
        memset(dp,-1,sizeof(dp));
        int istrue=1 ;
        
        int n=N;
        string s=S;
        return solve(n,s,0,n-1,istrue);
    }
