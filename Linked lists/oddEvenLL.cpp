//https://leetcode.com/problems/odd-even-linked-list/



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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head -> next) {
            return head;
        }

        ListNode *oddRoot = head, *evenRoot = head -> next;
        ListNode *linkNode = head -> next -> next, *curr = head;

        //Link every node to node -> next -> next
        while(linkNode) {
            ListNode *temp = curr -> next;
            curr -> next = linkNode;
            curr = temp;
            linkNode = linkNode -> next;
        }
        
        //Make the last node NULL
        curr -> next = linkNode;

        //Go to end of oddList and link to head of evenList
        ListNode *ptr = oddRoot;
        while(ptr -> next) ptr = ptr -> next;
        ptr -> next = evenRoot;

        
        return oddRoot;

    }
};
