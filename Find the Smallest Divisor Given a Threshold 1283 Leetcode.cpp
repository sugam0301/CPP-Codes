bool ispossible(vector<int>& nums, int threshold,int mid)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
               cnt+=(nums[i]+mid-1)/mid;
        
        if(cnt<=threshold) 
            return true;
	    return false;
	}
    
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low=1, high=*max_element(nums.begin(),nums.end());
        int res=high;
        
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            
            if(ispossible(nums,threshold,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;    
    }
