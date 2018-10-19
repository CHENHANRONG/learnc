import java.util.*;

public class Digraph {

    private final int V;  // #vertexes
    private int E;   // #edges
    private Set<Integer> []adj;  //adj symbol table

    public Digraph(int V) {
        this.V = V;
        this.E = 0;
        this.adj = new HashSet[V];

        for (int v = 0; v < V; v++) {
            adj[v] = new HashSet<Integer>();  // init symbol table
        }
    }


    public int V() {
        return this.V;
    }


    public int E(){
        return this.E;
    }


    /**
     * Add edge v->w
     * @param v
     * @param w
     */
    public void addEdge(int v, int w){
        this.adj[v].add(w);
        this.E++;
    }


    public Iterable<Integer> adj(int v){
        return adj[v];
    }


    /**
     *  reverse() that returns a copy with all its edges reversed.
     * @return
     */
    public Digraph revverse(){
        Digraph R = new Digraph(V);
        for(int v=0; v<V; v++){
            for(int w : adj[v]){
                R.addEdge(w, v);
            }
        }

        return R;
    }

}


/**
 * Single-source reachability:
 * Given a digraph and a source vertex s, support queries of the form
 * Is there a directed path from s to a given target vertex v?
 *
 * Application: Mark-and-sweep garbage collection
 * 垃圾回收
 */
class DirectedDFS
{
    private boolean[] marked;
    public DirectedDFS(Digraph G, int s)
    {
        this.marked = new boolean[G.V()];
        dfs(G, s);
    }

    public void dfs(Digraph G, Iterable<Integer> src)
    {
        marked = new boolean[G.V()];
        for(int s : src){
            if(!marked[s])
                dfs(G, s);
        }
    }

    public void dfs(Digraph G, int v)
    {
        marked[v]= true;
        for(int w : G.adj(v)){
            if(!marked[w])
                dfs(G, w);
        }
    }


    public boolean marked(int v){
        return marked[v];
    }

}


/**
 * Finding paths in digraphs - DFS
 *
 * Classic Question:
 * 1. Single-source directed paths:
 * Given a digraph and a source vertex s, support queries of the form Is there a directed path from s to a given target vertex v?
 * If so, find such a path.
 *
 * 2.
 *
 */
class DigraphDepthFirstPaths{

    private boolean[] marked;
    private int count;
    private int[] edgeTo;
    private final int s;

    public DigraphDepthFirstPaths(Digraph G, int s){
        this.marked = new boolean[G.V()];
        this.edgeTo = new int[G.V()];
        this.s = s;
        dfs(G,s);
    }


    private void dfs(Digraph G, int v){
        marked[v] = true;
        count++;
        for(int w : G.adj(v)) {
            if (!marked[w]){
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }


    public boolean hasPathTo(int v){
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v){
        if(!hasPathTo(v))
            return null;

        Stack<Integer> path = new Stack();
        for(int x=v; x!=s; x=this.edgeTo[x]){
            path.push(x);
        }

        path.push(s);

        return path;
    }


    public boolean marked(int w){
        return marked[w];
    }


    public int count(){
        return count;
    }


}


/**
 * Finding paths in digraphs - BFS
 * Classic Question:
 * 1. Single-source shortest directed paths:
 * Given a digraph and a source vertex s, support queries of the form Is there a directed path from s to a given target vertex v?
 * If so, find a shortest such path (one with a minimal number of edges).
 */
class DigraphBreadthFirstPaths {
    private boolean[] marked;  // Is a shortest path to this vertex known?
    private int[] edgeTo;  // last vertex on known path to this verte
    private final int s;  // source

    public DigraphBreadthFirstPaths(Digraph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        bfs(G, s);
    }

    public void bfs(Digraph G, int s) {
        Queue<Integer> queue = new LinkedList<Integer>();
        marked[s] = true;
        queue.add(s);
        while (!queue.isEmpty()) {
            int v = queue.poll();  // Remove next vertex from the queue.
            for (int w : G.adj(v)) {
                if (!marked[w]) {  // For every unmarked adjacent vertex
                    edgeTo[w] = v;  // save last edge on a shortest path
                    marked[w] = true;
                    queue.add(w);
                }
            }
        }
    }

    public boolean hasPathTo(int v) {
        return marked[v];
    }


    public Iterable<Integer> pathTo(int v){
        if(!hasPathTo(v))
            return null;

        Stack<Integer> path = new Stack();
        for(int x=v; x!=s; x=this.edgeTo[x]){
            path.push(x);
        }

        path.push(s);

        return path;
    }

}



    /**
     * When executing dfs(G, v),we have followed a directed path from the source to v.
     * To keep track of this path, DirectedCycle maintains a vertex-indexed array onStack[]
     * that marks the vertices on the recursive call stack (by setting onStack[v] to true on entry to dfs(G, v)
     * and to false on exit).
     * 
     * @param G
     * @param v
     */
    public void dfs(Digraph G, int v){
        onStack[v] = true;
        marked[v] = true;
        for(int w : G.adj(v)){
            if(this.hasCycle())
                return;
            else if(!marked[w]){
                edgeTo[w] = v;
                dfs(G, w);
            }else if(onStack[w]){
                /* If we ever find a directed edge v->w to a vertex w that is on that stack, we have found a cycle,
                since the stack is evidence of a directed path from w to v, and the edge v->w completes the cycle. */
                cycle = new Stack<Integer>();
                for(int x=v; x!=w; x=edgeTo[x])
                    cycle.push(x);

                cycle.push(w);
                cycle.push(v);
            }
        }

        onStack[v] = false;
    }

    public boolean hasCycle(){
        return cycle != null;
    }

    public Iterable<Integer> cycle(){
        return this.cycle;
    }
}
