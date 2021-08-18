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
 

void gen_par(int n,int open,int close, vector<char>&curr, vector<vector<char>>&res)
{
    if(open == 0 && close == 0)  //base
    {
        res.pb(curr);
        return;
    }

    if(open!=0) //left
    {
        curr.pb('(');
        gen_par(n,open-1,close,curr,res);
        curr.pop_back();
    }

    if(open < close)  //right
    {
        curr.pb(')');
        gen_par(n,open,close-1,curr,res);
        curr.pop_back();
    }

    //but acc to coding blocks we have to print the left subtree afterwards 
    //right subtree
    return;
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    
    vector<char>curr;
    vector<vector<char>>res;
    int open=n,close=n;
    gen_par(n,open,close,curr,res);
    sort(res.begin(), res.end());

    for(auto x:res)
    {
        for(auto y:x)
        {
            cout<<y;
        }
        cout<<"\n";
    }

}