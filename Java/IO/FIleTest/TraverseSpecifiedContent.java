package Java.IO.FIleTest;

import java.io.File;

public class TraverseSpecifiedContent {
    // 遍历指定目录及其子目录的文件及文件夹的绝对路径
    public static void main(String[] args) {
        File fIle = new File("E:\\CodeAll\\Java");
        fileDir(fIle);
    }

    private static void fileDir(File dir) {
        File[] files = dir.listFiles();
        if (files != null) {
            for(File file : files){
                if (file.isDirectory()) {
                    fileDir(file);
                }
                System.out.println(file.getAbsolutePath());
            }
        }
    }
}
