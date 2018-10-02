/**
61. Rotate List

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

*/


/*
my init solution:
用前后两个指针：
前指针领先k个位置。
当前指针当next为null：
1. 则把前指针当next指向head， 
2. 把临时指针dummy的next指向behind的next
3. 把behind的next指向null
4. 把head指向dummy的next

k>list 长度时， 取模获取真正的移动offset。

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null)
            return head;
        //three position identifiers: head, behind, prior
        ListNode dummy = new ListNode(0);
        ListNode behind = head;
        ListNode prior = head;
        
        ListNode temp = head;
        int listLen = 0;
        while(temp != null){
            listLen++;
            temp = temp.next;
        }
        
        if(listLen == 0)
            return head;
        
        int realMove = k%listLen;
        if(realMove == 0)
            return head;
        
        // prior go k steps first
        while(realMove>0){
            prior = prior.next;
            realMove--;
        }
        
        
        //
        while(prior.next != null){
            prior = prior.next;
            behind = behind.next;
        }
        
        //prior.next == null
        dummy.next = behind.next;
        prior.next = head;
        behind.next = null;
        head = dummy.next;
        return head;
        
    }
}
