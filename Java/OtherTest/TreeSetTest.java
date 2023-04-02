package Java.OtherTest;

import java.util.*;

class S implements Comparator {
    public int compare(Object obj1, Object obj2) {
        String s1 = (String) obj1;
        String s2 = (String) obj2;
        return s1.length() - s2.length();

    }
}

public class TreeSetTest {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet(new S());
        ts.add("haha");
        ts.add("xiaoming");
        ts.add("xiaoagang");
        ts.add("xiaogang");

        Iterator it = ts.iterator();
        while(it.hasNext())
        {
            Object obj = it.next();
            System.out.println(obj);
        }
        System.out.println(ts);

    }
}
