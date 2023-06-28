package com.example.LoginService;

import java.sql.*;

import com.example.connectDB.OperateDB;

public class Login {
    //    根据用户名和密码查询用户信息
    /**
     * @param userName: 用户名
     * @param password: 密码
     * @param operateDB: 链接数据库的类
     * @return LoginResult
     * @author Axing
     * @description 根据数据库中查询的用户名和密码判断返回怎样的登录信息
     * @date  2023/6/28 17:29
     */

    public LoginResult login(String userName, String password ,OperateDB operateDB) {
        LoginResult result = new LoginResult();


        // 查询用户信息
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            rs = operateDB.selectUser(userName, password);
            if (rs.next()) {
                result.setSuccess(true);
                result.setMessage("登录成功");
                result.setPermission(rs.getInt("permission"));
            } else {
                result.setSuccess(false);
                result.setMessage("用户名或密码错误");
                result.setPermission(0);
            }
        } catch (SQLException e) {
            result.setSuccess(false);
            result.setMessage("数据库查询失败");
            result.setPermission(0);
        } finally {
            // 关闭数据库连接
            operateDB.closeDB();
        }
        return result;
    }

    //    用户名或密码为空时返回的结果
    public LoginResult LoginResultFalse() {
        LoginResult result = new LoginResult();
        result.setSuccess(false);
        result.setMessage("用户名及密码不能为空");
        result.setPermission(0);
        return result;
    }
}

class LoginResult {
    private boolean success; // 是否成功
    private String message; // 登录信息
    private int permission; // 用户权限

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
