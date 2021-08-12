#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int merge(vector<int>&arr,int low,int mid,int high)
{
    int count=0;
    int i = low, j = mid+1 ; int n= arr.size();
    vi v(n); int k=low;

    while(i <= mid and j <= high)
    {
        if(arr[i] <= arr[j])
            v[k++] = arr[i++];
        else
        {
            v[k++] = arr[j++];
            count+=(mid+1)-i;
        }
    }

    while(i <= mid)
        v[k++] = arr[i++];
    while(j <= high)
        v[k++] = arr[j++];
    
    for(int i=low ; i <= high ; i++)
         arr[i] = v[i] ;

    return count;   
}

int merge_sort(vector<int> &arr,int low,int high)
{
    
    if(low < high) 
    {
        int res=0;
        int mid=(low+high)>>1;
        res+=merge_sort(arr,low,mid);
        res+=merge_sort(arr,mid+1,high);
        res+=merge(arr,low,mid,high);
        return res;
    }
    else
        return 0;
}

int32_t main()
{
    int n; cin>>n;
    vi arr(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<merge_sort(arr,0,n-1);
    
    
    return 0;
}