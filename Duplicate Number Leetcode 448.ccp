        int n=nums.size();
        for(int i=0 ; i < n; i++)
        {
            while(nums[i] < nums.size()  &&   nums[i] != nums[nums[i]])
                swap(nums[i] , nums[nums[i]]);
        }
        
        for(int i=0 ; i<n ;i++)
        {
            if(nums[i]!=i)
                return i;
        }
        return n;
