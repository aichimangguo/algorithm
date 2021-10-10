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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if(l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        else if(l1 == nullptr && l2 !=nullptr)
        {
            return l2;
        }
        else if(l1 != nullptr && l2 == nullptr)
        {
            return l1;
        }

        ListNode* pHead = nullptr;
        ListNode* pListNode = nullptr;
        while(l1 != nullptr && l2 != nullptr)
        {
           if(l1->val <= l2->val)
           {
               if(pHead == nullptr)
               {
                   pHead = l1;
                   pListNode = pHead;
                   l1 = l1->next;
                   continue;
               }

               pListNode->next = l1;
               pListNode = l1;
               l1 = l1->next;
           }
           else
           {
               if(pHead == nullptr)
               {
                  pHead = l2;
                  pListNode = pHead;
                  l2 = l2->next;
                  continue;
               }

               pListNode->next = l2;
               pListNode = l2;
               l2 = l2->next;
           }
        }

        if(l2 != nullptr)
        {
            pListNode->next = l2;
        }
        else
        {
            pListNode->next = l1;
        }

        return pHead;
    }
};
