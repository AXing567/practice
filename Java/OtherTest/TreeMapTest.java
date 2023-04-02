package Java.OtherTest;

import java.util.*;

public class TreeMapTest {
    public static void main(String[] args) {
        Map tm = new TreeMap(new MyComparator());
        tm.put(1234, "小明");
        tm.put(1235, "小李");
        tm.put(1237, "小刚");
        tm.put(1236, "小陈");
        tm.put(1233, "小赵");
        Set set = tm.keySet();
        Iterator it = set.iterator();
        while (it.hasNext()) {
            Object key = it.next();
            Object value = tm.get(key);
            System.out.println(key + ":" + value);
        }
    }
}

class MyComparator implements Comparator {
    public int compare(Object obj1, Object obj2) {
        int i1 = (int) obj1;
        int i2 = (int) obj2;
        return i2 - i1;
    }
}
