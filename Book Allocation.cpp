#include <bits/stdc++.h>
using namespace std;

bool ispossible(int *arr,int n,int barrier,int k)
{
    int pages=0,allocstud=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > barrier)
            return false;
        if(pages+arr[i] > barrier)
        {
            allocstud++;
            pages=arr[i];
        }
        else
            pages+=arr[i];
    }
    if(allocstud > k)
        return false;
    else
        return true;

}


int bookallocation(int *arr,int n,int k)
{
    int low=arr[0],high=0;
    for(int i=0;i<n;i++)
    {
        low=min(arr[i],low);
        high+=arr[i];
    }
    int res=0;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(ispossible(arr,n,mid,k))
        {
            res = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return res;
} 


int main() 
{
    int n;cin>>n;
    int k;cin>>k;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<bookallocation(arr,n,k);
}
