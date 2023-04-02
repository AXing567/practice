package Java.OtherTest;

import java.util.*;

public class PropertiesTest {
    public static void main(String[] args) {
        Properties p = new Properties();
        p.setProperty("backgroup-color", "red");
        p.setProperty("Font-size", "14px");
        p.setProperty("Language", "Chinese");
        Enumeration names = p.propertyNames();
        while (names.hasMoreElements()) {
            String key = (String) names.nextElement();
            String value = p.getProperty(key);
            System.out.println(key + ':' + value);

        }
    }
}
