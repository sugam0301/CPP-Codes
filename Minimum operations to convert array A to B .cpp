/*Note: We are not using LCS here 
Because finding LCS is O(N*M) ,
and 1 ≤ M , N ≤ 1e5 here.
We are using the property of B[ ] 
being sorted and having distinct elements 
here to reduce the problem to LIS. 
We can find LIS in O(NlogN).*/

    int lis(vector<int> v)
    {
     vector<int> lis;
     
     for(int i=0;i<v.size();i++)
     {
          auto it = lower_bound(lis.begin(), lis.end(), v[i]);
         if(it!=lis.end())
         *it=v[i];
         else
         lis.push_back(v[i]);
     }
     return lis.size();
    }
 
    int minInsAndDel(int A[], int B[], int N, int M) 
    {
        // code here
        vector<int> v;
        unordered_set<int> s;
        
        for(int i=0;i<M;i++){
            s.insert(B[i]);
        }
        
        for(int i=0;i<N;i++){
            if(s.find(A[i])!=s.end()){
                v.push_back(A[i]); 
       // Notice, we are pushing common elements of A and B
            }
        }
        
        int LCS=lis(v);
        
        return N+M-(2*LCS);
    }
