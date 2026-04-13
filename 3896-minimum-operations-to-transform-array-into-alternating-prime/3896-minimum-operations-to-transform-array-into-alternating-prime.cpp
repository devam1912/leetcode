class Solution {
public:

    bool isprime(int n)
    {
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;

        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0) return false;
        }
        return true;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int counter = 0;

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0) 
            {
                while(!isprime(nums[i]))
                {
                    nums[i]++;
                    counter++;
                }
            }
            else 
            {
                while(isprime(nums[i]))
                {
                    nums[i]++;
                    counter++;
                }
            }
        }
        return counter;
    }
};