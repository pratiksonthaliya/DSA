class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for(auto &x : mp){
            vector<int> &idxs = x.second;
            if(idxs.size() < 3) continue;
            for(int i=0; i<idxs.size(); i++){
                for(int j=i+1; j<idxs.size(); j++){
                    for(int k=j+1; k<idxs.size(); k++){
                        //cout << i << " " << j << " " << k << endl;
                        ans = min(ans, abs(idxs[i]-idxs[j]) + abs(idxs[j]-idxs[k]) + abs(idxs[k]-idxs[i]));
                    }
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};