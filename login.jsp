<%@ page language="java" import="java.util.*" contentType="text/html; charset=utf-8" %>
<html>
<head>
    <title>login</title>
    <link href="https://cdn.bootcss.com/twitter-bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet">
    <script src="https://cdn.bootcss.com/jquery/2.2.4/jquery.min.js"></script>
    <script src="https://cdn.bootcss.com/twitter-bootstrap/3.3.6/js/bootstrap.min.js"></script>
</head>
<body style="background: url(https://cn.bing.com/th?id=OHR.GuaitaTower_EN-CN7249728979_1920x1080.jpg&rf=LaDigue_1920x1080.jpg&pid=hp) no-repeat center center fixed; background-size: 100%;">
<form action="${pageContext.request.contextPath}/dologin.jsp" method="post">
    <div class="modal-dialog" style="margin-top: 10%;">
        <div class="modal-content">
            <div class="modal-header">
                <h4 class="modal-title text-center" id="myModalLabel">登录</h4>
            </div>
            <div class="modal-body" id = "model-body">
                <div class="form-group">

                    <input type="text" name="username" class="form-control" placeholder="用户名" autocomplete="off">
                </div>
                <div class="form-group">

                    <input type="password" name="password" class="form-control" placeholder="密码" autocomplete="off">
                </div>
            </div>
            <div class="modal-footer">
                <div class="form-group">
                    <button type="submit" class="btn btn-primary form-control">登录</button>
                </div>
            </div>
        </div>
    </div>
</form>
</body>
</html>

<%@ page language="java" import="java.util.*" contentType="text/html; charset=utf-8" %>
<%
    String path = request.getContextPath();
    String basePath = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + path + "/";
%>
<html>
<head>
    <title>Error</title>
    <link href="https://cdn.bootcss.com/twitter-bootstrap/3.3.1/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div class="container">
    <div class="row clearfix">
        <div class="col-md-12 column">
            <div class="alert alert-dismissable alert-danger">
                <button type="button" class="close" data-dismiss="alert" aria-hidden="true">×</button>
                <h4>登录失败!</h4>
                <strong>请检查用户名或密码！</strong><a href="login.jsp" class="alert-link">3s后自动跳转</a>
            </div>
        </div>
    </div>
</div>
<script>
    setTimeout('location.href="login.jsp"', 3000);
</script>
</body>
</html>



<%@ page language="java" import="java.util.*" contentType="text/html; charset=utf-8" %>
<html>
<head>
    <title>Success</title>
    <link href="https://cdn.bootcss.com/twitter-bootstrap/3.3.1/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<%
    String loginUser = "";
    if (session.getAttribute("loginUser") != null) {
        loginUser = session.getAttribute("loginUser").toString();
    }
%>
<div class="container">
    <div class="row clearfix">
        <div class="col-md-12 column">
            <div class="alert alert-dismissable alert-success">
                <button type="button" class="close" data-dismiss="alert" aria-hidden="true">×</button>
                <h4>
                    登陆成功！
                </h4> <strong>欢迎您！</strong> <font color="red"><%=loginUser%></font> <a href="login.jsp" class="alert-link">点击返回登陆界面</a>
            </div>
        </div>
    </div>
</div>
</body>
</html>



<%@ page language="java" import="java.util.*" contentType="text/html; charset=utf-8" %>
<%
    String username = "";
    String password = "";
    request.setCharacterEncoding("utf-8");//防止中文乱码

    username = request.getParameter("username");
    password = request.getParameter("password");

    //如果用户和密码都等于admin,则登录成功
    if ("admin".equals(username) && "admin".equals(password)) {
        session.setAttribute("loginUser", username);
        request.getRequestDispatcher("login_success.jsp").forward(request, response);

    } else {
        response.sendRedirect("login_failure.jsp");
    }
%>


