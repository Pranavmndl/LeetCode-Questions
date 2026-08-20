/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize=0;
    if(root==NULL)
     return NULL;
    int* result=(int*)malloc(sizeof(int)*2000);
    struct TreeNode** queue=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    int front=0;
    int rear=0;
    queue[rear++]=root;
    while(front<rear){
        int levelSize=rear-front;
        for(int i=0;i<levelSize;i++){
            struct TreeNode* current=queue[front++];
            if(i==levelSize-1){
                result[*returnSize]=current->val;
                (*returnSize)++;
            }
            if(current->left!=NULL)
              queue[rear++]=current->left;
            if(current->right!=NULL)
              queue[rear++]=current->right;
        }
    }
    free(queue);
    return result;
}