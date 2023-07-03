package com.example.test;

import com.example.OperateDB.OperateDB;

/**
 * @projectName: demo
 * @package: com.example.test
 * @className: Test
 * @author: Axing
 * @description: TODO
 * @date: 2023/6/30 17:36
 * @version: 1.0
 */
public class Test {
    public static void main(String[] args) {
        OperateDB.connect();
        OperateDB.insertUser("444","1","1","1","1");
        OperateDB.closeDB();
    }

}
