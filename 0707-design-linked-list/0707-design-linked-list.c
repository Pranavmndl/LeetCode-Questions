typedef struct {
    struct ListNode *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;
    struct ListNode *temp = obj->head;
    while (index--) {
        temp = temp->next;
    }
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        struct ListNode *temp = obj->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    struct ListNode *temp = obj->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;
    if (index == 0) {
        struct ListNode *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        obj->size--;
        return;
    }
    struct ListNode *temp = obj->head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    struct ListNode *deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    struct ListNode *temp = obj->head;
    while (temp != NULL) {
        struct ListNode *next = temp->next;
        free(temp);
        temp = next;
    }
    free(obj);
}