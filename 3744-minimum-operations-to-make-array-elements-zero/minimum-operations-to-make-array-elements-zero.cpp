class Solution {
private:
    long long findOps(long long n){
        if (n < 0) return 0;
        long long ops = 0, prev = 0, k = 1;

        while(prev < n){

            long long next = (1LL<<k) * (1LL<<k);  // 4^k
            // long long prev = (1LL<,(k-1)) * (1Ll<<(k-1)) // 4^(k-1)

            ops += (min(next-1, n) - prev) * k;
            prev = next-1;
            k++;
        }
        return ops;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        // 3 * 1 -> 12 * 2 -> 48 * 3 -> 

        for(int i=0; i<17; i++){
            cout << i << " " << findOps(i) << endl;
        }

        long long ans = 0;
        for(auto &q : queries){
            ans += (findOps(q[1]) - findOps(q[0] - 1) + 1)/2;
        } 

        return ans;
    }
};

// 0 -> 1
// 1 -> 1 -> 1
// 2 -> 1 -> 2
// 3 -> 1 -> 2

// 4 -> 2 -> 4
// 5 -> 2 -> 4
// 6 -> 2 -> 6
// 7 -> 2 -> 6

// 8 -> 2 -> 8
// 9 -> 2 -> 8
// 10 -> 2 -> 10
// 11 -> 2 -> 10

// 12 -> 2 -> 12
// 13 -> 2 -> 12
// 14 -> 2 -> 14
// 15 -> 2 -> 14

// num/4 -> a
// (a) * (a+1) / 2 * 4 + (num + 1)%4 * (a+1) 