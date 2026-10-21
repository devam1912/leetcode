class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // already sorted
        if (is_sorted(s.begin(), s.end()))
            return 0;

        // length 2 impossible
        if (n == 2)
            return -1;

        char first = s[0];
        char last = s[n-1];

        char middleMin = *min_element(s.begin()+1, s.end()-1);
        char middleMax = *max_element(s.begin()+1, s.end()-1);

        // case where 1 operation is enough
        if (first <= last && (middleMin >= first || middleMax <= last))
            return 1;

        // special worst case needing 3
        if (last < middleMin && first > middleMax)
            return 3;

        // otherwise
        return 2;
    }
};