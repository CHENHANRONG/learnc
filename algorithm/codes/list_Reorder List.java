/*

143. Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/



/*
my init solutiom:
用beind指向前部nodes
用ahead指向mid之后的后部指定倒序元素（通过从mid开始遍历n/2-i个来寻找）
用下面代码把前部第i个元素， 指向len-1-i个元素，并把len-1-i个元素指向第i+1个元素。
ListNode tt = behind.next;
behind.next = ahead;  // a[i] point to a[len-1-i]
ahead.next = tt; 
behind = tt;

结束于mid位置，mid分奇偶处理

*/
public void reorderList(ListNode head) {
        
        
        int n = 0;
        ListNode t = head;
        
        while(t!=null){
            n++;
            t = t.next;
        }
        
        if(n<=1)
            return;
        
        
        int mid = -1;
        if(n%2 == 0){  // 偶数
            mid = n/2-1;            
        }else{  //奇数
            mid = n/2;
        }
        
        ListNode midNode = head;
        int tmid = mid;
        while(tmid>0){
            midNode = midNode.next;
            tmid--;
        }
        
        ListNode behind = head;
        
        //find tail node
        for(int i=0;i<=mid;i++){
            
            if(i==mid && n%2!=0){  //奇数结束
                behind.next = null;
                return;
            }else if(i==mid && n%2==0){  //偶数结束
                behind.next.next = null;
                return;
            }
            
            ListNode ahead = midNode;
            int tail = n/2-i;
            while(tail>0){
                ahead = ahead.next;
                tail--;
            }
            
            
            ListNode tt = behind.next;
            behind.next = ahead;  // a[i] point to a[len-1-i]
            ahead.next = tt; 
            behind = tt;
            
            
        }
        
       
    }
