class Solution {
private:
    bool isSymmetric(int num){
        int n = num;
        int len = 0;
        while(n){
            n/=10;
            len++;
        }

        if(len%2 == 1) return false;

        int ds1 = 0, ds2 = 0;
        for(int i=0; i<len; i++){
            if(i < len/2) ds1 += (num%10);
            else ds2 += (num%10);
            num/=10;
        }

        return ds1 == ds2;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ct = 0;
        for(int num = low; num <= high; num++){
            if(isSymmetric(num)){
                ct++;
            }
        }

        return ct;
    }
};