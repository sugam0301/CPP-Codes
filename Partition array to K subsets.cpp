class Solution{
  public:
   
    int f(int a[], int n ,int k,int sum, vector<vector<int>>&dp)
    {
        if(sum==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(a[n-1]<=sum)
            return dp[n][sum] = f(a,n-1,k,sum,dp) + f(a,n-1,k,sum-a[n-1],dp);
        else
            return dp[n][sum] = f(a,n-1,k,sum,dp);
    }
    
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        sort(a, a+n); //important
        int sum=0;
         for(int i=0; i<n; i++)
            sum+=a[i];
        if((sum % k)!=0 || a[n-1]>sum/k)  //important
            return false;
        
        sum = sum/k;
        
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        //memset(dp,-1,sizeof(dp));
        
    
        if(k <= f(a,n,k,sum,dp));
            return true; 
        return false;
    }
