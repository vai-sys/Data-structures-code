class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
     
        vector<int> minutes(timePoints.size());
   
        for (int i = 0; i < timePoints.size(); ++i) {
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3, 2));
            minutes[i] = h * 60 + m;
        }
        
        sort(minutes.begin(), minutes.end());
     
        int ans = INT_MAX;
        
       
        for (int i = 1; i < minutes.size(); ++i) {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }
        
      
        ans = min(ans, 24 * 60 - minutes.back() + minutes[0]);
        
        return ans;
    }
};
