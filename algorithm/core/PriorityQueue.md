# Priority queue
Priority queue represented as a **balanced binary heap: the two children of queue[n] are queue[2*n+1] and queue[2*(n+1)].** The priority queue is ordered by comparator, or by the elements' natural ordering, if comparator is null: For each node n in the heap and each descendant d of n, n <= d. The element with the lowest value is in queue[0], assuming the queue is nonempty.

```Java
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

    private void siftDownUsingComparator(int k, E x) {
        int half = size >>> 1;  // 无符号右移 -> 除以2取中间值
        while (k < half) {  //
            int child = (k << 1) + 1;  //左移， 乘以2
            Object c = queue[child];  // c的值是k的某个child的值（左右child中较大的那个）
            int right = child + 1;  //比较两个child哪个大
            if (right < size &&
                comparator.compare((E) c, (E) queue[right]) > 0)
                c = queue[child = right];
            if (comparator.compare(x, (E) c) <= 0)  //直到x小于某个child
                break;
            queue[k] = c;  //如果x大于两个child中较大的那个，则把较大的child放到本k的位置
            k = child;  //把k指向较大的child
        }
        queue[k] = x;  // 把x放到合适的k的child的节点上，保证此节点的所有父节点都比此节点的值大
    }
```