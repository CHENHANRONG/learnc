/*
Java code:
public static String mystery(String s)
    {
       int N = s.length();
       if (N <= 1) return s;
       String a = s.substring(0, N/2);
       String b = s.substring(N/2, N);
       return mystery(b) + mystery(a);
    }
*/

std::string string_reverse(std::string s){
    size_t N = s.length();
    if (N <= 1) return s;
    std::string a = s.substr(0, N/2);
    std::string b = s.substr(N/2, N);
    return string_reverse(b) + string_reverse(a);
}
