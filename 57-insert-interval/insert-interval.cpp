class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        int i=0;
        while(i < n && newInterval[0] > intervals[i][1]){ // non ovelapping
            ans.push_back(intervals[i]);
            i++;
        }

        while(i < n && newInterval[1] >= intervals[i][0]){ // overlapping case and merging
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            i++;
        }
        ans.push_back(newInterval);

        while(i < n){ // non ovelapping
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};