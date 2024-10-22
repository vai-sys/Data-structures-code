
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL) return -1;
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> ans;
        while (!q.empty()) {
            int levelsize = q.size();
            long long levelsum = 0;
            for (int i = 0; i < levelsize; i++) {
                 
                auto currentNode = q.front();
                q.pop();

                levelsum += currentNode->val;
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }
            ans.push_back(levelsum);
        }
         
         if(ans.size() <k )return -1;

        sort(ans.begin(), ans.end(), greater<long long>());
         return ans[k - 1];
    }
};