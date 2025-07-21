class Solution {
public:
    //TC - O(Nlog(N)) and SC - O(1)
    bool isValid(vector<int>& piles, int h, long long mid){
        long long hrsUsed = 0;
        for(int i=0; i<piles.size(); i++){
            hrsUsed = hrsUsed + (piles[i] + mid - 1)/mid;
            if(hrsUsed > h) return false;
        } 
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long st = 1;
        long long en = *max_element(piles.begin(), piles.end());
        long long ans = -1;
        
        while(st<=en){
            long long mid = st + (en-st)/2;
            if(isValid(piles, h, mid)){ //mid -> bananas he can eat in a hr
                ans = mid;
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
};


// 10^9 * 10^5

// st = 1 

//2banana/hr
// {2, 3, 4, 6} -> O(N) ~ 10^5

//3banana/hr
// {1, 2, 3, 4}

//4banana/hr
// {1, 1, 2, 3} -> kha liya

// en = max_ele = 10^9