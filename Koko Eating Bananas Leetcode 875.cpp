class Solution {
public:
    bool ispossible(vector<int>& piles, int h,int mid)
    {
        int hrs=0;
        for(int i=0;i<piles.size();i++)
        {
		    if(piles[i] <= mid)
                hrs+=1;
            else
                hrs+=(piles[i]/mid) + 1;
        }
        if(hrs<=h) 
            return true;
	    return false;
	}
	
	
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int res=high;
        if(piles.size()==1)
        {
            int p = piles[0]/h;
            if(piles[0]%h==0)
                return p;
            else
                p+1;
        
        }
        
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            
            if(ispossible(piles,h,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};
