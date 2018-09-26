/*
1256. Nth Digit
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Example
Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
Notice
n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).
*/

/*
Java:
思路:
1-9:      9个数字，每个数字长度为1，故总占位为9*1；
10-99:    90个数字，每个数字长度为2，故总占位为90*2；
100-999:  900个数字，每个数字长度为3，故总占位为900*3；
以此类推

对于给定的输入n， 假定是100，则
100-9=91，落在90*2的范围内，故数字必为一个二位数。
计算这个二位数： long num = (x-1)/len+start;  ， len=2， start=10， x = n-9; 为55.
计算55中哪个数字需要返回，需要计算offset：  int offset = (x-1) % len; 为0
故为第一位数字5， 取得这位数字通过result = (int)(num / Math.pow(10,len-offset-1))%10; 获得。
*/

    /**
     * @param n: a positive integer
     * @return: the nth digit of the infinite integer sequence
     */
  public int findNthDigit(int n) {

        // write your code here
        int x = n;
        BigInteger start = BigInteger.valueOf(1);
        int len = 1;
        int i=0;

        int result = 0;

        BigInteger range = BigInteger.valueOf(9*((int)Math.pow(10,i))*len);
        while(range.compareTo(BigInteger.valueOf(x)) < 0){
            x = (int) (x-range.intValue());
            i++;
            len++;
            start = (BigInteger) BigInteger.valueOf((long)Math.pow(10,i));
            range = BigInteger.valueOf(9*((long)Math.pow(10,i))*len);
        }


//        long num = (x-1)/len+start;
        BigInteger num = start.add(BigInteger.valueOf((x-1)/len)) ;
        int offset = (x-1) % len;
//        result = (int)(num / Math.pow(10,len-offset-1))%10;
        result = num.divide(BigInteger.valueOf((long)Math.pow(10,len-offset-1))).mod(BigInteger.valueOf(10)).intValue();
        return result;

    }
    
    
    /* 
    C++
    */
    class Solution {
    public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};
