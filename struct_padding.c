 //==========================================================
    //    Size of structures
    struct{
        //smaller type auto padding to same as longest type in struct
        char c;
        int i;
        long l;
        double d
    }x;
    printf("size=%d\n", sizeof(x));
