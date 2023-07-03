package com.example.OperateDB;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.sql.*;

public class OperateDB {
    private static Connection conn;
    private static PreparedStatement pstmt;
    private static ResultSet rs;
    /*日志记录器*/
    static Logger logger = LoggerFactory.getLogger(OperateDB.class);


    /**
     * @author Axing
     * @description 链接数据库
     * @date 2023/6/28 16:30
     */
    public static void connect() {
        try {
            logger.info("数据库准备连接");
            Class.forName("com.mysql.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/school";
            conn = DriverManager.getConnection(url, "root", "123");
            logger.info("数据库连接成功");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    /**
     * @param name:
     * @param mobilePhone:
     * @param userName:
     * @param password:
     * @param token:
     * @return boolean 是否插入成功，成功返回true，否则返回false
     * @author Axing
     * @description 向数据库中插入一条新的用户数据（姓名，手机号，用户名，密码，token）token由TokenUtil.generateToken()生成
     * @date 2023/6/30 17:57
     */
    public static boolean insertUser(String name, String mobilePhone, String userName, String password, String token) {
        try {
            pstmt = conn.prepareStatement("insert into user(userName,password,mobilePhone,token,name) values(?,?,?,?,?)");
            pstmt.setString(1, userName);
            pstmt.setString(2, password);
            pstmt.setString(3, mobilePhone);
            pstmt.setString(4, token);
            pstmt.setString(5, name);
            if (pstmt.executeUpdate() == 1) {
                logger.info("新建用户数据成功");
                return true;
            } else {
                logger.error("新建用户数据失败");
                return false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            logger.error("新建用户数据异常（插入数据至mysql）");
        }
        return false;
    }

    /**
     * @param token:
     * @param userName:
     * @return boolean 更新成功返回true，否则返回false
     * @author Axing
     * @description 根据用户名更新token
     * @date 2023/6/29 10:22
     */
    public static boolean update(String token, String userName) {
        try {
            pstmt = conn.prepareStatement("update user set token = ? where userName = ?");
            pstmt.setString(1, token);
            pstmt.setString(2, userName);
            return pstmt.executeUpdate() == 1;
        } catch (Exception e) {
            e.printStackTrace();
            logger.error("更新token异常");
        }
        return false;
    }

    /**
     * @param userName:
     * @return boolean
     * @author Axing
     * @description 根据用户名查询是否存在此用户
     * @date 2023/6/30 18:39
     */
    public static boolean selectUserName(String userName) {
        try {
            pstmt = conn.prepareStatement("select * from user where userName = ?");
            pstmt.setString(1, userName);
            return pstmt.executeQuery() != null;
        } catch (Exception e) {
            e.printStackTrace();
            logger.info("查找userName异常");
        }
        return false;
    }
    /**
     * @param token:
     * @param userName:
     * @return ResultSet
     * @author Axing
     * @description 根据token判断是否存在此token，存在则返回一个true，否则返回false。验证token时可以通过此方法判断token是否存在
     * @date 2023/6/29 10:24
     */
    public static boolean selectToken(String token, String userName) {
        try {
            pstmt = conn.prepareStatement("select * from user where token = ? and userName = ?");
            pstmt.setString(1, token);
            pstmt.setString(2, userName);
            return pstmt.executeQuery() != null;
        } catch (Exception e) {
            e.printStackTrace();
            logger.info("查找token异常（当有此报错的时候，selectToken()的返回值为空）");
        }
        return false;
    }

    /**
     * @param userName: 用户名
     * @param password: 密码
     * @return ResultSet
     * @author Axing
     * @description 查询用户名和密码后返回一个对象如登录信息，权限等。参考com.example.LoginService.LoginResult类
     * @date 2023/6/28 16:30
     */
    public static ResultSet selectUser(String userName, String password) {
        try {
            pstmt = conn.prepareStatement("SELECT * FROM user WHERE userName = ? AND password = ?");
            pstmt.setString(1, userName);
            pstmt.setString(2, password);
            return pstmt.executeQuery();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return rs;
    }

    /**
     * @author Axing
     * @description 关闭数据库
     * @date 2023/6/28  16:36
     */
    public static void closeDB() {
        try {
            if (rs != null) rs.close();
            if (pstmt != null) pstmt.close();
            if (conn != null) conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
