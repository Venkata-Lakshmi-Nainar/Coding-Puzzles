/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr = head , *qtr = head , *prev = head ;
        if ( !head ) {
            return head ;
        }
        while ( n-- && qtr ) {
            qtr = qtr -> next ;            
        }
        if ( !qtr ) {
            return head -> next ;
        }
        while ( qtr ) {
            qtr = qtr -> next ;
            prev = ptr ;
            ptr = ptr -> next ;            
        }
        prev -> next = ptr -> next ;
        return head ;
    }
};
