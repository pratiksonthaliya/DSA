class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i=0, j=0, n = players.size(), m = trainers.size();

        int ans = 0;
        while(i < n && j < m){
            if(players[i] <= trainers[j]){
                i++; 
                ans++;
            }
            j++;
        }

        return ans;
    }
};