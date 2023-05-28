package com.example.demo;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;


@WebServlet("/LoginServlet")  //这是就是路由的配置
public class LoginServlet  extends HttpServlet {
    @Override
    protected  void service(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException{
        //设置客户端的编码格式
        request.setCharacterEncoding("UTF-8");
        //接受客户端传递的参数
        String uname= request.getParameter("uname");
        String upwd=request.getParameter("upwd");

        //用来判断用户名是否为空
        if (uname==null || "".equals(uname.trim()))
        {
            //用于提示用户信息
            request.setAttribute("msg","用户名不能为空");
            //请求跳转转换到login.jsp
            request.getRequestDispatcher("login.jsp").forward(request,response);
            return;

        }

        //用来判断密码是否为空
        if (upwd==null || "".equals(upwd.trim()))
        {
            //用于提示用户信息
            request.setAttribute("msg","密码不能为空");
            //请求跳转转换到login.jsp
            request.getRequestDispatcher("login.jsp").forward(request,response);
            return ;

        }
        //此处用来判断用户名和密码是否正确,这里暂且规定密码和用户名的正确值都是admin
        if (!"admin".equals(uname)||!"admin".equals(upwd))
        {
            //提示用户信息
            request.setAttribute("msg","用户登录失败");
            //请转发到login.jsp
            request.getRequestDispatcher("login.jsp").forward(request,response);
            return ;
        }


        //设置登录界面
        request.getSession().setAttribute("uname",uname);
        //如果这些判断都没有执行,那么就运行成功,跳转到index.jsp
        response.sendRedirect("index.jsp");

    }

}
