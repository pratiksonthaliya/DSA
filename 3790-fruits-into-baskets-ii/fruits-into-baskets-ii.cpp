class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ct = 0;
        for(int fruit : fruits){
            bool isPlaced = false;
            for(int i=0; i<baskets.size(); i++){
                if(baskets[i] >= fruit){
                    baskets[i] = 0;
                    isPlaced = true;
                    break;
                }
            }
            if(!isPlaced) ct++;
        }
        return ct;
    }
};