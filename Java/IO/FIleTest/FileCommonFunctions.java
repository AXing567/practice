package Java.IO.FIleTest;

import java.io.File;

public class FileCommonFunctions {
    //    文件类常用方法测试
    public static void main(String[] args) {
        File file = new File("E:\\CodeAll\\Java\\FIleTest\\example.txt");
        System.out.println("Tests whether the file or directory denoted by this abstract pathname exists:" + file.exists());
        System.out.println("文件名称" + file.getName());
        System.out.println("文件的相对路径" + file.getPath());
        System.out.println("文件的绝对路径" + file.getAbsoluteFile());
        System.out.println("文件的父路径" + file.getParent());
        System.out.println(file.canRead() ? "The file cna read" : "The file can't read");
        System.out.println(file.canWrite() ? "The file can write" : "The file can't write");
        System.out.println(file.isFile() ? "This is a file." : "This isn't a file");
        System.out.println(file.isDirectory() ? "This is a directory" : "This isn't a directory");
        System.out.println(file.isAbsolute() ? "This is a absolute path" : "This isn't a absolute path");
        System.out.println("The last modified time is " + file.lastModified());
        System.out.println("The file size is " + file.length() + "bytes");
        System.out.println("Was the file successfully deleted? " + file.delete());

    }
}
