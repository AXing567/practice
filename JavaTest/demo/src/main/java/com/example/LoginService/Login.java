package com.example.LoginService;


import com.example.OperateDB.OperateDB;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author Axing
 * @description 登录，注册服务
 * @date 2023/6/30 18:19
 */
public class Login {
    /*日志记录器*/
    private static Logger logger = LoggerFactory.getLogger(Login.class);

    /**
     * @param userName:  用户名
     * @param password:  密码
     * @return LoginResult
     * @author Axing
     * @description 根据数据库中查询的用户名和密码判断返回怎样的登录信息。在此方法中，不考虑用户名或密码为空的情况
     * @date 2023/6/28 17:29
     */
    public static Result login(String userName, String password) {
        Result result = new Result();


        // 查询用户信息
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            rs = OperateDB.selectUser(userName, password);
            if (rs.next()) {
                result.setSuccess(true);
                result.setMessage("登录成功");
                result.setPermission(rs.getInt("permission"));
                /*如果登录成功，生成一个token并存放至数据库*/
                result.setToken(TokenUtil.generateToken(userName));
                logger.info("登录成功");
            } else {
                result.setSuccess(false);
                result.setMessage("用户名或密码错误");
                result.setPermission(0);
                result.setToken("000000000000000000000000000000000000");
                logger.info("用户名或密码错误");
            }
        } catch (SQLException e) {
            result.setSuccess(false);
            result.setMessage("数据库查询失败");
            result.setPermission(0);
            result.setToken("000000000000000000000000000000000000");
            logger.warn("数据库查询失败");
        } finally {
            // 关闭数据库连接
//            OperateDB.closeDB();
        }
        return result;
    }


    /**
     * @return Result 登录或注册结果，包含登录或注册是否成功，登录或注册信息，用户权限，用户token
     * @author Axing
     * @description 用户名或密码为空时返回的结果
     * @date 2023/6/29 8:09
     */
    public static Result Result(boolean success, String message, int permission, String token) {
        Result result = new Result();
        result.setSuccess(success);
        result.setMessage(message);
        result.setPermission(permission);
        result.setToken(token);
        return result;
    }
}

/**
 * @author Axing
 * @description 登录信息类，包含了登录是否成功，登录信息，用户权限，用户token
 * @date 2023/6/29 10:16
 */
class Result {
    private boolean success; // 是否成功
    private String message; // 登录信息
    private int permission; // 用户权限
    private String token; // 用户token

    public String getToken() {
        return token;
    }

    public void setToken(String token) {
        this.token = token;
    }

    public String toString() {
        return "LoginResult [success=" + success + ", message=" + message + ", permission=" + permission + "]";
    }


    public void setSuccess(boolean success) {
        this.success = success;
    }


    public void setMessage(String message) {
        this.message = message;
    }


    public void setPermission(int permission) {
        this.permission = permission;
    }
}

