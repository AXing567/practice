package Java.IO.FIleTest;

import java.io.File;
import java.io.FilenameFilter;

public class Traverse2 {
    //    用过滤器遍历目录下的所有文件名
    public static void main(String[] args) {
        File file = new File("E:\\CodeAll\\Java\\FIleTest");
        FilenameFilter filter = new FilenameFilter() {
            public boolean accept(File dir, String name) {
                File currFile = new File(dir, name);
                return currFile.isFile() && name.endsWith(".java");
            }
        };
        if (file.exists()) {
            String[] lists = file.list(filter);
            if (lists != null) {
                for (String name : lists){
                    System.out.println(name);
                }
            }
        }
    }
}
