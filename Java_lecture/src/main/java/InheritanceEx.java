import java.util.Scanner;

class Person{
    private int weight;
    int age;
    protected int height;
    public String name;

    public void setWeight(int weight){
        this.weight = weight;
    }

    public int getWeight(){
        return this.weight;
    }
}

class Student extends Person{
    public void set(int age, String name, int height, int weight){
        this.age = age;
        this.name = name;
        this.height = height;
        setWeight(weight);
    }

    public void print(){
        System.out.println("이름은 " + name + " 나이는 " + age + " 키는 " + height + " 몸무게는 " + getWeight());
    }
}

public class InheritanceEx {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("나이, 이름, 키(정수), 몸무게(정수) 를 차례대로 입력하세요 (띄어쓰기로 구분) >> ");

        int age = scanner.nextInt();
        String name = scanner.next();
        int height = scanner.nextInt();
        int weight = scanner.nextInt();
        Student s = new Student();
        s.set(age, name, height, weight);
        s.print();
    }
}
