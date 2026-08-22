/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(root==NULL)
     return;
    struct TreeNode* left=root->left;
    struct TreeNode* right=root->right;
    flatten(left);
    flatten(right);
    root->left=NULL;
    root->right=left;
    struct TreeNode* temp=root;
    while(temp->right !=NULL)
      temp=temp->right;
    temp->right=right;
    
}