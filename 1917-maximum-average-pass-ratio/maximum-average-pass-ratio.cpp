#define S pair<double, int> 
//diff, idx
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<S> pq;
        for(int i=0; i<classes.size(); i++){
            double avg  = 1.0*classes[i][0]/classes[i][1];
            double navg = 1.0*(classes[i][0]+1)/(classes[i][1]+1);
            pq.push({navg-avg, i});
        }

        while(extraStudents--){
            double diff = pq.top().first;
            int i     = pq.top().second;
            pq.pop();

            classes[i][0]++;
            classes[i][1]++;

            double avg  = 1.0*classes[i][0]/classes[i][1];
            double navg = 1.0*(classes[i][0]+1)/(classes[i][1]+1);
            pq.push({navg-avg, i});
        }

        double ans = 0;
        for(int i=0; i<classes.size(); i++){
            double avg  = 1.0*classes[i][0]/classes[i][1];
            ans += avg;
        }
        return ans/(classes.size());
    }
};