#include <iostream>
using namespace std;
int main() 
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int low=0,high=n-1,mid;
    int res=arr[low];
    while(low<=high)
    {
        mid=(low+high)>>1;
       
        if(arr[mid]>=arr[low])
        {
            res=mid;
            low=mid+1;
        }
        else if(arr[mid]<=arr[high])
        {
            high=mid;
        }

    }
   if(res>0)
   		cout<<res-1;
	else	
		cout<<n-1;
}
