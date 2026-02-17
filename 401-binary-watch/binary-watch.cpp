class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        map<int, set<int>> b_hr, b_min;
        for(int hr=0; hr<12; hr++){
            b_hr[__builtin_popcount(hr)].insert(hr);
        }

        for(int min=0; min<60; min++){
            b_min[__builtin_popcount(min)].insert(min);
        }

        vector<string> ans;
        for(int b=0; b<=turnedOn; b++){
            for(int hr : b_hr[b]){
                for(int min : b_min[turnedOn - b]){
                    ans.push_back(to_string(hr) + ":" + (min < 10 ? "0" : "") + to_string(min));
                }
            }
        }

        return ans;
    }
};