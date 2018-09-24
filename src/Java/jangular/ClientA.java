
public class ClientA {

  private MyService service;

  ClientA() {
    System.out.println("ClientA");
    this.service = new MyService();
  }

  public void setValue(int v) {
    this.service.setValue(v);
  }

  public void printValue() {
    System.out.println(this.service.getValue());
  }

}
