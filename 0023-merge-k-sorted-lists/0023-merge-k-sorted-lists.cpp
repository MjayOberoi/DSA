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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(auto i:lists)
        {
            while(i!=NULL)
            {
                v.push_back(i->val);
                i=i->next;
            }
        }
        ListNode* head=new ListNode;
        ListNode* temp=head;
        sort(v.begin(),v.end());
        for(auto i:v)
        {
            ListNode* st=new ListNode(i);
            temp->next=st;
            temp=temp->next;
        }
        return head->next;
    }
};