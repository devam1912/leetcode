class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
     int i=0;
     int j = nums.size()-1;
     int count=0;

     while(i<j)
     {
        if(nums[i]==0)
        {
            while(j>=0 && nums[j]==0) j--;

            if(i<j)
            {
                count++;

                int temp = nums[j];
                nums[j]=0;
                nums[i]=temp;

                i++;
                j--;
            }
        }
        else
        {
            while(j>=0 && nums[j]==0) j--;

            i++;
        }
     }

     return count;
    }
};