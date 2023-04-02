package Java.OtherTest;

import java.util.*;

public class IteratorTest{
    public static void main(String[] args) {
        ArrayList list = new ArrayList();
        list.add("小明");
        list.add("小李");
        list.add("小刚");
        list.add("小赵");
        Iterator it = list.iterator();
        while (it.hasNext()){
            if (it.next().equals("小李")){
                it.remove();
            }
        }
        System.out.println(list);
    }
}