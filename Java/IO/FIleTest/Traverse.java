package Java.IO.FIleTest;

import java.io.File;

public class Traverse {
    //    遍历目录下的所有文件名
    public static void main(String[] args) {
        File file = new File("E:\\CodeAll\\Java\\FIleTest");
        if (file.isDirectory()) {
            String[] list = file.list();
            if (list != null) {
                for (String string : list) {
                    System.out.println(string);
                }
            } else {
                System.out.println("The directory is empty.");
            }
        }

    }
}
