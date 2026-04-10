class Solution {
public:

    int dischecker(vector<int>& nums, int value)
    {
        vector<int> check;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == value)
                check.push_back(i);
        }

        if(check.size() < 3) return INT_MAX;

        int ans = INT_MAX;

        for(int i = 0; i + 2 < check.size(); i++)
        {
            int dist = 2 * (check[i+2] - check[i]);
            ans = min(ans, dist);
        }

        return ans;
    } 

    int minimumDistance(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> store;

        for(int num : nums)
            freq[num]++;

        for(auto f : freq)
        {
            if(f.second >= 3)   
            {
                int value = f.first;
                store.push_back(dischecker(nums, value));
            }
        }

        if(store.empty()) return -1;

        return *min_element(store.begin(), store.end());
    }
};