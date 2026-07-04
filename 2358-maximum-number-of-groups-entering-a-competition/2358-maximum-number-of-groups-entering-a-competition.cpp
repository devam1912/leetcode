class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();

        int groups = 0;
        int studentsNeeded = 0;

        while (studentsNeeded + (groups + 1) <= n) {
            groups++;
            studentsNeeded += groups;
        }

        return groups;
    }
};