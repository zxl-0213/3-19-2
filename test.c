/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    int* array=(int*)malloc(sizeof(int)*10000);
    int i=0;
   
   if(head==NULL)
   {
        *returnSize=i;

        return array;
   }
   if(head->next==NULL)
   {
        *returnSize=i+1;

       array[i]=head->val;
       return array;
   }
    struct ListNode* n1=NULL;
    struct ListNode* n2=head;
    struct ListNode* n3=head->next;
    while(n2)
    {
        n2->next=n1;
        n1=n2;
        n2=n3;
        if(n3)
            n3=n3->next;
    }
    
    while(n1)
    {
        array[i]=n1->val;
        n1=n1->next;
        i++;
    }
    *returnSize=i;
    return array;
}