class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int playerind=0;
        int trainerind=0;
        int count=0;
        while(playerind<players.size() && trainerind<trainers.size())
        {
            if(players[playerind]<=trainers[trainerind])
            {
                playerind++;
                trainerind++;
                count++;
            }
            else if(players[playerind]>trainers[trainerind])
            {
                trainerind++;
            }
        }
        return count;
    }
};