/**
 * Graph Class
 * 
 * File: Graph.java
 * 
 * @author Marco "soniyj" Matascioli
 */

package dagtest;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Graph {
  private Map<String, Node> edges = new HashMap<String, Node>();
  
  public void Create(int depth, int width) {
    this.CreateRec(depth-1, width, "1", 0);
  }
  
  private void CreateRec(int depth, int width, String sb, int prof) {
    if(depth<0)
      return;
    for(int i=1; i<=width; i++) {
      this.addEdge(sb, sb+"."+i, prof, width);
      CreateRec(depth-1, width, sb+"."+i, prof+1);
    }
  }
  
  public void addEdge(String src, String dest, int depth, int width) {
    Node srcNeighbors = this.edges.get(src);
    if (srcNeighbors == null) {
      this.edges.put(src, srcNeighbors = new Node());
    }
    // In case dest === srcNeighbors => skip
    srcNeighbors.add(dest);
    
    srcNeighbors.setName(dest);
    srcNeighbors.setParent(src);
    srcNeighbors.setDepth(depth);
    srcNeighbors.setChildren(width);
  }
  
  public Iterable<String> getNeighbors(String vertex) {
    Node neighbors = this.edges.get(vertex);
    if (neighbors == null) {
      return Collections.emptyList();
    } else {
      return Collections.unmodifiableList(neighbors);
    }
  }
  
  public void Print() {
    for (Map.Entry<String, Node> entry : edges.entrySet()) {
      String key = entry.getKey();
      Node value = entry.getValue();
      System.out.println("key, " + key + " value " + value);
    }
  }
} /* Class Graph */
