
void swap(int v[], int i, int j){
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//    void swap(int v[], int i, int j);
/* qsort: sort v[left]...v[right] in increaseing order 
step 1: choose (left+right)/2, swap it to 'left' postion as v[left]
step 2: compare each element from left+1 to right until find one element's value >=v[left], mark its postion as last;
step 3: swap v[left] with v[last], so that v[last] >= all elements in left sub array, and v[last] <= all element's value in right sub-array.
Step 4: do recursively logic to [left, last-1] and [last+1, right] two subarrays.
*/
void qsort0(int v[], int left, int right){
    int i, last;
    
    // do nothing if array contains fewer than two elements
    if(left >= right)
        return;
        
    swap(v, left, (left+right)/2);  //move partition elem to v[0]
    last = left;
    for(i = left+1; i <= right; i++)  //partition
        if(v[i] < v[left]){
           swap(v,++last,i);
        }

    
    swap(v,left, last);  //restore partition elem
    qsort0(v, left, last-1);  //recursively do the qsort to left sub array
    qsort0(v, last+1, right);  //recursively do the qsort to right sub array
}



#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void qsort1(int *arr, unsigned int left, unsigned int right){
//    int mid = (left+right)/2;
    if(left >= right)
        return; //nothing to be sorted when left >= right
    
    swap(arr+left, arr+ (left+right)/2);
    unsigned int pivot = left;
    unsigned int i = left;
    /*go though the array, swap the smaller value to [last]'s left, and bigger
    ones in the right of the [last] */
    for(i = left+1; i<=right; i++){
        if(*(arr+i) < *(arr+left)){
            swap(arr + ++pivot, arr+i);
        }
    }
    
    swap(arr+left, arr+pivot);
    qsort1(arr, left, pivot-1);
    qsort1(arr, pivot+1, right);
}

int main(int argc, char **arg){
    int ia[] = {4,23,63,745,34,53,24,344,5,6,87,2};
    unsigned int len =sizeof(ia)/sizeof(ia[0]);
    qsort1(ia, 0, len-1);
    int j;
    for(j=0; j<len; j++){
        printf("ia[%d]=%d;\n", j, *(ia+j));
    }
    return EXIT_SUCCESS;
}


/* move previous elements down insertion point reached  */
void shift_element (unsigned int i , int arr[]) {
    int ivalue;
    /* guard against going outside array */
    for (ivalue = arr[i]; i && arr[i-1] > ivalue; i--){
        arr[i] = arr[i-1]; /* move element down */
    }
    arr[ i ] = ivalue ;
}

/*iterate until out−of−order element found; shift the element, and continue iterating */
void insertion_sort (int arr[], size_t len) {
    unsigned int i;
    for (i = 1; i < len; i++){
        if (arr[i] < arr[i-1]){
            shift_element(i, arr);
        }
        print_array(arr, len);
    }
