class Solution {
public:

    long long solve(vector<int>& Astart, vector<int>& Adur, vector<int>& Bstart, vector<int>& Bdur)
    {
        int m = Bstart.size();

        vector<pair<int,int>> rides;

        for(int i=0;i<m;i++)
            rides.push_back({Bstart[i], Bdur[i]});

        sort(rides.begin(), rides.end());

        vector<int> starts(m);
        vector<long long> pref(m);
        vector<long long> suff(m);

        for(int i=0;i<m;i++)
            starts[i] = rides[i].first;

        pref[0] = rides[0].second;

        for(int i=1;i<m;i++)
            pref[i] = min(pref[i-1], (long long)rides[i].second);

        suff[m-1] =
            (long long)rides[m-1].first + rides[m-1].second;

        for(int i=m-2;i>=0;i--)
        {
            long long cur =
                (long long)rides[i].first + rides[i].second;

            suff[i] = min(suff[i+1], cur);
        }

        long long ans = LLONG_MAX;

        for(int i=0;i<Astart.size();i++)
        {
            long long T = (long long)Astart[i] +Adur[i];

            int pos =upper_bound(starts.begin(), starts.end(),T) - starts.begin();

            if(pos > 0)
                ans = min(ans,T + pref[pos-1]);

            if(pos < m)
                ans = min(ans, suff[pos]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration)
    {
        long long ans = LLONG_MAX;

        ans = min(ans, solve(landStartTime, landDuration, waterStartTime, waterDuration));

        ans = min(ans, solve(waterStartTime, waterDuration, landStartTime,landDuration));

        return (int)ans;
    }
};