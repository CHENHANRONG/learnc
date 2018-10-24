/*
905. Sort Array By Parity

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000

*/

void swap(int []array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
public int[] sortArrayByParity(int[] A) {
    int i=0; 
    int j=A.length-1;
    while(i<j){
        if(A[i]%2==0){
            i++;
            continue;
        }else{
            //A[i] is even
            swap(A, i,j);
            j--;
        }
    }

    return A;
}
