/*
13. Implement strStr()
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

if target does not exist in source, just return -1.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.

Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure you confirm with the interviewer first.

*/
// method 1: O(n2)
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     * 思路： 遍历source中的每一个字符，比对第i个字符开始往后target个长度的字符，与target字符一一对比，完全匹配返回i。
     */
    public int strStr(String source, String target) {
        // Write your code here
        if(source == null || target == null) 
            return -1;
        else if(source.length() == 0 && target.length() ==0)
            return 0;
        else if(target.length()<1)
            return 0;
        else if(source.length()<1 || source.length()<target.length())
            return -1;
            
        // int findIndex = -1;
        for(int i=0;i<=source.length()-target.length();i++){
            for(int j=0;j<target.length();j++){
                if(source.charAt(i+j) != target.charAt(j)){
                    break;
                }else if(j == target.length()-1){
                    return i;
                }else{
                    continue;
                }
            }
        }
        
        return -1;
    }
    
    //思路2: KMP
    
