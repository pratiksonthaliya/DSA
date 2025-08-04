class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 1, i = 0, j = 0, n = fruits.size();

        unordered_map<int, int> mp; // freq
        while(i < n && j < n){
            
            mp[fruits[j]]++;
            while(mp.size() > 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            if(mp.size() <= 2) ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};