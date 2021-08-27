#include <bits/stdc++.h>
using namespace std;


bool solve(int a[],int n,int mid,int m)
{
    int sum=0;
    for(int i=0;i<n;i++)
    if(a[i]>mid)	
    sum=sum+a[i]-mid;
    
    if(sum>=m)
        return true;
    else    
        return false;
}



int main() {
    int n;
    int m;
    cin>>n>>m;
    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];


    int lb=0;
    int ub = *max_element(a,a+n);

    int mid;
    int ans=0;
    while(lb<=ub)
    {
    	mid=(lb+ub)/2;
    	if(solve(a,n,mid,m))
    	{
    		ans=mid;
    		lb=mid+1;
    	}
    	else
    		ub=mid-1;
    }
    cout<<ans;

return 0;
}