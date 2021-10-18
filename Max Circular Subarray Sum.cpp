class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int res=nums[0];
            
        for(int i=1;i<nums.size();i++)
        {
            ans=max(ans+nums[i],nums[i]);
            res=max(res,ans);
        }
        return res;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int sum=0;
        int kadane = maxSubArray(nums);
        if(kadane<0)    return kadane; //important
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i] = -nums[i];
        }
        
        int circular = sum + maxSubArray(nums);
        return max(kadane,circular);
        
    }
};
