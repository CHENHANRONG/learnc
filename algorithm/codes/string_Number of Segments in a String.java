/*

434. Number of Segments in a String


Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5

*/


/*
My init solution:
use split(String reg);
*/


    public int countSegments(String s) {
        String trimmed = s.trim();
        if (trimmed.equals("")) {
            return 0;
        }
        return trimmed.split("\\s+").length;
    }


/*
in place solution

Approach #2 In-place [Accepted]
Intuition

If we cannot afford to allocate linear additional space, a fairly simple algorithm can deduce the number of segments in linear time and constant space.

Algorithm

To count the number of segments, it is equivalent to count the number of string indices at which a segment begins. Therefore, by formally defining the characteristics of such an index, we can simply iterate over the string and test each index in turn. Such a definition is as follows: a string index begins a segment if it is preceded by whitespace (or is the first index) and is not whitespace itself, which can be checked in constant time. Finally, we simply return the number of indices for which the condition is satisfied.


Complexity Analysis

Time complexity : O(n)

We do a constant time check for each of the string's nn indices, so the runtime is overall linear.

Space complexity : O(1)

There are only a few integers allocated, so the memory footprint is constant.

*/

    public int countSegments(String s) {
        int segmentCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s.charAt(i-1) == ' ') && s.charAt(i) != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }

