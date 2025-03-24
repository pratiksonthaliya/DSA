class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        int ans = 0, latestEnd = 0;
        for(int i=0; i<meetings.size(); i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            
            if(start > latestEnd + 1){
                ans += (start - latestEnd - 1);
            }
            latestEnd = max(latestEnd, end);
        }

        ans += (days - latestEnd);
        return ans;
    }
};