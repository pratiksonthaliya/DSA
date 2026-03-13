class Solution {
private:
    bool isValid(long long t, int mountainHeight, vector<int>& workerTimes){

        for(int time : workerTimes){

            long long work = t / time;
            int x = (sqrt(1+ 8*work) - 1) / 2;

            mountainHeight -= x;
            if(mountainHeight <= 0) return 1;
        }
        return (mountainHeight <= 0);
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long st = 0, en = 1LL * (*max_element(workerTimes.begin(), workerTimes.end())) * mountainHeight * (mountainHeight + 1) / 2;

        long long ans = en;
        while(st <= en){
            long long mid = st + (en - st) / 2;
            if(isValid(mid, mountainHeight, workerTimes)){
                ans = min(ans, mid);
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};