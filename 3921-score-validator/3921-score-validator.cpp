class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n = events.size();
        vector<int>ans;
        int ts=0;
        int tc=0;
        for(int i=0;i<n;i++)
        {
            if(events[i]=="1") ts++;
            if(events[i]=="2") ts+=2;
            if(events[i]=="3") ts+=3;
            if(events[i]=="4") ts+=4;
            if(events[i]=="5") ts+=5;
            if(events[i]=="6") ts+=6;
            if(events[i]=="W") tc++;
            if(events[i]=="WD") ts++;
            if(events[i]=="NB") ts++;
            if(tc==10) break;
        }
        ans.push_back(ts);
        ans.push_back(tc);
        return ans;
    }
};