package Java.IO.OtherIOTest;

import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.io.FileOutputStream;

public class ObjectOutputStreamTest {
    public static void main(String[] args) {
        FileOutputStream fos = null;
        ObjectOutputStream oos = null;
        Person p = new Person(20, "张三");
        try {
            //首先创建一个文件输出流，用于将对象写入文件
            fos = new FileOutputStream("OtherIOTest/test.txt");
            //用ObjectOutputStream包装文件输出流，使其具有写入对象的功能
            oos = new ObjectOutputStream(fos);
            System.out.println("写入对象前：" + p.getName() + " " + p.getAge());
            //将对象写入文件
            oos.writeObject(p);
        } catch (Exception e){
            e.printStackTrace();
        } finally {
            try {
                if (oos != null) {
                    oos.close();
                }
                System.out.println("如果没有报错，那么写入成功！");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        

    }
}

class Person implements Serializable{
    // 该类必须实现Serializable接口，否则会报错
    private int age;
    private String name;

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }
}
