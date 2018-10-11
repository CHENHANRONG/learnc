/*
551. Student Attendance Record I

You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False


*/


/*
My solution:
*/
 public boolean checkRecord(String s) {
        boolean res = true;
        int aCnt = 0;
        int conLCnt = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == 'A'){
                aCnt++;
                if(aCnt >1){
                    res = false;
                    break;
                }
                 conLCnt = 0; //reset continous L cnt
                    
            }else if(s.charAt(i) == 'L'){
                conLCnt++;
                if(conLCnt>2){
                    res = false;
                    break;
                }
            }else{
                conLCnt = 0; //reset continous L cnt
            }
                
        }
        
        return res;
        
    }
    
    
    /* other solution
    Native API
    */
    
    //string api
    public boolean checkRecord(String s) {
        if(s.indexOf("A") != s.lastIndexOf("A") || s.contains("LLL"))
            return false;
        return true;
    }
    
    //regex 
    public boolean checkRecord(String s) {
    return !s.matches(".*LLL.*|.*A.*A.*");
    }
    
    
