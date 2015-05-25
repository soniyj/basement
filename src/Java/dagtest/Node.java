/**
 * Node Class
 * 
 * File: Node.java
 * 
 * @author Marco "soniyj" Matascioli
 */

/**
 * Note: Name and Parent are just for compatibility,
 *       these information are already stored into the edges Map.
 */
package dagtest;

import java.util.ArrayList;

public class Node extends ArrayList<String> {
  private int depth;
  private int children;
  private String name;
  private String parent;
  
  public void setDepth(int d) {
    this.depth = d;
  }
  public int getDepth() {
    return this.depth;
  }
  
  public void setChildren(int c) {
    this.children = c;
  }
  public int getChildren() {
    return this.children;
  }
  
  public void setName(String s) {
    this.name = s;
  }
  public String getName() {
    return this.name;
  }
  
  public void setParent(String s) {
    this.parent = s;
  }
  public String getParent() {
    return this.parent;
  }
} /* Class Node */