class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
    
        sort(events.begin(), events.end()); // by start
        multiset<int> mst; // by end

        int maxDay = 0;
        for(auto &e : events){
            maxDay = max(maxDay, e[1]);
        }

        int ans = 0, i = 0;
        for(int day = 1; day <= maxDay; day++){

            while(i < n && events[i][0] == day){
                mst.insert(events[i][1]);
                i++;
            }

            while(!mst.empty() && *mst.begin() < day){
                mst.erase(mst.begin());
            }

            if(mst.size() > 0){
                ans++;
                mst.erase(mst.begin());
            }
        }
        return ans;
    }
};