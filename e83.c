#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* head){
    
    if(!head) {
        return head;
    }

    struct ListNode *headNode = head;
    struct ListNode *prevNode = head;
    head = head->next;

    while(head) {

        if(! (head->val ^ prevNode->val)) {
            // delete what head currently poits to
            prevNode->next = head->next;
            // free(head);
        }
        else
            prevNode = head;
        head = head->next;
    }
    return headNode;
}

void print(struct ListNode* head) {
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    {
        int example1[] = {1, 1, 2};

        struct ListNode *ex1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *tmp = ex1;
        
        for(int i = 0; i < 2; i++) {
            tmp->val = example1[i];
            tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
        tmp->val = example1[2];
        tmp->next = NULL;

        print(ex1);
        print(deleteDuplicates(ex1));
    }


    {
        int example2[] = {1,1,2,3,3};

        struct ListNode *ex2 = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *tmp = ex2;
        
        for(int i = 0; i < 4; i++) {
            tmp->val = example2[i];
            tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
        tmp->val = example2[4];
        tmp->next = NULL;

        print(ex2);
        print(deleteDuplicates(ex2));
        
    }

    {
        int example3[] = {1,1,1,1,3};

        struct ListNode *ex3 = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *tmp = ex3;
        
        for(int i = 0; i < 4; i++) {
            tmp->val = example3[i];
            tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            tmp = tmp->next;
        }
        tmp->val = example3[4];
        tmp->next = NULL;

        print(ex3);
        print(deleteDuplicates(ex3));
        
    }



    return 0;
}
