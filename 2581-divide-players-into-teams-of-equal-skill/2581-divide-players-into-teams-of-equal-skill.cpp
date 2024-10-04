class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int left = 0;
        int n = skill.size();
        int right = n - 1;

      
        sort(skill.begin(), skill.end());

        
        int totalTeamSkill = skill[left] + skill[right];
        
        long long chemistry = 0;  

        while (left < right) {
           
            if (skill[left] + skill[right] != totalTeamSkill) {
                return -1; 
            }

       
            chemistry += skill[left] * skill[right];

            left++;
            right--;
        }

     
        return chemistry;
    }
};
