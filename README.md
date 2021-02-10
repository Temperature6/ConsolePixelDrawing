# 控制台像素画图

### 功能

​		使用方向键控制指针在命令提示符中通过打印#、@、*、%的方式画出图像

### 操作

​		开始之前右击窗口左上角，属性——布局——调整大小时对输出的文本换行——取消勾选
​		注意：在光标到达窗口边界之前调整窗口大小防止出现问题
​		按下#、@、*、%对应的数字按键切换画笔，按下“s”键保存，按下“0”切换为橡皮,按下空格键抬起\放下画笔
​		颜色对应的按键：B-兰 G-绿 C-青 R-红 M-洋红 D-深灰 Y-黄 W-白

### 命令行调用程序

启动后直接跳转到新建画布界面

```
控制台像素画图.exe /n
```

使用命令行调用程序打开文件，/path为文件路径，不能含有空格和特殊字符

```
控制台像素画图.exe /f /path
```

启动后直接跳转到操作说明界面

```
控制台像素画图.exe /h
```

启动后打开GitHub仓库

```
控制台像素画图.exe /g
```

### 文件

​	**控制台像素画图.exe**  主程序文件

​	**fileanalysis.dll**  用于读取、储存画图文件的可供调用的动态链接库

### 说明

​	很多设计没有必要，比如动态链接库和命令行调用，只是一种新的尝试