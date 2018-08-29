 //==========================================================
// Members can be explicitly aligned using compiler extensions.
// __attribute__((aligned(x))) /∗gcc∗/ 
//  __declspec((aligned(x))) /∗MSVC∗/
    //    Size of structures
    struct{
        //smaller type auto padding to same as longer type in struct ?
        char c;
        int i;
        long l;
        double d
    }x;
    printf("size=%d\n", sizeof(x));
