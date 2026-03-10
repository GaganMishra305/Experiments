/* ABSTRACTION: using interface(implements), abstract-class(extends) */
abstract class Parent {
    void method() {
        System.out.println("Parent class method");
    }
}
interface oops {
    void method2();
}

class Child extends Parent implements oops{  /* INHERITANCE: single, hiarachial, multilevel  */
    void method() {
        System.out.println("Child class method");
    }

    @Override
    public void method2() { // polymorphism
    }
}

class Main {
    public static void main(String[] args) {
        Parent o2 = new Child(); // ENCAPSULATION
        o2.method();
    }
}