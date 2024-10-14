class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;  
        priority_queue<int> pq;

       
        for (int num : nums) {
            pq.push(num);
        }

       
        while (k > 0) {
            int num = pq.top();  
            pq.pop();  

            score += num;  
            num = ceil((double)num / 3); 

            pq.push(num);  
            k--;  
        }

        return score;  
    }
};
