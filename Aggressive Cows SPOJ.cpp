#include<bits/stdc++.h>
using namespace std;
#define int             long long

bool ispossible(int *arr, int n, int dist, int cows)
{
    int count=1, coord=arr[0];
    for(int i=1; i<n; i++)
    {
        if((arr[i] - coord) >= dist)  //atleast this distance
        {
            count++;
            coord = arr[i];
        } 
        if(count == cows)
            return true;
    }
    return false;
}


int aggressive_cows(int *arr,int n, int low, int high,  int cows)
{
    int res = 1;
    while(low <= high)
    {
        int mid = (low+high) >> 1;
        if(ispossible(arr,n,mid,cows))
        {
            low=mid+1;
            res = mid; 
        }
        else
             high=mid-1;
    }
    return res;
}


int32_t main()
{
    int cows; cin>>cows;
    int n;cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    int low=1, high;
    int maxx=arr[0], minn=arr[0];
    for(int i=0;i<n;i++)
    {
        maxx=max(arr[i],maxx);
        minn=min(arr[i],minn);
    }
    
    high = maxx-minn;
    cout<<aggressive_cows(arr, n,low, high, cows);
}