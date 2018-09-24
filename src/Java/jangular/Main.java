
public class Main {

  public static void main(String[] args) {
    System.out.println("Hello JAngular!");

    System.out.println("\nObject Reference");
    ClientA ca = new ClientA();
    ca.setValue(10);
    ca.printValue();

    ClientB cb = new ClientB();
    cb.printValue();

    System.out.println("\nObject Inheritance");
    ClientC cc = new ClientC();
    cc.setValue(20);
    cc.printValue();

    ClientD cd = new ClientD();
    cd.printValue();

    System.out.println("\nObject Singleton");
    ClientE ce = new ClientE();
    ce.setValue(30);
    ce.printValue();

    ClientF cf = new ClientF();
    cf.printValue();

  }

}
