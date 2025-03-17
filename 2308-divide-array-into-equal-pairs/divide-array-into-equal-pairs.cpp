class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> isOdd(501, false); 
        for(int &num : nums){
            isOdd[num] = !(isOdd[num]);
        }

        for(int i=0; i<501; i++){
            if(isOdd[i] == 1){
                return false;
            }
        }

        return true;
    }
};