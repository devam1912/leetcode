class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size())
            return false;

        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s == goal)
                return true;

            // left rotate by 1
            reverse(s.begin(), s.begin() + 1);
            reverse(s.begin() + 1, s.end());
            reverse(s.begin(), s.end());
        }

        return false;
    }
};