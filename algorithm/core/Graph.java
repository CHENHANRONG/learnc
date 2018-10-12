public class Graph {
    Graph(int V){

    }

//    Graph(In in){
//
//    }

    int V(){  // #vertex

    }

    int E(){  // #edge

    }

    void addEdge(int v, int w){  // add new edge v-w

    }

    Iterable<Integer> adj(int V){  // all vertexes adj to V

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
