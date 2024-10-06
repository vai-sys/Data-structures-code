

string toBinaryString(int num) {
    string binary = "";
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    return binary;
}

bool compareBinary(int a, int b) {
    string binA = toBinaryString(a);
    string binB = toBinaryString(b);
    return binA + binB > binB + binA;
}

class Solution {
public:
    int maxGoodNumber(std::vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareBinary);
        string result = "";
        for (int num : nums) {
            result += toBinaryString(num);
        }
        return stoi(result, 0, 2); 
    }
};
