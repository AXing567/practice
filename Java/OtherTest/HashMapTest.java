package Java.OtherTest;

import java.util.*;

public class HashMapTest {
    public static void main(String[] args) {
        Map hm = new TreeMap();
        hm.put(123,"张三");
        hm.put(129,"李四");
        hm.put(124,"王五");
        Set keySet = hm.keySet();
        Iterator it = keySet.iterator();
        while(it.hasNext()){
            Object key = it.next();
            Object value = hm.get(key);
            System.out.println(key + ":" + value);
        }

    }
}
