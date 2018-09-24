
public class ClientC extends MyService {

  ClientC() {
    System.out.println("ClientC");
  }

  // Not possible to use this
  public void setValue(int v) {
    //this.setValue(v);
    super.setValue(v);
  }

  public void printValue() {
    System.out.println(this.getValue());
  }

}
