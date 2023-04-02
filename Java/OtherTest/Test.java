package Java.OtherTest;

class Student {
    private String name;
    private String id;

    public String getName() {
        return name;
    }

    public String getId() {
        return id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Student() {
    }

}

public class Test {
    public static void main(String[] args) {
        Student s1 = new Student();
        // int a;
        s1.setId("123");
        s1.setName("haha");
        System.out.println("学生姓名：" + s1.getName());
        System.out.println("学生学号：" + s1.getId());
        System.out.println("hello world");
    }
}
