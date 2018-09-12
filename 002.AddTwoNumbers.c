/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    
    struct ListNode *head      = NULL;
    struct ListNode *current   = head = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *pre       = NULL;

    int carry = 0 ;
    int sum   = 0 ;
    
    while (true){
        
        if(pre != NULL){
            current   = (struct ListNode *) malloc(sizeof(struct ListNode));
            pre->next = current ;
        }

        sum           = ((node1!=NULL)?node1->val:0) + ((node2!=NULL)?node2->val:0) + carry; 
        carry         = sum / 10; 
        current->val  = sum % 10;
        current->next = NULL;

        pre   = current ;
        node1 = (node1!=NULL)?node1->next:NULL;
        node2 = (node2!=NULL)?node2->next:NULL;
        
        if(node1 == NULL && node2 ==NULL ){
            if(carry==1){
                current   = (struct ListNode *) malloc(sizeof(struct ListNode));
                current->val = 1 ;
                current->next = NULL ;
                pre->next = current ;
            }
            break;
        }   
    }
    return head;
}

