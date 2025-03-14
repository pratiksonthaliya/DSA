class Solution {
private:
    bool isValid(int num, vector<int>& candies, long long k){

        long long ct = 0;
        for(int candy : candies){
            ct += 1ll*(candy/num);
        }

        return ct >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int st = 1, en = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while(st <= en){
            int mid = st + (en - st) / 2;
            if(isValid(mid, candies, k)){
                ans = mid;
                st = mid + 1;
            } else {
                en = mid - 1;
            }
        }

        return ans;
    }
};