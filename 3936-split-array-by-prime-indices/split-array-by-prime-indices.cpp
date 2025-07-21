class Solution {
private:
    bool isPrime(long long a) { // SQRT(N)
        if (a==1 || a==0) return 0; 

        for (int i=2;i<=round(sqrt(a));++i) {
            if (a%i==0) return 0; 
        }
        return 1; 
    }
public:
    long long splitArray(vector<int>& nums) {
        long long psum = 0;
        for(int i=0; i<nums.size(); i++){
            if(isPrime(i)){
                psum += nums[i];
            } else {
                psum -= nums[i];
            }
        }

        return abs(psum);
    }
};

