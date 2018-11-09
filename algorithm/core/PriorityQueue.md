# Priority queue
Priority queue represented as a **balanced binary heap: the two children of queue[n] are queue[2*n+1] and queue[2*(n+1)].** The priority queue is ordered by comparator, or by the elements' natural ordering, if comparator is null: For each node n in the heap and each descendant d of n, n <= d. The element with the lowest value is in queue[0], assuming the queue is nonempty.

## siftDown
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

## siftUp
```Java
    /**
     * Inserts item x at position k, maintaining heap invariant by
     * promoting x up the tree until it is greater than or equal to
     * its parent, or is the root.
     *
     * To simplify and speed up coercions and comparisons. the
     * Comparable and Comparator versions are separated into different
     * methods that are otherwise identical. (Similarly for siftDown.)
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
            int parent = (k - 1) >>> 1;  //（k-1）除以2获取父节点的index
            Object e = queue[parent];
            if (comparator.compare(x, (E) e) >= 0)  //直到x大于父节点
                break;
            queue[k] = e;   //把父节点的值放入k
            k = parent;  //k上移指向父节点
        }
        queue[k] = x;  //最终合适到位置放入x
    }
    ```


    ## removeAt
    ```Java
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
            if (queue[i] == moved) { // 如果siftDown之后，queue[i] == moved， 表明 moved  小于所有child（表明moved原来也是叶节点？）
                siftUp(i, moved);  // 这时候要尝试做siftUp
                if (queue[i] != moved)  //如果siftUp使堆有变化，则返回moved
                    return moved;
            }
        }
        return null;  // 如果到i-1为止堆元素没有变化，返回null
    }
    ```