import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

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

    public DepthFirstPath(Graph G, int s){
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
