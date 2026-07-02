class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> st;

        int j = 0;
        int m = target.size();

        for (int i = 1; i <= n; i++) {
            st.push(i);
            ans.push_back("Push");

            if (j < m && i == target[j]) {
                j++;
            } else {
                ans.push_back("Pop");
                st.pop();
            }

            if (j == m)
                return ans;
        }

        return ans;
    }
};