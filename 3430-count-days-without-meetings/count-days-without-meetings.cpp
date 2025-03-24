class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Merge
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);
        for(int i=1; i<meetings.size(); i++){
            if(meetings[i][0] > merged.back()[1]){
                merged.push_back(meetings[i]);
            } else {
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            }
        }
        
        int ans = 0;
        if(merged[0][0] > 1){
            ans += merged[0][0] - 1;
        }
        cout << ans << " ";
        for(int i=1; i<merged.size(); i++){
            if(merged[i][0] > merged[i-1][1]){
                ans += (merged[i][0] - merged[i-1][1] - 1);
            }
            cout << ans << " ";
        }
        if(merged[merged.size() - 1][1] < days){
            ans += (days - merged[merged.size() - 1][1]);
        }
        cout << ans << " ";

        return ans;
    }
};