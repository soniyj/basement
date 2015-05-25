/**
 * Algorithms Classes 
 * 
 * Contains BFS and DFS Classes as well.
 * 
 * File: Algos.java
 * 
 * @author Marco "soniyj" Matascioli
 */

package dagtest;

import java.util.Deque;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import java.util.Set;

public class Algos {
  protected Set<String> visited = new HashSet<String>();
  protected Graph graph;
} /* Class Algos */

class TraverseBreadthFirst extends Algos implements Iterator<String> {
  private Queue<String> queue = new LinkedList<String>();

   public TraverseBreadthFirst(Graph g, String startingVertex) {
    this.graph = g;
    this.queue.add(startingVertex);
    this.visited.add(startingVertex);
  }
  
  @Override
  public boolean hasNext() {
    return !this.queue.isEmpty();
  }

  @Override
  public String next() {
    //removes from front of queue
    String next = queue.remove(); 
    for (String neighbor : this.graph.getNeighbors(next)) {
      if (!this.visited.contains(neighbor)) {
        this.queue.add(neighbor);
        this.visited.add(neighbor);
      }
    }
    return next;
  }

  @Override
  public void remove() {
    throw new UnsupportedOperationException("Not supported yet.");
  }
} /* BFS */

class TraverseDepthFirst extends Algos implements Iterator<String> {
  private Deque<Iterator<String>> stack = new LinkedList<Iterator<String>>();
  private String next;

  public TraverseDepthFirst(Graph g, String startingVertex) {
    this.stack.push(g.getNeighbors(startingVertex).iterator());
    this.graph = g;
    this.next = startingVertex;
  }

  @Override
  public void remove() {
    throw new UnsupportedOperationException("Not supported yet.");
  }

  @Override
  public boolean hasNext() {
    return this.next != null;
  }

  @Override
  public String next() {
    if (this.next == null) {
      throw new NoSuchElementException();
    }
    try {
      this.visited.add(this.next);
      return this.next;
    } finally {
      this.advance();
    }
  }

  private void advance() {
    Iterator<String> neighbors = this.stack.peek();
    do {
      while (!neighbors.hasNext()) { // No more nodes -> back out a level
        this.stack.pop();
        if (this.stack.isEmpty()) {  // Done!
          this.next = null;
          return;
        }
        neighbors = this.stack.peek();
      }
      this.next = neighbors.next();
    } while (this.visited.contains(this.next));
    this.stack.push(this.graph.getNeighbors(this.next).iterator());
  }
} /* DFS */