class Solution {
public:
    int getRange(int num) {
        int largest = 0;
        int smallest = 9;

        while (num > 0) {
            int digit = num % 10;
            largest = max(largest, digit);
            smallest = min(smallest, digit);
            num /= 10;
        }

        return largest - smallest;
    }

    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;

        for (int i = 0; i < nums.size(); i++) {
            int range = getRange(nums[i]);
            maxRange = max(maxRange, range);
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int range = getRange(nums[i]);

            if (range == maxRange) {
                sum += nums[i];
            }
        }

        return sum;
    }
};