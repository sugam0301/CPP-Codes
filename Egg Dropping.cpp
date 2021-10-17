int t[201][201];
    int solve(int n,int f)
    {
        if(n==1)
            return f;   //it will be th worst case as we will have to check for each floor
        if(f==0 ||f==1) //if it is 0floors ,then 0 ways to check and if 1floor ,1way only to check 
                        //whether the egg will survive or not
            return f; 
        
        if(t[n][f]!=-1)
            return t[n][f];
        
        int mn=INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int temp = 1 + max(solve(n-1,k-1), solve(n,f-k));
            mn = min(mn,temp);
        }
        return t[n][f] = mn;
    }
    
    
    int eggDrop(int n, int k) 
    {
        memset(t,-1,sizeof(t));

        return solve(n,k);
    }
