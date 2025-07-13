class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i=0, n = players.size(), m = trainers.size();

        int ans = 0;
        for(int j=0; i < n && j < m; j++){
            if(players[i] <= trainers[j]){
                i++; 
                ans++;
            }
        }

        return ans;
    }
};