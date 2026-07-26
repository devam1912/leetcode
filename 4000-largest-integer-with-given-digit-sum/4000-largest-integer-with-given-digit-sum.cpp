class Solution {
public:
    int largestInteger(int n, int s) {
        if (s == 0) return 0;

        int end;
        int ans = INT_MIN;
        string st = "";

        for (int i = 0; i < n; i++) {
            st += "9";
        }

        end = stoi(st);

        for (int i = 0; i <= end; i++) {
            int num = i;
            int sum = 0;

            while (num) {
                int rem = num % 10;
                sum += rem;
                num /= 10;
            }

            if (sum == s)
                ans = i;
        }

        if (ans == INT_MIN) return -1;
        return ans;
    }
};