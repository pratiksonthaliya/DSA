class Solution {
public:
    // long long count(int n, int m){

    //     long long ans = 0;

    //     for(int x=n; x>=1; x-=2){
    //         ans += min(x, m-1);
    //     }

    //     for(int y=m-2; y>=1; y-=2){
    //         ans += min(n-1, y);
    //     }

    //     return ans;

    //     // 3, 2
    //     // {3, 2} -> {2, 1}
    //     // {1, 2}

    //     // 5, 7

    //     // {5, 7}, {3, 7}, {1, 7}
    //     // {5, 5}, {5, 3}, {5, 1}

    //     // {5, 7} -> {4, 6}, {3, 5}, {2, 4}, {1, 3}

    // }
    long long flowerGame(int n, int m) {
        long long oddN = (n + 1) / 2;
        long long evenN = n / 2;
        long long oddM = (m + 1) / 2;
        long long evenM = m / 2;

        return oddN * evenM + evenN * oddM;
    }
};