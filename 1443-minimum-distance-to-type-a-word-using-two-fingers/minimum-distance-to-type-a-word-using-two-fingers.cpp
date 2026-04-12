class Solution {
private:
    string word;
    map<char, pair<int, int>> mp;
    map<string, int> dp;
    void getLoc(){
        char ch = 'A';
        for(int i=0; i<5; i++){
            for(int j=0; j<6; j++){
                mp[ch] = {i, j};
                if(ch == 'Z') return;
                ch += 1;
            }
        }
    }
    int solve(int i, int f1_x, int f1_y, int f2_x, int f2_y){
        if(i == word.size()) return 0;

        string key = to_string(i) + "_" + to_string(f1_x) + "_" + to_string(f1_y) + "_" 
                        + to_string(f2_x) + "_" + to_string(f2_y);
        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        int x = mp[word[i]].first, y = mp[word[i]].second;

        int ans1 = solve(i+1, x, y, f2_x, f2_y);
        if(f1_x != -1){
            ans1 += abs(f1_x - x) + abs(f1_y - y);
        }

        int ans2 = solve(i+1, f1_x, f1_y, x, y);
        if(f2_x != -1){
            ans2 += abs(f2_x - x) + abs(f2_y - y);
        }

        return dp[key] = min(ans1, ans2);
    }
public:
    int minimumDistance(string word) {
        this->word = word;
        getLoc();
        return solve(0, -1, -1, -1, -1);
    }
};