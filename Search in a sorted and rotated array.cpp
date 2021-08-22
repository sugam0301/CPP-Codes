#include <iostream>
using namespace std;
int main() 
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int x;cin>>x;
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)>>1;
        if(arr[mid]==x)
        {
            cout<<mid;
            break;
        }
        else if(arr[mid]>=arr[low])
        {
            if(x<=arr[mid] && x>=arr[low])
                high=mid-1;
            else    
                low=mid+1;
        }
        else if(arr[mid]<=arr[high])
        {
            if(x>=arr[mid] && x<=arr[high])
                low=mid+1;
            else    
                high=mid-1;
        }

    }
    if(x!=arr[mid])
        cout<<-1;
}
