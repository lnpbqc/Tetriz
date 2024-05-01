# Tetriz

> [项目来源:【手把手教你写俄罗斯方块：6-俄罗斯方块的表示和旋转】](https://www.bilibili.com/video/BV1gx42127RM)
6

### 控制台字符
> [参考来源](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)

![相关控制](./readme_img/image.png)

![16色](./readme_img/image2.png)

![256色](./readme_img/image3.png)


### tc 命名空间函数

> void move_to(int row,int col);
> 移动到某行某列

> void set_fore_color(int id);
> 设置前景色

> void set_back_color(int id);
> 设置背景色

> void clean_screen();
> 清空屏幕

> void reset_color();
> 重置颜色


> void hide_cursor();
> 隐藏指针

> void show_cursor();
> 显示指针

### utils 命名空间

> int fps();
> 返回刷新次数

> inline int b2c(int bindex);
> 两列为一个坐标

### draw 命名空间

> void window(int x,int y,int width,int height,std::string title);
> 在x,y(两个内容算一个y像素)处画一个width宽,height高的窗口

### game 命名空间

> void window(int x,int y,int width,int height,std::string title);
> 在x,y(两个内容算一个y像素)处画一个width宽,height高的窗口

> int row();
> 返回行数

> int col();
> 返回列数


> char getch();
> 无缓冲,无回显返回读取的字符串

> void key_event();
> 处理键盘事件

> bool is_running();
> 返回运行状态

> void start_key_listener();
> 开始键盘监听

> void init();
> 初始化


> void command_quit();
> 退出函数

> void command_rotate();
> 旋转函数

> void command_left();
> 左移函数

> void command_right();
> 右移函数

> void command_down();
> 下降函数
