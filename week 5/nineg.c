#include <stdio.h>
#include <stdlib.h>

// Define a structure for the linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeLists(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode dummy;
    struct ListNode *current = &dummy;
    
    while (head1 && head2) {
        if (head1->val < head2->val) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    
    current->next = (head1 != NULL) ? head1 : head2;
    
    return dummy.next;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, m, i;
    // Read inputs
    scanf("%d %d", &n, &m);
    
    // Create linked lists
    struct ListNode *head_jake = NULL;
    struct ListNode *head_amy = NULL;
    struct ListNode *prev = NULL;
    
    // Create linked list for Jake's perps
    for (i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;
        if (!head_jake)
            head_jake = newNode;
        else
            prev->next = newNode;
        prev = newNode;
    }
    
    prev = NULL;
    // Create linked list for Amy's perps
    for (i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;
        if (!head_amy)
            head_amy = newNode;
        else
            prev->next = newNode;
        prev = newNode;
    }
    
    // Merge the two lists
    struct ListNode *mergedList = mergeLists(head_jake, head_amy);
    
    // Print the merged list
    printList(mergedList);
    
    // Free the memory
    struct ListNode* temp;
    while (mergedList) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }
    
    return 0;
}
