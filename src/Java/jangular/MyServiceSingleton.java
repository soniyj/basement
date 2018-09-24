
public class MyServiceSingleton {

  private int value;
  private static MyServiceSingleton single_instance = null; 

  private MyServiceSingleton() {
    this.value = 0;
  }

  // static method to create instance of Singleton class 
  public static MyServiceSingleton getInstance() { 
    if (single_instance == null) 
      single_instance = new MyServiceSingleton(); 

    return single_instance;
  } 

  int getValue() {
    return this.value;
  }

  void setValue(int v) {
    this.value = v;
  }

}
