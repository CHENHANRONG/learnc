```Java
/**
 * Definition for ListNode
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
 ```


## 查找List的中点
```Java
ListNode slow = head, fast = head;
      
while (fast.next!=null && fast.next.next!=null) {
  slow = slow.next;
  fast = fast.next.next;
}

ListNode mid = slow;

```


## Reverse the list:
```Java
ListNode reverse(ListNode head) {
    ListNode prev = null, curr = head, next = null;

    while (curr != null) {
      next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
}

/**
* @param head: n
* @return: The new head of reversed linked list.
* 思路：头部插入
*/
public ListNode reverse(ListNode head) {

  ListNode newhead = null;
  while(head != null){
      ListNode temp = head.next;  // temp指向链表除head之外的头node

      head.next = newhead;  // header's next point to head head
      newhead = head;  // new head point to first element which is temp

      head = temp;  //head point to head's next
  }

  return newhead;
}
```

## Merge two lists:
```Java

/**
* @param l1: ListNode l1 is the head of the linked list
* @param l2: ListNode l2 is the head of the linked list
* @return: ListNode head of linked list
*/
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
  // write your code here
  if(l1 == null) return l2;
  if(l2 == null) return l1;


  ListNode head = null;
  ListNode tail = new ListNode(0);
  if(l1.val < l2.val)
      head = l1;
  else
      head = l2;
  //    
  while(l1 != null && l2 != null){
      if(l1.val < l2.val){ 
          //进行尾部插入
          ListNode temp = l1.next;
          tail.next = l1;
          tail = l1;
          // tail.next = null;
          l1 = temp;
      }else{
          //进行尾部插入
          ListNode temp = l2.next;
          tail.next = l2;
          tail = l2;
          // tail.next = null;
          l2 = temp;
      }

  }

  if(l1 == null) tail.next = l2;
  if(l2 == null) tail.next = l1;


  return head;
}

```


##  Delete Node in a Linked List
```Java
/*
* @param node: the node in the list should be deletedt
* @return: nothing
*/
public void deleteNode(ListNode node) {
  node.val = node.next.val;
  node.next = node.next.next;
}
 ```
