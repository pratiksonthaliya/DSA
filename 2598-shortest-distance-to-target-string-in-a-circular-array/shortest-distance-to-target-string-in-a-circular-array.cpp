class Solution {
public:
    int closestTarget(vector<string>& words, string target, int stIdx) {
        int n = words.size();
        set<int> idxs;
        for(int i=0; i<n; i++){
            if(words[i] == target) idxs.insert(i);
        }

        if(idxs.size() == 0) return -1;

        int ans = INT_MAX;
        for(int tarIdx : idxs){
            int k = abs(stIdx - tarIdx);
            ans = min(ans, min(k, n-k));
        }
        return ans;
    }
};