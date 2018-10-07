/*

38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

*/

/*better one*/
public String countAndSay(int n) {
	    	StringBuilder curr=new StringBuilder("1");
	    	StringBuilder prev;
	    	int count;
	    	char say;
	        for (int i=1;i<n;i++){
	        	prev=curr;
	 	        curr=new StringBuilder();       
	 	        count=1;
	 	        say=prev.charAt(0);
	 	        
	 	        for (int j=1,len=prev.length();j<len;j++){
	 	        	if (prev.charAt(j)!=say){
	 	        		curr.append(count).append(say);
	 	        		count=1;
	 	        		say=prev.charAt(j);
	 	        	}
	 	        	else count++;
	 	        }
	 	        curr.append(count).append(say);
	        }	       	        
	        return curr.toString();
        
    }
}


/*
My init solution:
My thinking: use queue, every level, maintenance a size_level to record the queue size to access in x level;
for each level, use cnt to record duplicate number and add queue with (cnt, i number);

*/


public String countAndSay(int n) {
        int level = 1;
        Queue<Integer> ql = new LinkedList<Integer>();
        if(n==1)
            return "1";
        ql.add(1);
        int levelSize=1;
        level++;
        while(level <= n){
            int tempCnt = 0;
            int curNum = -1;
            for(int i=0;i<levelSize;i++){
                if(i==0){
                    curNum = ql.poll();
                    tempCnt++;
                    if(i==levelSize-1){
                        ql.add(tempCnt);
                        ql.add(curNum);
                        curNum = -1;
                        tempCnt = 0;
                    }
                }else {
                    int t = ql.poll();
                    if(t==curNum && i<levelSize-1){
                        tempCnt++;
                    }

                    if(t==curNum && i==levelSize-1) {
                        tempCnt++;
                        ql.add(tempCnt);
                        ql.add(curNum);
                        curNum = -1;
                        tempCnt = 0;
                    }else if(t!=curNum && i<levelSize-1){
                        ql.add(tempCnt);
                        ql.add(curNum);
                        curNum = t;
                        tempCnt = 1;
                    }else if(t!=curNum && i==levelSize-1){
                        ql.add(tempCnt);
                        ql.add(curNum);
                        ql.add(t);
                        ql.add(1);
                    }
                }
            }

            levelSize = ql.size();
            level++;
        }

        StringBuilder sb = new StringBuilder();
        for(Integer s : ql) {
            sb.append(String.valueOf(s));
        }

        return sb.toString();

    }
