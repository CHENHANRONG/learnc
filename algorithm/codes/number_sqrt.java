/*
141. Sqrt(x)
Description:
Implement int sqrt(int x).

Compute and return the square root of x.

Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3

Challenge
O(log(x))
*/



/*
My init solution:
*/
/**
     * @param x: An integer
     * @return: The sqrt of x
     */
    public int sqrt(int x) {
        // write your code here
        long start=0;
        long end = x;
        long mid = 0;

        while(start <= end){
            mid = start+(end-start)/ 2;
            if(mid*mid==x)
                return (int)mid;
            else if(mid*mid < x) {
                start = mid + 1;
                if (start * start > x) {  //判断
                    return (int) start - 1;  //注意是start-1
                }
            }else {
                    end = mid - 1;
                    if (end * end < x) {
                        return (int) end;  //注意是end
                    }
                }
        }

        return -1;
    }

