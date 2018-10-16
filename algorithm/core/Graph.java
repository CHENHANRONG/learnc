import java.util.*;

public class Graph {
    private final int V;  // #vertexes
    private int E;  // #edges
    private Set<Integer>[]adj;

    Graph(int V){
        this.V = V;
        this.E = 0;
        this.adj = new HashSet[V];  // create adj symbol table
        for(int i=0; i<V; i++){
            this.adj[i] = new HashSet<Integer>();   // init symbol table
        }

    }

//    Graph(In in){
//
//    }

    int V(){  // #vertex
        return this.V;
    }

    int E(){  // #edge
        return this.E;
    }

    void addEdge(int v, int w){  // add new edge v-w
        this.adj[v].add(w);
        this.adj[w].add(v);
        this.E++;
    }

    Iterable<Integer> adj(int v){  // all vertexes adj to V
        return this.adj[v];
    }

    public String toString(){
        String s = V+" vertices,  "+ E+" edges\n";
        for(int v=0; v<V; v++){
            s += v + ": ";
            for(int w : this.adj(v)){
                s += w + " ";
            }

            s += "\n";
        }

        return s;
    }


    /**
     * Calc vertex's degree
     * degree: number of edges adhere to this vertex
     *
     *
     * @param G
     * @param v
     * @return
     */
    public static int degree(Graph G, int v){
        int degree = 0;
        for(int w : G.adj(v))
            degree++;

        return degree;
    }


    /**
     * Find max degree of graph.
     * Go through all vertexes and find out the max
     *
     * @param G
     * @return
     */
    public static int maxDegree(Graph G){
        int max = 0;
        for(int v=0; v<G.V(); v++){
            if(degree(G, v)>max)
                max = degree(G, v);
        }

        return max;
    }


    /**
     * Calc average degree of the graph
     * 2*#edges/#vertexes
     *
     * @param G
     * @return
     */
    public static double avgDegree(Graph G){
        return 2.0*G.E()/G.V();
    }


    /**
     * If vertex v's adj vertex contain itself, then that means there is self loops.
     * @param G
     * @return
     */
    public static int numberOfSelfLoops(Graph G){
        int count = 0;
        for(int v=0; v<G.V(); v++){
            for(int w : G.adj(v)){
                if(v == w)
                    count++;
            }
        }

        return count/2;   //every edge count for 2 times.
    }







}


class DepthFirstSearch{

    private boolean[] marked;
    private int count;

    public DepthFirstSearch(Graph G, int s){
        marked = new boolean[G.V()];
        dfs(G,s);
    }


    private void dfs(Graph G, int v){
        marked[v] = true;
        count++;
        for(int w : G.adj(v))
            if(!marked[w]) dfs(G, w);
    }


    public boolean marked(int w){
        return marked[w];
    }


    public int count(){
        return count;
    }

}



class DepthFirstPaths{

    private boolean[] marked;
    private int count;
    private int[] edgeTo;
    private final int s;

    public DepthFirstPaths(Graph G, int s){
        this.marked = new boolean[G.V()];
        this.edgeTo = new int[G.V()];
        this.s = s;
        dfs(G,s);
    }


    private void dfs(Graph G, int v){
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


class BreadthFirstPaths {
    private boolean[] marked;  // Is a shortest path to this vertex known?
    private int[] edgeTo;  // last vertex on known path to this verte
    private final int s;  // source

    public BreadthFirstPaths(Graph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        bfs(G, s);
    }

    public void bfs(Graph G, int s) {
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
 * Depth-first search to find connected components in a graph
 */
class CC   //connected components
{

    private boolean[] marked;
    private int[] id;  // id[i] is vertex i's CC
    private int count;  // CC's value

    public CC(Graph G){
        marked = new boolean[G.V()];  // init marked
        id = new int[G.V()];  // init id
        for(int s=0; s<G.V(); s++){
            if(!marked[s]){
                dfs(G,s);
                this.count++;  // calc CC value
            }
        }
    }


    public void dfs(Graph G, int v)
    {
        marked[v] = true;
        id[v] = this.count;
        for(int w : G.adj(v)) {
            if (!marked[w]) {
                dfs(G, w);
            }
        }
    }


    public boolean connected(int v, int w)
    {
        return id[v] == id[w];
    }

    public int id(int v)
    {
        return id[v];
    }

    public int count()
    {
        return count;
    }
}


/**
 * is G acyclic? (assumes no self-loops or parallel edges)
 */
class Cycle
{
    private boolean[] marked;
    private boolean hasCycle;

    public Cycle(Graph G)
    {
        marked = new boolean[G.V()];
        for (int s = 0; s < G.V(); s++){
            if (!marked[s])
                dfs(G, s, s);
        }
    }


    /**
     *
     * @param G : Graph
     * @param v :
     * @param u : ???
     */
    public void dfs(Graph G, int v, int u)
    {
        marked[v] = true;
        for(int w : G.adj(v)) {
            if (!marked[w])
            {
                dfs(G, w, v);
            }
            else if(w != u)  // w is marked, and w is not u  ???
            {
                this.hasCycle = true;
            }
        }
    }

    public boolean hasCycle(){
        return this.hasCycle;
    }

}


/**
 * is G bipartite? (two-colorable)
 */
class TwoColor
{
    private boolean[] marked;
    private boolean[] color;  //
    private boolean isTwoColorable = true;  //

    public TwoColor(Graph G){
        marked = new boolean[G.V()];  // init marked
        color = new boolean[G.V()];  // init color array
        for(int s=0; s<G.V(); s++){
            if(!marked[s]){
                dfs(G,s);
            }
        }
    }


    public void dfs(Graph G, int v)
    {
        marked[v] = true;
        for(int w : G.adj(v)) {
            if (!marked[w]) {
                color[w] = !color[v];
                this.dfs(G, w);
            }else if(color[w] == color[v]){
                this.isTwoColorable = false;
            }
        }
    }

    public boolean isBipartite(){
        return this.isTwoColorable;
    }
}
