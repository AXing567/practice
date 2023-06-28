package com.example.servlet;

import com.example.LoginService.Login;
import com.example.connectDB.OperateDB;
import com.google.gson.Gson;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

@WebServlet("/LoginServlet")  //这是就是路由的配置
public class LoginServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws IOException {

//        设置编码格式
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");

//        链接数据库
        OperateDB operateDB = new OperateDB();
        operateDB.connect();

//        获取前端传来的数据
        StringBuilder requestBody = new StringBuilder();
        BufferedReader reader = request.getReader();
        String line;
        while ((line = reader.readLine()) != null) {
            requestBody.append(line);
        }
        reader.close();

//        创建用于登录的类、用于返回map的对象、json处理对象
        Login loginService = new Login();
        Map<String, Object> map = new HashMap<>();
        Gson gson = new Gson();

//        当没有输入用户名和密码时返回的结果
        if (requestBody.toString().equals("")) {
            map.put("checkCode", loginService.LoginResultFalse());
            response.getWriter().write(gson.toJson(map));
        } else {
//            否则根据数据库，检测是否登录成功，并返回结果至客户端
            map = gson.fromJson(requestBody.toString(), Map.class);
            String uname = map.get("uname").toString();
            String upwd = map.get("upwd").toString();
            map.put("checkCode", loginService.login(uname, upwd,operateDB));
            map.put("token", UUID.randomUUID().toString());
//            将map转换为json并输出到前端
            response.getWriter().write(gson.toJson(map));
        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }
}
