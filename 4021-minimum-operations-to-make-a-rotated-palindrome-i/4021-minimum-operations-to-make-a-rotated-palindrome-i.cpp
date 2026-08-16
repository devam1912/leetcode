class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int ans = INT_MAX;

        for (int rot = 0; rot < n; rot++) {

            string temp = s;

            reverse(temp.begin(), temp.begin() + rot);
            reverse(temp.begin() + rot, temp.end());
            reverse(temp.begin(), temp.end());

            int left = 0;
            int right = n - 1;

            int cost = rot;   // number of left rotations

            while (left < right) {

                int a = temp[left] - 'a';
                int b = temp[right] - 'a';

                // increment left character until it becomes right
                int cost1 = (b - a + 26) % 26;

                // increment right character until it becomes left
                int cost2 = (a - b + 26) % 26;

                cost += min(cost1, cost2);

                left++;
                right--;
            }

            ans = min(ans, cost);
        }

        return ans;
    }
};