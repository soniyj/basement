
public class ClientB {

  private MyService service;

  ClientB() {
    System.out.println("ClientB");
    this.service = new MyService();
  }

  public void setValue(int v) {
    this.service.setValue(v);
  }

  public void printValue() {
    System.out.println(this.service.getValue());
  }
  
}
