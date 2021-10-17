int dp[100][100];
int solve(int price[], int i, int j, int year)
{
    if(i>j) return 0;
    if(i==j) return price[i]*year;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int left = price[i]*year + solve(price,i+1,j,year+1);
    int right = price[j]*year +solve(price,i,j-1,year+1);
    return dp[i][j] = max(left,right);
}
int maxProfit(int price[], int n)
{
    memset(dp,-1,sizeof(dp));
    return solve(price,0,n-1,1);
}
