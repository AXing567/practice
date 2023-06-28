package com.example.demo;

import com.example.connectDB.LoginService;
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


@WebServlet("/LoginServlet")  //这是就是路由的配置
public class LoginServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

//        设置编码格式
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");

//        获取前端传来的数据
        StringBuilder requestBody = new StringBuilder();
        BufferedReader reader = request.getReader();
        String line;
        while ((line = reader.readLine()) != null) {
            requestBody.append(line);
        }
        reader.close();

        LoginService loginService = new LoginService();
        Map<String, Object> map = new HashMap<>();
        Gson gson = new Gson();

//        当没有输入用户名和密码时返回的结果
        if (requestBody.toString().equals("")) {
            map.put("checkCode", loginService.LoginResultFalse());
            response.getWriter().write(gson.toJson(map));
            return;
        }

//        检测是否登录成功
        map = gson.fromJson(requestBody.toString(), Map.class);
        String uname = map.get("uname").toString();
        String upwd = map.get("upwd").toString();
        map.put("checkCode", loginService.login(uname, upwd));

//        将map转换为json并输出到前端
        response.getWriter().write(gson.toJson(map));

    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }
}
