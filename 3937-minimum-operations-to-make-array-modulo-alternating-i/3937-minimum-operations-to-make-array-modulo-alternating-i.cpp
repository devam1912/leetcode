class Solution {
public:
    
    // minimum operations needed to convert num so that
    // num % k == target
    int cost(int num, int target, int k)
    {
        int rem = num % k;
        
        // move upward
        int up = (target - rem + k) % k;
        
        // move downward
        int down = (rem - target + k) % k;
        
        return min(up, down);
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        // try every possible pair (x,y)
        // x -> even index remainder
        // y -> odd index remainder
        for(int x = 0; x < k; x++)
        {
            for(int y = 0; y < k; y++)
            {
                if(x == y) continue;

                int ops = 0;

                for(int i = 0; i < n; i++)
                {
                    if(i % 2 == 0)
                        ops += cost(nums[i], x, k);
                    else
                        ops += cost(nums[i], y, k);
                }

                ans = min(ans, ops);
            }
        }

        return ans;
    }
};