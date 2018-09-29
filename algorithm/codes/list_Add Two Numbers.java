/*

2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/


/*
更简练都表述
*/
public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummyHead = new ListNode(0);
    ListNode p = l1, q = l2, curr = dummyHead;
    int carry = 0;
    while (p != null || q != null) {
        int x = (p != null) ? p.val : 0;
        int y = (q != null) ? q.val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr.next = new ListNode(sum % 10);
        curr = curr.next;
        if (p != null) p = p.next;
        if (q != null) q = q.next;
    }
    if (carry > 0) {
        curr.next = new ListNode(carry);
    }
    return dummyHead.next;
}


/*
My init solution:
思路： 从第一位（个位）开始，遍历每个节点
如果节点不为null， 获取节点都val； 如果节点为null， 返回0
每个节点都值为 l1.val+l2.val+addToNext（前面计算都进位）%10 ； 同时计算当前位都进位值为：

            addToNext = 0;  //reset add to next;
            while(curSum >= 10 ){
                curSum /= 10;
                addToNext++;
            }
            
 */
 
 public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null)
            return null;
        
       
        int addToNext = 0;  //add to next
        
        int l1val = 0;
        if(l1 != null)
            l1val = l1.val;

        int l2val = 0;
        if(l2 != null)
            l2val = l2.val;

        int curSum = l1val+l2val+addToNext;
        int curVal = curSum % 10;  //current position val
        ListNode resultHeader = new ListNode(curVal);  //init header
        ListNode lastTempPos = resultHeader;
        while(curSum >= 10 ){
            curSum /= 10;
            addToNext++;
        }
        
        while(l1.next != null || l2.next != null || addToNext>0){
            
            if(l1.next != null){
                l1 = l1.next;
                l1val = l1.val;
            }
            else{
                l1val = 0;
            }
            
            if(l2.next != null){
                l2 = l2.next;
                l2val = l2.val;
            }
            else{
                l2val = 0;
            }
            
            curSum = l1val+l2val+addToNext;
            curVal = curSum % 10;  //current position val
            
            //add new ListNode
            ListNode newNode = new ListNode(curVal);
            // link the new node into result list
            lastTempPos.next = newNode;  
            lastTempPos = newNode;    
            
            //calculate the addToNext val
            addToNext = 0;  //reset add to next;
            while(curSum >= 10 ){
                curSum /= 10;
                addToNext++;
            }
            
        }
        
        return resultHeader;
    }
