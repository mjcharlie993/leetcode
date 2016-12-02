//Source : https://leetcode.com/problems/delete-node-in-a-linked-list/
//Author : Mao Jiachen
//Date   : 2016/11/29

/***************************************************************************************
 *
 * Approach: Swap with Next Node
 * The usual way of deleting a node from a linked list is to modify the next pointer of 
 * the node before it, to point to the node after it.
 * 
 * Since we do not have access to the node before the one we want to delete,
 * we cannot modify the next point of that node in any way.
 * Instead, we have to replace the value of the node we want to delete with the value in
 * the node after it.
 *
 * Becaues we know that the node we want to delete is not the tail of the list,
 * we can guarantee that this approach is possible.
 *
 * Delete node 3
 *      -----------
 *      |         V
 * 1 -> 2 -> 3 -> 4 -> 5 -> X
 *
 * 1 -> 2 -> 4 -> 4 -> 5 -> X
 *           -----------
 *           |         V
 * 1 -> 2 -> 4 -> 4 -> 5 -> X
 *
 * 1 -> 2 -> 4 -> 5 -> X
 *
 *
 ***************************************************************************************/

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
    void deleteNode(ListNode* node) {
        if (node == nullptr)
            return;
        else {
            ListNode *temp = node->next;
            node->val = temp->val;
            node->next = temp->next;
        }
    }
};
