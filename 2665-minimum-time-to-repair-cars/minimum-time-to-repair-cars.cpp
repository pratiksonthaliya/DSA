class Solution {
private:
    bool isValid(long long t, vector<int>& ranks, int cars){
        long long ct = 0;
        for(int i=0; i<ranks.size(); i++){
            ct += sqrt(t/ranks[i]);
            if(ct >= cars){
                return true;
            }
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long st = 0;
        long long en = 1e18;

        long long ans = -1;
        while(st <= en){
            long long mid = st + (en - st) / 2;
            if(isValid(mid, ranks, cars)){
                ans = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
};