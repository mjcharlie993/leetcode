//Source : https://leetcode.com/problems/reverse-linked-list/
//Author : Mao Jiachen
//Date   : 2016/11/29

/***************************************************************************************
 *
 * #1
 * Approach: Iteration 
 * Assume that we have linked list 1 -> 2 ->3 -> X, 
 * we would like to change it to X -> 1 -> 2 -> 3.
 *
 * While you are traversing the list, change the current node`s next point to its 
 * previous element. Since a node does not have point to its previous node,
 * you must store its previous element beforehand. You also need another pointer to store
 * the next node before changing the point.
 * Do not forget to return new head pointer at the end!
 * 
 *
 * #2
 * Approach: Recursion
 * The recursive version is slightly trickier and the key is to work backwards.
 * Assume that the rest of the list had already been reversed, now how do I reverse 
 * the front part?
 * Let`s assume the list is: n(1) -> ... -> n(k-1) -> n(k) -> n(k+1) -> ... ->n(m) ->X
 * Assume from node n(k+1) to n(m) had been reversed and you are at node n(k).
 * n1 -> ... -> n(k-1) -> n(k) -> n(k+1) <- ... <- n(m)
 * We want n(k+1)`s next node to point to n(k).
 * So,
 * n(k)->next->next = n(k).
 * Be very careful that n1`s next must point to X. 
 * If you forget about this, your linked list has a cycle in it.
 * This bug could be caught if you test your code with a linked list of size 2.
 *
 ***************************************************************************************/
 
 //Iteration
 class Solution { 
 public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while (head != nullptr) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};
 
//Recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};
