/*binary search*/

void *(bsearch)(const void *key, const void *base,
	size_t nelem, size_t size, _Cmpfun *cmp)
	{	/* search sorted table by binary chop */
	const char *p;
	size_t n;

	for (p = (const char *)base, n = nelem; 0 < n; )
		{	/* check midpoint of whatever is left */
		const size_t pivot = n >> 1;
		const char *const q = p + size * pivot;
		const int val = (*cmp)(key, q);

		if (val < 0)
			n = pivot;	/* search below pivot */
		else if (val == 0)
			return ((void *)q);	/* found */
		else
			{	/* search above pivot */
			p = q + size;
			n -= pivot + 1;
			}
		}
	return (NULL);	/* no match */
	}


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


int* linear_search(int val, int *arr, size_t n){
    int *pArr;
    int *pArrEnd = arr+n;
    for(pArr = arr;pArr<pArrEnd;pArr++ ){
        if(*pArr == val){
            return pArr;
        }
    }
    
    return NULL;
}
