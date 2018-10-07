public class MaxPQ<Key extends  Comparable<Key>> {

    private Key[] pq;
    private int N = 0;


    public MaxPQ(){  //创建一个优先队列

    };
    public MaxPQ(int maxN){  //创建一个初始容量为max的优先队列
        pq = (Key[]) new Comparable[maxN+1];
    }
    public MaxPQ(Key[] a){  //create MaxPQ using elements in a[]
        pq = a;
    }

    public boolean isEmpty(){
        return N == 0;
    }

    public int size(){
        return N;
    }

    void insert(Key v){
        pq[++N] = v;
        swim(N);
    }

    public Key max(){
        return pq[1];
    }

    Key delMax(){
        Key max = pq[1];  // get max from root
        exch(1, N--);  //exchange root with last element
        pq[N+1] = null;  // ?
        sink(1);   //sink changed root to proper position, recover heap balance
        return max;
    }






    private boolean less(int i, int j){
        return pq[i].compareTo(pq[j]) < 0;
    }

    private void exch(int i, int j){
        Key t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }


    /**
     * 上浮(swim)
     * @param k
     */
    private void swim(int k){
        while(k>1 && less(k/2, k)){
            exch(k/2,k);
            k = k/2;
        }
    }


    /**
     * 下沉(sink)
     * @param k
     */
    private void sink(int k){
        while(2*k <= N){
            int j = 2*k;
            if(j < N && less(j,j+1))
                j++;
            if(!less(k,j))
                break;
            exch(k,j);
            k=j;
        }
    }


}
