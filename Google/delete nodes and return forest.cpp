/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the result in any order.

 

Example 1:



Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
*/
class Solution {
private:
    bool helper(vector<TreeNode*>& res, TreeNode* & root, unordered_set<int>& set)
    {
        
        if(root == nullptr)
            return false;
        
        bool del = set.find(root->val) != set.end();
        bool l = helper(res, root->left, set);
        bool r = helper(res, root->right, set);
        
        if(del)
        {
           
            if(!l && root->left)
                res.push_back(root->left);
            if(!r && root->right)
                res.push_back(root->right);
            root = nullptr;
        }
        return del;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        
        vector<TreeNode*> res;
        
        
        bool r = helper(res, root, set);
        if( !r && root)
            res.push_back(root);
        return res;
    }
};
