// Count Nodes Equal to Average of Subtree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<int, int> sum(TreeNode* r, int& c){
        if(!r)
        return {0, 0};

        auto lp=sum(r->left, c), rp = sum(r->right, c);
        int avg = (lp.first+rp.first+r->val) / (lp.second+rp.second+1);
        if(avg==r->val)
        c++;
        return {(lp.first+rp.first+r->val), (lp.second+rp.second+1)};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int c=0;
        sum(root, c);
        return c;
    }
};