class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {   
        sort(meetings.begin(), meetings.end());

        vector<int> meetingsHeld(n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> used; // {end_time, room_no}
        
        priority_queue<long long, vector<long long>, greater<>> unused; 
        for(long long i=0; i<n; i++) unused.push(i);

        for(auto meeting : meetings){
            long long st_t = meeting[0], en_t = meeting[1];

            while(!used.empty() && used.top().first <= st_t){ // jo empty ho rha h usko empty krdo
                unused.push(used.top().second);
                used.pop();
            }

            // unused hai
            if(!unused.empty()){
                long long room_no = unused.top();
                used.push({en_t, room_no});
                unused.pop();
                meetingsHeld[room_no]++;
            } else {
                long long time = used.top().first;
                long long room_no = used.top().second;
                used.pop();

                used.push({en_t - st_t + time, room_no});
                meetingsHeld[room_no]++;
            }
        }

        int ans = 0, max_val = 0;
        for(int i=0; i<n; i++){
            //cout << meetingsHeld[i] << " ";
            if(meetingsHeld[i] > max_val){
                ans = max(ans, i);
                max_val = meetingsHeld[i];
            }
        }
        return ans;
    }
};