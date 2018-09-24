
public class ClientF {

  private MyServiceSingleton service;

  ClientF() {
    System.out.println("ClientF");
    this.service = MyServiceSingleton.getInstance();
  }

  public void setValue(int v) {
    this.service.setValue(v);
  }

  public void printValue() {
    System.out.println(this.service.getValue());
  }

}
