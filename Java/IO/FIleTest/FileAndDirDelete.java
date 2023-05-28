package Java.IO.FIleTest;

import java.io.File;

public class FileAndDirDelete {
    public static void main(String[] args) {
        File file = new File("E:\\CodeAll\\Java\\FIleTest\\Test");
        deleteDir(file);
    }

    private static void deleteDir(File dir) {
        if (dir.exists()) {
            File[] files = dir.listFiles();
            if (files != null) {
                for (File file : files) {
                    if (file.isDirectory()) {
                        deleteDir(file);
                    } else {
                        System.out.println(file.getName() + "删除" + (file.delete() ? "成功" : "失败"));
                    }
                }
            }
            System.out.println(dir.getName() + "删除" + (dir.delete() ? "成功" : "失败"));
        }
    }
}
