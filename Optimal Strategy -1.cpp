#include <bits/stdc++.h>
using namespace std;

long long solve(int arr[],int i,int j,vector<vector<int>>&dp)
{
    if(i==j)
        return arr[i];
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]= max( arr[i]+min(solve(arr,i+1,j-1,dp), solve(arr,i+2,j,dp)) ,
                          arr[j]+min(solve(arr,i+1,j-1,dp), solve(arr,i,j-2,dp)));
}
long long maximumAmount(int arr[], int n) 
{
    vector<vector<int>>dp(31,vector<int>(31,-1));
    return solve(arr,0,n-1,dp);
}

int main() 
{
	    int N;
	    cin>>N;
	    int A[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    cout<<maximumAmount(A,N)<<endl;
	return 0;
} 
