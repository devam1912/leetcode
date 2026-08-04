class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        int n = tasks.size();
        vector<long long> pref(n);
        pref[0]=tasks[0];

        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+tasks[i];

        long long total=pref.back();

        long long workDone=0;

        vector<int> ans;

        for(long long shift:shifts)
        {
            workDone+=shift;

            if(workDone>=total)
            {
                ans.push_back(0);
                workDone=0;
            }
            else
            {
                int completed=
                upper_bound(pref.begin(),pref.end(),workDone)
                -pref.begin();

                ans.push_back(n-completed);
            }
        }

        return ans;
    }
};