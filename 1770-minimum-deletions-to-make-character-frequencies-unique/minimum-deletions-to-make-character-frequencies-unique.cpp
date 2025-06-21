class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char ch : s) mp[ch]++;

        map<int, int> freq;
        for(auto x : mp) freq[x.second]++;

        int ans = 0;
        for(auto x : freq){

            int num = x.first, f = x.second;
            while(f > 1 && num-1 > 0){
                if(freq.find(num-1) == freq.end()){
                    freq[num-1]++;
                    f--;
                    ans += (x.first - (num-1));
                }
                num--;
            }

            if(f > 1) ans += (x.first) * (f-1);
        }

        return ans;
    }
};