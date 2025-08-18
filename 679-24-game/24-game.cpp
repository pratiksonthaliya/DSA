class Solution {
private:
    const double EPS = 1e-4;
    bool dfs(vector<double>& nums){
        if(nums.size() == 1){
            return fabs(nums[0] - 24.0) < EPS;
        }

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){

                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                
                double a = nums[i], b = nums[j];
                vector<double> res = {a+b, a-b, b-a, a*b};
                if(fabs(b) > EPS) res.push_back(a/b);
                if(fabs(a) > EPS) res.push_back(b/a);

                for(double val : res){
                    next.push_back(val);
                    if(dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
};