int mcm(int *arr, int i,int j, int dp[101][101])
{
    if(i>=j)
        return 0;
    int mn = INT_MAX;

    
    if(dp[i][j]!=-1)
            return dp[i][j];
    int temp=0;
    for(int k=i;k<j;k++)
    {
        int temp=mcm(arr,i,k,dp)+mcm(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,temp); 
    }
    return dp[i][j] = mn;
    
}
    int matrixMultiplication(int N, int arr[])
    {
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        return mcm(arr,1,N-1,dp);
    }
