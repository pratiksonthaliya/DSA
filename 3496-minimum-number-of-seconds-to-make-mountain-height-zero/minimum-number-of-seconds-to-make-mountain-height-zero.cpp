class Solution {

    // 1 -> 1
    // 3 -> 2
    // 6 -> 3
    // 10 -> 4
    // 15 -> 5
    // 21 -> 6
    // 21 = (x) * (x+1) / 2;

    // 0 = x^2 + x - 42

    // x = -1 + sqrt(1 + 4 * 2*k) / 2

private:
    bool isValid(long long t, int mountainHeight, vector<int>& workerTimes){

        for(int time : workerTimes){

            long long k = t / time;

            int x = (sqrt(1+ 8*k) - 1) / 2;

            mountainHeight -= x;
            if(mountainHeight <= 0) return 1;
        }
        return (mountainHeight <= 0);
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long st = 0, en = 1e18 + 7;

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