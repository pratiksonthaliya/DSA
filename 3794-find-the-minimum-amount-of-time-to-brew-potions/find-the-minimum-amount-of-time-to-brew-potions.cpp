#define ll long long
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        long long totSkill = accumulate(skill.begin(), skill.end(), 0l);
        
        vector<long long> startTime(n, 0);
        long long time = 0;

        for(int i=0; i<m; i++){ // for each mana
            time = startTime[0];
            for(int j=0; j<n; j++) {
                time += skill[j] * 1LL * mana[i];
                startTime[j] = time;
            }

            // cout << time << endl;
            
            if(i == m-1) continue;

            long long currTime = time;
            for(int j=n-1; j>=0; j--){
                currTime -= mana[i+1] * 1LL * skill[j];
                // cout << startTime[j] << " " << currTime << endl;
                startTime[j] = max(currTime, startTime[j]);
                currTime = startTime[j];
            }

            // cout << currTime << " " << startTime[0] << endl;
        }

        return time;
    }
};