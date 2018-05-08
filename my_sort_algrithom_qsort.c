
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
