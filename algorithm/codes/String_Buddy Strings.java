/**
859. Buddy Strings

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Example 2:

Input: A = "ab", B = "ab"
Output: false
Example 3:

Input: A = "aa", B = "aa"
Output: true
Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false
 

Note:

0 <= A.length <= 20000
0 <= B.length <= 20000
A and B consist only of lowercase letter

*/


public boolean buddyStrings(String A, String B) {
    if(A.length() != B.length())
        return false;


    Set<Character> cs = new HashSet<Character>();

    int diffNum = 0;
    StringBuilder diffA = new StringBuilder();
    StringBuilder diffB = new StringBuilder();

    for(int i=0; i<A.length(); i++){
        if(A.charAt(i) == B.charAt(i)){
            cs.add(A.charAt(i));
        }else{
            if(++diffNum > 2){
                return false;
            }else{
                diffA = diffA.insert(0, A.charAt(i));
                diffB = diffB.append(B.charAt(i));
            }
        }
    }


    if(diffNum== 0 && cs.size() < A.length()){  
        return true;
    }else if(diffNum == 2){
        if(diffA.toString().equals(diffB.toString()))
            return true;
    }

    return false;

}


/**
other:
*/
public boolean buddyStrings(String A, String B) {
    if (A.length() != B.length()) return false;
    if (A.equals(B)) {
        Set<Character> s = new HashSet<Character>();
        for (char c : A.toCharArray()) s.add(c);
        return s.size() < A.length();
    }
    List<Integer> dif = new ArrayList<>();
    for (int i = 0; i < A.length(); ++i) if (A.charAt(i) != B.charAt(i)) dif.add(i);
    return dif.size() == 2 && A.charAt(dif.get(0)) == B.charAt(dif.get(1)) && A.charAt(dif.get(1)) == B.charAt(dif.get(0));
}
