class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        int low=0,high=n-1;
        
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-1]!=nums[n-2])
                return nums[n-1];
        
        int mid;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(nums[mid]!=nums[mid+1] && nums[mid-1]!=nums[mid])
                return nums[mid];
            
            
            if(nums[mid]==nums[mid+1])
            {
                if(mid%2==0)
                    low=mid+1;
                else
                    high=mid-1;
            }
            
            else if(nums[mid]==nums[mid-1])
            {
                if(mid%2==0)
                    high=mid-1;
                else
                    low=mid+1;
            } 
        }
        return -1;
    }
    
};
