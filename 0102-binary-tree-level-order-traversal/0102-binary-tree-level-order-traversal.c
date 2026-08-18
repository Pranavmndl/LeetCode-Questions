/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize=0;

    if (root==NULL){
        *returnColumnSizes=NULL;
        return NULL;
    }
    int** result=(int**)malloc(sizeof(int*)*2000);
    *returnColumnSizes=(int*)malloc(sizeof(int)*2000);
    struct TreeNode** queue=
        (struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    int front=0;
    int rear=0;

    queue[rear++]=root;
    while (front<rear){
        int levelSize=rear-front;
        result[*returnSize]=
            (int*)malloc(sizeof(int)*levelSize);
        (*returnColumnSizes)[*returnSize]=levelSize;
        for (int i=0;i<levelSize;i++){
            struct TreeNode* current=queue[front++];
            result[*returnSize][i]=current->val;
            if (current->left!=NULL)
                queue[rear++]=current->left;
            if (current->right!=NULL)
                queue[rear++]=current->right;
        }
        (*returnSize)++;
    }
    free(queue);
    return result;
}