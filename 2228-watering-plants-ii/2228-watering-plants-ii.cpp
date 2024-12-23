class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int left = 0;
        int right = plants.size() - 1;
        int waterA = capacityA;
        int waterB = capacityB;
        int count = 0;

        while (left <= right) {
            
            if (left == right) {
                if (waterA >= waterB) {
                    if (waterA < plants[left]) {
                        count++; 
                    }
                } else {
                    if (waterB < plants[right]) {
                        count++; 
                    }
                }
                break; 
            }

           
            if (waterA < plants[left]) {
                count++;
                waterA = capacityA;
            }
            waterA -= plants[left];
            left++;

            if (waterB < plants[right]) {
                count++;
                waterB = capacityB;
            }
            waterB -= plants[right];
            right--;
        }

        return count;
    }
};
