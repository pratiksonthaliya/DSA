class Solution {
public:
    int binaryGap(int n) {
        if((n&(n-1)) == 0) return 0;

        int ans = 0, prev_1 = -1;
        for(int i=0; i<31; i++){
            if(n&(1<<i)){
                if(prev_1 >= 0) 
                    ans = max(ans, i - prev_1);
                prev_1 = i;
            } 
        }
        return ans;
    }
};