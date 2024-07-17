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
public:
TreeNode* LCA(TreeNode* root, int s, int t){
    if(root==NULL || root->val==s || root->val==t) return root;

    TreeNode* left = LCA(root->left,s,t);
    TreeNode* right = LCA(root->right,s,t);

    if(left!=NULL && right!=NULL) return root;

    if(left!=NULL ) return left;
    else return right;
}
bool findPath(TreeNode* root, int val, string &path){
    if(root==NULL) return false;
    if(root->val==val) return true;

    path.push_back('L');
    if(findPath(root->left,val,path)) return true;
    path.pop_back();

    path.push_back('R');
    if(findPath(root->right,val,path)) return true;
    path.pop_back();

    return false;
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root,startValue,destValue);
        string lcaToSource = "";
        string lcaToDest = "";

        findPath(lca,startValue,lcaToSource);
        findPath(lca,destValue,lcaToDest);

        for(int i=0;i<lcaToSource.length();i++){
            lcaToSource[i]='U';
        }

        return lcaToSource+lcaToDest;

    }
};