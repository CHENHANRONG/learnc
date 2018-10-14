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
```

## Merge two lists:
```Java
void merge(ListNode l1, ListNode l2) {
  while (l1 != null) {
    ListNode n1 = l1.next, n2 = l2.next;
    l1.next = l2;

    if (n1 == null)
      break;

    l2.next = n1;
    l1 = n1;
    l2 = n2;
  }
}
```
