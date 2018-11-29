public class PriorityQueue<Key extends Comparable<Key>> implements java.io.Serializable {

    private static final int DEFAULT_INITIAL_CAPACITY = 11;

    /**
     * Priority queue represented as a balanced binary heap: the two children of
     * queue[n] are queue[2*n+1] and queue[2*(n+1)]. The priority queue is ordered
     * by comparator, or by the elements' natural ordering, if comparator is null:
     * For each node n in the heap and each descendant d of n, n <= d. The element
     * with the lowest value is in queue[0], assuming the queue is nonempty.
     */
    transient Object[] queue; // non-private to simplify nested class access

    /**
     * The number of elements in the priority queue.
     */
    private int size = 0;

    /**
     * The comparator, or null if priority queue uses elements' natural ordering.
     */
    private final Comparator<? super Key> comparator;

    /**
     * Creates a {@code PriorityQueue} with the default initial capacity (11) that
     * orders its elements according to their {@linkplain Comparable natural
     * ordering}.
     */
    public PriorityQueue() {
        this(DEFAULT_INITIAL_CAPACITY, null);
    }

    /**
     * Creates a {@code PriorityQueue} with the specified initial capacity that
     * orders its elements according to their {@linkplain Comparable natural
     * ordering}.
     *
     * @param initialCapacity the initial capacity for this priority queue
     * @throws IllegalArgumentException if {@code initialCapacity} is less than 1
     */
    public PriorityQueue(int initialCapacity) {
        this(initialCapacity, null);
    }

    /**
     * Creates a {@code PriorityQueue} with the specified initial capacity that
     * orders its elements according to the specified comparator.
     *
     * @param initialCapacity the initial capacity for this priority queue
     * @param comparator      the comparator that will be used to order this
     *                        priority queue. If {@code null}, the
     *                        {@linkplain Comparable natural ordering} of the
     *                        elements will be used.
     * @throws IllegalArgumentException if {@code initialCapacity} is less than 1
     */
    public PriorityQueue(int initialCapacity, Comparator<? super Key> comparator) {
        // Note: This restriction of at least one is not actually needed,
        // but continues for 1.5 compatibility
        if (initialCapacity < 1)
            throw new IllegalArgumentException();
        this.queue = new Object[initialCapacity];
        this.comparator = comparator;
    }

    /**
     * Inserts item x at position k, maintaining heap invariant by promoting x up
     * the tree until it is greater than or equal to its parent, or is the root.
     *
     * To simplify and speed up coercions and comparisons. the Comparable and
     * Comparator versions are separated into different methods that are otherwise
     * identical. (Similarly for siftDown.)
     *
     * @param k the position to fill
     * @param x the item to insert
     */
    private void siftUp(int k, E x) {
        if (comparator != null)
            siftUpUsingComparator(k, x);
        else
            siftUpComparable(k, x);
    }

    @SuppressWarnings("unchecked")
    private void siftUpComparable(int k, E x) {
        Comparable<? super E> key = (Comparable<? super E>) x;
        while (k > 0) {
            int parent = (k - 1) >>> 1;
            Object e = queue[parent];
            if (key.compareTo((E) e) >= 0)
                break;
            queue[k] = e;
            k = parent;
        }
        queue[k] = key;
    }

    @SuppressWarnings("unchecked")
    private void siftUpUsingComparator(int k, E x) {
        while (k > 0) {
            int parent = (k - 1) >>> 1; // （k-1）除以2获取父节点的index
            Object e = queue[parent];
            if (comparator.compare(x, (E) e) >= 0) // 直到x大于父节点
                break;
            queue[k] = e; // 把父节点的值放入k
            k = parent; // k上移指向父节点
        }
        queue[k] = x; // 最终合适到位置放入x
    }

    /**
     * Inserts item x at position k, maintaining heap invariant by
     * demoting x down the tree repeatedly until it is less than or
     * equal to its children or is a leaf.
     *
     * @param k the position to fill
     * @param x the item to insert
     */
    private void siftDown(int k, E x) {
        if (comparator != null)
            siftDownUsingComparator(k, x);
        else
            siftDownComparable(k, x);
    }

    @SuppressWarnings("unchecked")
    private void siftDownComparable(int k, E x) {
        Comparable<? super E> key = (Comparable<? super E>)x;
        int half = size >>> 1;        // loop while a non-leaf
        while (k < half) {
            int child = (k << 1) + 1; // assume left child is least
            Object c = queue[child];
            int right = child + 1;
            if (right < size &&
                ((Comparable<? super E>) c).compareTo((E) queue[right]) > 0)
                c = queue[child = right];
            if (key.compareTo((E) c) <= 0)
                break;
            queue[k] = c;
            k = child;
        }
        queue[k] = key;
    }

    @SuppressWarnings("unchecked")
    private void siftDownUsingComparator(int k, E x) {
        int half = size >>> 1;
        while (k < half) {
            int child = (k << 1) + 1;
            Object c = queue[child];
            int right = child + 1;
            if (right < size &&
                comparator.compare((E) c, (E) queue[right]) > 0)
                c = queue[child = right];
            if (comparator.compare(x, (E) c) <= 0)
                break;
            queue[k] = c;
            k = child;
        }
        queue[k] = x;
    }


    /**
     * Removes the ith element from queue.
     *
     * Normally this method leaves the elements at up to i-1,
     * inclusive, untouched.  Under these circumstances, it returns
     * null.  Occasionally, in order to maintain the heap invariant,
     * it must swap a later element of the list with one earlier than
     * i.  Under these circumstances, this method returns the element
     * that was previously at the end of the list and is now at some
     * position before i. This fact is used by iterator.remove so as to
     * avoid missing traversing elements.
     */
    @SuppressWarnings("unchecked")
    private E removeAt(int i) {
        // assert i >= 0 && i < size;
        modCount++;
        int s = --size;
        if (s == i) // i是最后一个，直接删除
            queue[i] = null;  // 直接删除
        else {
            E moved = (E) queue[s];  // 把最后一个元素保存到临时变量moved
            queue[s] = null;  // 删除最后一个元素
            siftDown(i, moved);  // 把原最后的元素放入位置i， 并调用siftDown重新调整堆
            if (queue[i] == moved) { // 如果siftDown之后，queue[i] == moved， 表明 moved < 所有child，moved原来也是叶节点 
                siftUp(i, moved);  // 这时候要尝试做siftUp
                if (queue[i] != moved)  //如果siftUp使堆有变化，则返回moved
                    return moved;
            }
        }
        return null;  // 如果到i-1为止堆元素没有变化，返回null
    }

    /**
     * Inserts the specified element into this priority queue.
     *
     * @return {@code true} (as specified by {@link Queue#offer})
     * @throws ClassCastException if the specified element cannot be
     *         compared with elements currently in this priority queue
     *         according to the priority queue's ordering
     * @throws NullPointerException if the specified element is null
     */
    public boolean offer(E e) {
        if (e == null)
            throw new NullPointerException();
        modCount++;
        int i = size;  // i等于当前size，即当前最后位置
        if (i >= queue.length)
            grow(i + 1);  //保证queue容量
        size = i + 1;  // 递增size
        if (i == 0)
            queue[0] = e;  //如果是第一个，直接放在heap根
        else
            siftUp(i, e);  //如果不是第一个，放在i之后要siftUp来恢复堆
        return true;
    }

    /**
     * Establishes the heap invariant (described above) in the entire tree,
     * assuming nothing about the order of the elements prior to the call.
     */
    @SuppressWarnings("unchecked")
    private void heapify() {
        for (int i = (size >>> 1) - 1; i >= 0; i--)
            siftDown(i, (E) queue[i]);
    }
    
    private boolean less(int i, int j) {
        return pq[i].compareTo(pq[j]) < 0;
    }

    private void exch(int i, int j) {
        Key t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }

    private void swim(int k) {
        while (k > 1 && less(k / 2, k)) {
            exch(k / 2, k);
            k = k / 2;
        }
    }

    private void sink(int k) {
        while (2 * k <= N) {
            int j = 2 * k;
            if (j < N && less(j, j + 1))
                j++;
            if (!less(k, j))
                break;
            exch(k, j);
            k = j;
        }
    }
    
}
