class Solution {
public:
    int minOperations(vector<int>& nums) {
        int left=0;
        int right=0;
        int n = nums.size();
        int size=0;
        int count=0;
        while(right<n)
        {
            size++;
            if(size==3)
            {
                if(nums[left]==0)
                {
                    count++;
                    for(int i=left;i<left+3 && i<n;i++)
                    {
                        if(nums[i]==0) nums[i]=1;
                        else nums[i]=0;
                    }
                    left++;
                }
                else
                {
                    left++;
                }
                    
                    size--;
            }
            right++;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) return -1;
        }
        return count;
    }
};