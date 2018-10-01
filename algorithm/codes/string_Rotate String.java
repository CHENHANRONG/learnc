/*
8. Rotate String
Given a string and an offset, rotate string by offset. (rotate from left to right)

Example

Given "abcdefg"： offset=0 => "abcdefg" offset=1 => "gabcdef" offset=2 => "fgabcde" offset=3 => "efgabcd"

Challenge： Rotate in-place with O(1) extra memory.

*/

public class Solution {
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     * 
     * 思路：相当于把数组末尾offset个元素，不变换顺序地冒泡交换到数组最开头的offset个位置。
     * 当offset>数组长度的时候，其实真正offset值的是 offset %= str.length
     */
     
     //方法一： 每次把offset中的1个元素，移动str.length-offset次：
     public void rotateString(char[] str, int offset) {
        // write your code here
        if(str.length>0){
            offset %= str.length;  //offset length
            for(int i=0;i<offset;i++){  //数组最后offset个元素
                for(int j=0;j<str.length-offset;j++){     //每次循环, 把每个offset里的元素向前移动str.length-offset位
                    char temp = str[str.length - offset + i-j-1];
                    str[str.length - offset + i-j-1] = str[str.length - offset + i-j];
                    str[str.length - offset + i-j] = temp;
                }
                
            }
        }
     }
     //方法二： 每次把offset个元素，集体往前移动1位，一共移动str.length-offset次：
    public static void rotateString(char[] str, int offset) {
       
        if(str!=null && str.length>0){
        
            // write your code here
            offset %= str.length;
            for(int i=str.length-offset-1;i>=0;i--){  //
                for(int j=0;j<offset;j++){
                    char temp = str[i+j];
                    str[i+j] = str[i+j+1];
                    str[i+j+1] = temp;
                }
            }
        }
    }
}
// (A^-1B^-1)^-1 = BA
public void rotateString(char[] str, int offset) {
        // write your code here
        if (str == null || str.length == 0)
            return;
            
        offset = offset % str.length;
        reverse(str, 0, str.length - offset - 1);
        reverse(str, str.length - offset, str.length - 1);
        reverse(str, 0, str.length - 1);
    }
    
    private void reverse(char[] str, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
