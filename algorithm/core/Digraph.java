
import java.util.HashSet;
import java.util.Set;

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
 */
public class DirectedDFS
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
