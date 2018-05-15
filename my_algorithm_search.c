/*binary search*
int *binary_search0(int val, int *arr, unsigned int arr_size){
    unsigned int L=0, R=arr_size, M;
    while(L<R){
        M = (L+R-1)/2;  // find middle
        if(val == arr[M]){
            return arr+M;
        }else if(val<arr[M]){
            R = M;  // val < arr[M]
        }else{
            L = M+1;
        }
    }
    
    return NULL;  // no match
}
