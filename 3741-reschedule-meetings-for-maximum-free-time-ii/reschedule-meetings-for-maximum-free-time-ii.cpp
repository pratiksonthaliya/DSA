class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        set<int> duration;

        int ans = 0;
        for(int i=0; i<n; i++){
            int d = endTime[i] - startTime[i];
            int f1 = (i == 0   ? startTime[0] : startTime[i] - endTime[i-1]);
            int f2 = (i == n-1 ? eventTime - endTime[n-1] : startTime[i+1] - endTime[i]);

            ans = max(ans, f1 + f2);

            if(duration.lower_bound(d) != duration.end()){
                ans = max(ans, f1 + f2 + d);
            }
            duration.insert(f1);
        }

        duration.clear();
        for(int i=n-1; i>=0; i--){
            int d = endTime[i] - startTime[i];
            int f1 = (i == 0   ? startTime[0] : startTime[i] - endTime[i-1]);
            int f2 = (i == n-1 ? eventTime - endTime[n-1] : startTime[i+1] - endTime[i]);
            
            if(duration.lower_bound(d) != duration.end()){
                ans = max(ans, f1 + f2 + d);
            }
            duration.insert(f2);
        }

        return ans;

        // vector<int> freeTime;
        // freeTime.push_back(startTime[0]);
        // for(int i=1; i<n; i++){
        //     if(startTime[i] > endTime[i-1]){
        //         freeTime.push_back(startTime[i] - endTime[i-1]);
        //     }
        // }
        // if(eventTime > endTime[n-1]) freeTime.push_back(eventTime - endTime[n-1]);


        // vector<int> pre()

        // for(int val : freeTime){
        //     cout << val << " ";
        // }
    }
};