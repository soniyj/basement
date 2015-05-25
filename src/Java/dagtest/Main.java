/**
 * Testing a Directed Acyclic Graph that simulate a Database. 
 * 
 * Performing also BFS and DFS.
 * 
 * File: Main.java
 * 
 * @author Marco "soniyj" Matascioli
 */

package dagtest;

import java.util.Iterator;

public class Main {

  public static void expectIteration(Iterator<String> it) {
    StringBuilder sb = new StringBuilder();
    while (it.hasNext()) {
      sb.append(' ').append(it.next());
      sb.append('\n');
    }
    System.out.println(sb.toString());
  }
  
  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    System.out.println("Hello world!\n");
    
    Graph G = new Graph();
    G.Create(2, 3);
    //G.Print();
    
    System.out.println("BFS");
    expectIteration(new TraverseBreadthFirst(G, "1"));
    System.out.println("DFS");
    expectIteration(new TraverseDepthFirst(G, "1"));
  }
} /* Class Main */