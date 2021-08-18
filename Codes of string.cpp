#include<bits/stdc++.h>
using namespace std; 
#define int             long long
#define pb              push_back  

void solve( string &s, int i,int n, vector<char>&curr, vector<vector<char>>&res)
{
    if(i==n) 
    {
        res.pb(curr);
        return;
    }
    
    curr.pb(char(s[i]-'0'+97 -1));    //left subtree - taking 1char at a time
    solve(s,i+1,n,curr,res); 
    curr.pop_back();
    
 
    if(i+1 != n)                     //right subtree - taking 2char at a time
    {
        int c =  (s[i]-'0')*10 + s[i+1]-'0';
        //cout<<char(c)<<endl;
        if(c<=26)
        {
            curr.pb(char(c+'a'-1)); 
            solve(s,i+2,n,curr,res);
            curr.pop_back();
        }
        
    }
    return;
    
}

int32_t main()
{
    int num; cin>>num;   //input
    string s = to_string(num);
    int n= s.size();

    vector<char>curr;
    vector<vector<char>>res;
    solve(s,0,n,curr,res);  //rec fxn
    
    cout<<"[";
    for(int i=0;i<res.size();i++)
    {
        for(auto x:res[i])
        {
            cout<<x;
        }
        if(i!=res.size()-1)
            cout<<", ";
    }
    cout<<"]";
}