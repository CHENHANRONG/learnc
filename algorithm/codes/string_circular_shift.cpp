/*
A string s is a circular shift (or circular rotation) of a string t if it matches when the characters are circularly shifted by any number of positions; 
e.g., ACTGACG is a circular shift of TGACGAC, and vice versa. 
Detecting this condition is important in the study of genomic sequences. 
Write a program that checks whether two given strings s and t are circular shifts of one another. 
Hint: The solution is a one-liner with indexOf(), length(), and string concatenation.
*/

/*
My solution:
string s1 = "ACTGACG";
string s2 = "TGACGAC";
splite s1 into two substrings, and from max length of the string, 
then minux 1 for each step to verify if the max length string could be find from s2.
if max length substring could be found from s2, then check the other substring of s1 are match the rest of the s2.

Java code:
import java.lang.String;
public class Test1{


    public static void main(String []args){
        String s1 = "ACTGACG";
        String s2 = "TGACGAC";
        int len = s1.length();
        int temp = 0;
        while(temp<len){
            String maxMatchStr = s1.substring(0,len-temp);  // try to find the max matched substring
            //System.out.println("maxMatchStr = "+ maxMatchStr);
            int findInd = s2.indexOf(maxMatchStr);
            String otherStr = s1.substring(len-temp);  // the left substring of s1
            if(findInd>-1){. //if could find
                String conStr = otherStr.concat(maxMatchStr);  //check if the two concated string is equal to s2
                System.out.println("temp = "+temp+"; firstStr = "+ otherStr + "; secondStr = "+ maxMatchStr);
                if(conStr.equals(s2)){
                    System.out.println("loop string");
                }
            }else{
                temp++;
            }
        }
        System.out.println("Not loop");
    }


}

*/


//C++ code:




/*
Better solutions:
*/


/*
Best solutions:
*/


/*
Review:
*/
