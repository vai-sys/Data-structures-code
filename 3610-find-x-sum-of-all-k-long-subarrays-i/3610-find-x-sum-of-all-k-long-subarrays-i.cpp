#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int, int> freq;
        
      
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
   
        for (int i = 0; i < k; ++i) {
            freq[nums[i]]++;
        }
        
        for (const auto& pair : freq) {
            pq.push(pair);
        }
        
      
        int xSum = 0;
        vector<pair<int, int>> temp;
        for (int i = 0; i < x && !pq.empty(); ++i) {
            auto top = pq.top();
            pq.pop();
            xSum += top.first * top.second;
            temp.push_back(top);
        }
        answer.push_back(xSum);
        
      
        for (const auto& item : temp) {
            pq.push(item);
        }
        
     
        for (int i = k; i < n; ++i) {
           
            freq[nums[i-k]]--;
            if (freq[nums[i-k]] == 0) {
                freq.erase(nums[i-k]);
            }
            
            
            freq[nums[i]]++;
            
          
            while (!pq.empty()) {
                pq.pop();
            }
            for (const auto& pair : freq) {
                pq.push(pair);
            }
         
            xSum = 0;
            temp.clear();
            for (int j = 0; j < x && !pq.empty(); ++j) {
                auto top = pq.top();
                pq.pop();
                xSum += top.first * top.second;
                temp.push_back(top);
            }
            answer.push_back(xSum);
            
            
            for (const auto& item : temp) {
                pq.push(item);
            }
        }
        
        return answer;
    }
};