class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       
        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
          
            auto [freq1, ch1] = pq.top(); 
            pq.pop();
            
            
            if (result.size() >= 2 && result[result.size() - 1] == ch1 && result[result.size() - 2] == ch1) {
                if (pq.empty()) break; 
                auto [freq2, ch2] = pq.top();
                pq.pop();
                
               
                result += ch2;
                freq2--;
                
                
                if (freq2 > 0) pq.push({freq2, ch2});
                
              
                pq.push({freq1, ch1});
            } else {
               
                result += ch1;
                freq1--;
                
              
                if (freq1 > 0) pq.push({freq1, ch1});
            }
        }
        
        return result;
    }
};
