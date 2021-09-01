class Solution {
public:
     bool ispossible(vector<int>& nums, int m,int mid)
     {
         int sum=0, count=1;
         for(int i=0;i<nums.size();i++)
         {
             if(sum+nums[i]>mid)
             {
                 sum=nums[i];
                 count++;
             }
             else
                 sum+=nums[i];
         }
         if(count > m)
             return false;
         else
            return true;
     }
    
    
    int splitArray(vector<int>& nums, int m) 
    {
        int low=0,high=0;
        for(int i=0;i<nums.size();i++)
        {
            high+=nums[i] ;
            low=max(low,nums[i]);
        }
        
        int res=0;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(ispossible(nums,m,mid))
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
