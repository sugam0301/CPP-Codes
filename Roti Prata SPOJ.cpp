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

bool ispossible(int *arr, int n, int barrier, int prata)
{
    int time = 0, count=0;
    for(int i=0;i<n;i++)
    {
        time=0 ; int j=1;
        while(true)
        {
            time += j*arr[i];
            j++;
            if(time > barrier)
                break;
            count++;
        }
    }
    return count>=prata;
}


int rotiprata(int *arr,int n, int low, int high,  int prata)
{
    int res = low;
    while(low <= high)
    {
        int mid = (low+high) >> 1;
        if(ispossible(arr,n,mid,prata))
        {
            res=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return res;
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int prata; cin>>prata;
    int n;cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    int low=1, high=100000000;
    cout<<rotiprata(arr, n,low, high, prata);
    
    return 0;
}