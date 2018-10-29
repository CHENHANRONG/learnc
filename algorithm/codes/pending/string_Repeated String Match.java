/*

686. Repeated String Match


Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.

*/

public int repeatedStringMatch(String A, String B) {
    int cnt = 0;
    int j=0;
    for(int i=0;i<B.length();){
        while(i+j < B.length() && A.indexOf(B.substring(i, i+j+1))>=0){
            j++;
        }

        if(j>=0){
            i = i+j;
            j = 0;
            cnt++;
        }else{
            //j<0, no match
            cnt = -1;
            break;
        }

    }

    return cnt;
}
