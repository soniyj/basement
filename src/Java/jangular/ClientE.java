
public class ClientE {

  private MyServiceSingleton service;

  ClientE() {
    System.out.println("ClientE");
    this.service = MyServiceSingleton.getInstance();
  }

  public void setValue(int v) {
    this.service.setValue(v);
  }

  public void printValue() {
    System.out.println(this.service.getValue());
  }

}
