
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
