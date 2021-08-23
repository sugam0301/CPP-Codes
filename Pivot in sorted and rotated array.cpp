#include <iostream>
using namespace std;
int main() 
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int low=0,high=n-1,mid;
    while(low<high)
    {
        mid=(low+high)>>1;
       
        if(arr[mid]>=arr[low])
            low=mid+1;
        else if(arr[mid]<=arr[high])
            high=mid;
        

    }
   cout<<arr[low];
}
