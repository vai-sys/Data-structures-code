// class Solution {
// public:
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>occupied;
//         priority_queue<int,vector<int>,greater<int>>freeChair;
//         int chair=0;
//         sort(times.begin(),times.end());
//         int targetFriendArr=times[targetFriend][0];
//         int n=times.size();

//         for(int i=0;i<n;i++){
//             int arrival=times[i][0];
//             int departure=times[i][1];
//             while(!occupied.empty() && occupied.top().first <= arrival){
//                 freeChair.push(occupied.top().second);
//                 occupied.pop();
//             }

//             if(freeChair.empty()){
//                 occupied.push({departure,chair});

//                 if(arrival==targetFriendArr){
//                     return i;

//                 }
//                 chair++;
//             }
//             else{
//                 int leastChairAvail=freeChair.top();
//                 if(arrival==targetFriendArr){
//                     return leastChairAvail;
//                 }
//                 occupied.push({departure,leastChairAvail});

//             }
//         }
//         return -1;
//     }
// };



class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied; 
        priority_queue<int, vector<int>, greater<int>> freeChair;
        int chair = 0;
        int n = times.size();
        
    
        vector<pair<vector<int>, int>> timesWithIndex;
        for (int i = 0; i < n; ++i) {
            timesWithIndex.push_back({times[i], i});
        }
        
       
        sort(timesWithIndex.begin(), timesWithIndex.end(), [](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
            return a.first[0] < b.first[0];
        });
        
        
        int targetFriendArr = times[targetFriend][0];

        for (int i = 0; i < n; i++) {
            int arrival = timesWithIndex[i].first[0];
            int departure = timesWithIndex[i].first[1];
            int friendIndex = timesWithIndex[i].second;
            
           
            while (!occupied.empty() && occupied.top().first <= arrival) {
                freeChair.push(occupied.top().second); 
                occupied.pop();
            }

            int assignedChair;
            if (freeChair.empty()) {
                assignedChair = chair++; 
            } else {
                assignedChair = freeChair.top(); 
                freeChair.pop();
            }

           
            occupied.push({departure, assignedChair});


            if (friendIndex == targetFriend) {
                return assignedChair;
            }
        }

        return -1;
    }
};
