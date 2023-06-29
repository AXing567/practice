package com.example.loginService;

import java.sql.*;

import com.example.operateDB.OperateDB;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Login {
    /*日志记录器*/
    Logger logger = LoggerFactory.getLogger(Login.class);

    /**
     * @param userName:  用户名
     * @param password:  密码
     * @return LoginResult
     * @author Axing
     * @description 根据数据库中查询的用户名和密码判断返回怎样的登录信息。在此方法中，不考虑用户名或密码为空的情况
     * @date 2023/6/28 17:29
     */
    public LoginResult login(String userName, String password) {
        LoginResult result = new LoginResult();


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
                result.setToken("00000000000000000000");
                logger.info("用户名或密码错误");
            }
        } catch (SQLException e) {
            result.setSuccess(false);
            result.setMessage("数据库查询失败");
            result.setPermission(0);
            result.setToken("00000000000000000000");
            logger.warn("数据库查询失败");
        } finally {
            // 关闭数据库连接
//            operateDB.closeDB();
        }
        return result;
    }


    /**
     * @return LoginResult 登录错误信息类，参考com.example.loginService.LoginResult类
     * @author Axing
     * @description 用户名或密码为空时返回的结果
     * @date 2023/6/29 8:09
     */
    public LoginResult LoginResultFalse() {
        LoginResult result = new LoginResult();
        result.setSuccess(false);
        result.setMessage("用户名及密码不能为空");
        result.setPermission(0);
        result.setToken("00000000000000000000");
        return result;
    }
}

/**
 * @author Axing
 * @description 登录信息类，包含了登录是否成功，登录信息，用户权限，用户token
 * @date 2023/6/29 10:16
 */
class LoginResult {
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
