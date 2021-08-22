#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int t;cin>>t;
while(t--)
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);
    int low=0,high=n-1;
    int x;cin>>x;

    int ans1,ans2;
    while(low<high)
    {
        if(arr[low]+arr[high]  ==  x)
        {
            ans1=arr[low];
            ans2=arr[high];
            low++;
            high--;
        }
        else if(arr[low]+arr[high]  >  x)
            high--;
        else    
            low++;
    }
    cout<<"Deepak should buy roses whose prices are "<<ans1<<" and "<<ans2<<"."<<endl;
}
}
