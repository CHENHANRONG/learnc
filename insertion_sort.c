
int intArrary[] = {8,5,0,1,2,3,4,6,9,11,10};
int *pIA = intArrary;

void shit_element(unsigned i){
    int ivalue;
    
    for(ivalue = *(pIA+i); i && *(pIA+i-1) > ivalue; i--)
        *(pIA+i) = *(pIA+i-1);  //move bigger value to later one
    *(pIA+i) = ivalue;  // move smaller value to
}

void insertion_sort (void) {
    unsigned int i;
    unsigned int len = array_length(intArrary);
    for (i = 1; i < len; i++){
        if (*(pIA+i) <  *(pIA+i-1))
            shit_element(i);
    }
}


int main(void){
    insertion_sort();
    for(int x=0;x<array_length(intArrary);x++){
        printf("*(pIA+x)=%d\n",*(pIA+x));
    }
