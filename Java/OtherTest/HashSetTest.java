package Java.OtherTest;

import java.util.*;

class Student1 {
    private String name;
    private String id;

    public Student1(String name, String id) {
        this.id = id;
        this.name = name;
    }

    public String toString() {
        return id + ':' + name;
    }

    public int hashCode() {
        return id.hashCode();
    }

    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (!(obj instanceof Student)) {
            return false;
        }
        Student1 stu = (Student1) obj;
        boolean b = this.id.equals(stu.id);
        return b;
    }
}

public class HashSetTest {
    public static void main(String[] args) {
        Student1 s1 = new Student1("小明", "1");
        Student1 s2 = new Student1("小明", "1");
        Student1 s3 = new Student1("小李", "1");
        HashSet h = new HashSet<>();
        h.add(s1);
        h.add(s2);
        h.add(s3);
        h.add(s1);

        System.out.println(h);

    }
}
