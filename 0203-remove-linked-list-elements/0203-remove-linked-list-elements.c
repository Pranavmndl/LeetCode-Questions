/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while(head !=NULL && head->val==val){
        struct ListNode *temp=head;
        head=head->next;
        free(temp);
    }
    struct ListNode *current=head;
    struct ListNode *previous=NULL;

    while(current!=NULL){
        if(current ->val==val){
            previous->next=current->next;
            free(current);
            current=previous->next;
        }else{
            previous=current;
            current=current->next;
        }
    }
    return head;
}