class Solution {
public:
    //TC - O(Nlog(N)) and SC - O(1)
    bool isValid(vector<int>& piles, int h, long long mid){
        long long hrsUsed = 0;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]%mid == 0){
                if(hrsUsed + (piles[i]/mid) > h){
                    return false;
                }
                hrsUsed = hrsUsed + (piles[i]/mid); 
            }
            
            else if(piles[i]%mid != 0){
                if(hrsUsed + (piles[i]/mid) + 1 > h){
                    return false;
                }
                hrsUsed++;
                hrsUsed = hrsUsed + (piles[i]/mid);
            }
            
        } 
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(), piles.end());
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

// 1 

//2banana/hr
// {2, 3, 4, 6}

//3banana/hr
// {1, 2, 3, 4}

//4banana/hr
// {1, 1, 2, 3} -> kha liya

