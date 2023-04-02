package Java.OtherTest;

import java.util.*;

public class HomeWork7 {
    public static void main(String[] args) {
        HomeWork7_3.runWork();
    }
}

class HomeWork7_1 {
    public static void runWork() {
        ArrayList<String> al = new ArrayList<String>();
        Date date = new Date();
        for (int i = 1; i <= 10; i++) {

            al.add(Integer.toString(i));
        }
        Iterator it = al.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
        Date date2 = new Date();
        System.out.println("running time:" + (date2.getTime() - date.getTime()));
    }
}

class HomeWork7_2 {
    class Person {
        private String name;
        private int age;

        public Person(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public int hasCode() {
            return name.hashCode();
        }

        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (!(obj instanceof Person)) {
                return false;
            }
            Person per = (Person) obj;
            return this.name.equals(per.name);
        }
    }

    public static void runWork() {
        Map<Integer, Person> map = new HashMap<Integer, Person>();// 题目让用set这里看成了map来做的了。。。。。。

        map.put(3, new HomeWork7_2().new Person("张三", 18));
        map.put(2, new HomeWork7_2().new Person("李四", 20));
        map.put(1, new HomeWork7_2().new Person("铁柱", 50));
        map.put(1, new HomeWork7_2().new Person("铁柱", 50));

        Set set = map.keySet();
        Iterator it = set.iterator();
        while (it.hasNext()) {
            int key = (int) it.next();
            HomeWork7_2.Person p = map.get(key);
            System.out.println(p.age + p.name);
        }

    }
}

class HomeWork7_3 {
    public static void runWork() {
        Map<String, String> map = new TreeMap<String, String>(new HomeWork7_3().new MyCompare());

        map.put("4", "Aimee");
        map.put("2", "John");
        map.put("5", "Amanda");
        map.put("1", "Lucy");
        map.put("3", "Smith");
        // System.out.println(map.);
        Set set = map.keySet();
        Iterator it = set.iterator(); 
        while (it.hasNext()) {
            String key = (String) it.next();
            String value = map.get(key);
            System.out.println(key + ":" + value);
        }
    }

    class MyCompare implements Comparator {
        public int compare(Object obj1, Object obj2) {
            String s1 = (String)obj1;
            String s2 = (String)obj2;

            return s2.compareTo(s1);

        }

    }

}