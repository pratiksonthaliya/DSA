class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;

        if(startTime[0] > 0){
            freeTime.push_back(startTime[0]);
        }

        for(int i=1; i<startTime.size(); i++){
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }

        if(endTime[n-1] < eventTime){
            freeTime.push_back(eventTime - endTime[n-1]);
        }

        if(freeTime.size() <= k){
            return accumulate(freeTime.begin(), freeTime.end(), 0);
        }

        for(auto d : freeTime){
            cout << d << " ";
        }
        cout << endl;

        int m = freeTime.size(), ans = 0;
        vector<int> pre(m+1, 0);
        for(int i=0; i<m; i++){
            pre[i+1] = pre[i] + freeTime[i]; 
            if(i+1 > k) ans = max(ans, pre[i+1] - pre[i-k]);
            cout << pre[i+1] << " ";
        }

        return ans;
    }
};