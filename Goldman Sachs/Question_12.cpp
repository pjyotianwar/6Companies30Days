// All Elements in Two Binary Search Trees

class Solution {
    void dfs(TreeNode* root, vector<int>& t){
        if(!root) return;
        dfs(root->left, t);
        t.push_back(root->val);
        dfs(root->right,t);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1;
        vector<int> t2;
        vector<int> res;
        dfs(root1, t1);
        dfs(root2, t2);
        int i=0, j=0;
        while (i<t1.size() || j<t2.size()){
            if(i<t1.size() && j<t2.size() && t1[i]<=t2[j] || j==t2.size()) {
                res.push_back(t1[i]);
                i++;
            }
            else {
                res.push_back(t2[j]);
                j++;
            }
        }
        return res;
    }
};