```Java
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;
    
    
public class Main
{
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    public static int minSubArray(List<Integer> nums) {
        // write your code here
        int prevSum = 0;
        int laterSum = 0;
        int i = 0;
        for (int num : nums) {
            
            if(i == 0){
                prevSum = num;
                laterSum = num;
                continue;
            }
            
            if(num >0){
                laterSum = Integer.MAX_VALUE;
            }else{
                if(laterSum>0){
                    laterSum = num;
                }else{
                    laterSum += num;
                }
            }
            
            prevSum = Math.min(prevSum, laterSum);
            i++;
        }

        return prevSum;
    }
    
	public static void main(String[] args) {
	    List<Integer> nums = new ArrayList<Integer>(Arrays.asList(1,-1,-2,1));
	    

	    int out = minSubArray(nums);
		System.out.println("Hello World");
	}
}

```
