/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* h)
    {
        int count=0;
        while(h!=NULL)
        {
            count++;
            h=h->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //If no node or only one node is present
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        
        //Calculate the length of node & check with k
        int length=getLength(head);
        if(k>length) return head;
        
        
        int count=0;
        ListNode* curr=head;
        ListNode*prev=NULL;
        ListNode* next=curr->next;
        
        //To reverse till kth node
        while(curr!=NULL&&count<k)
        {
            count++;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
       
        //Recursive call to rerse further nodes
        head->next=reverseKGroup(curr,k);
        
        //return reversed link list
         return prev;
    }
};