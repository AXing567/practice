<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录</title>
</head>
<body>
<form action="LoginServlet" method="post">    <!--这代表着指向loginServlet后台服务器,用的时POST的提交方法-->
    姓名: <input type="text" name="uname"><br>
    密码: <input type="password" name="upwd"><br>
    <!--这句话的作用是获取后台作用域中的对象,并显示在客户端-->
    <button>登录</button><span style="color:red; font-size:16px;"><%=request.getAttribute("msg")%></span>

</form>
</body>
</html>
