class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {

        long long sumi = 0;
        long long sumd = 0;

        int n = nums.size();
        int i = 0;

        while (i < (n - 1) && nums[i] < nums[i + 1]) {
            sumi += nums[i];
            i++;
        }

        sumi += nums[i];
        sumd += nums[i];

        i++;


        while (i < (n - 1) && nums[i] > nums[i + 1]) {
            sumd += nums[i];
            i++;
        }

        sumd += nums[n - 1];

        if (sumi > sumd) return 0;

        if (sumd > sumi) return 1;

        return -1;
    }
};