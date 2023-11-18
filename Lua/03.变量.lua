--[[
    1.变量分类
        1)全局变量
        2)局部变量
        3)表中的域
        Lua 中的变量全是全局变量，哪怕是语句块或是函数里，除非用 local 显式声明为局部变量
        局部变量的作用域为从声明位置开始到所在语句块结束<这十分特殊>

    2.赋值语句
        1)改变一个变量的值
            a = "hello" .. "world"
        2)对多个变量同时赋值
            a, b = 10, 2*x 
        3)交换变量
            x, y = y, x   -- 遇到赋值语句Lua会先计算右边所有的值然后再执行赋值操作，所以我们可以这样进行交换变量的值
        4)当变量个数和值的个数不一致时，Lua会一直以变量个数为基础采取以下策略
            a. 变量个数 > 值的个数             按变量个数补足nil
            b. 变量个数 < 值的个数             多余的值会被忽略
        5)多值赋值经常用来交换变量，或将函数调用返回给变量
            a, b = f()   -- f()返回两个值，第一个赋给a，第二个赋给b，尽可能使用局部变量，可以避免命名冲突，同时访问速度更快
            
    3.索引
        1)使用方括号   t[i]
        2)使用.   t.i 
        3)函数调用：gettable_event(t,i) -- 采用索引访问本质上是一个类似这样的函数调用
]] 

--测试变量
print("------------------------------------------------")
a = 5   -- 全局变量
local b = 5   -- 局部变量
function joke()
    c = 5   -- 全局变量
    local d = 6   -- 局部变量
end
joke()
print(c,d)   --> 5 nil，局部变量d不能被函数在外部引用
do
    local e = 6   -- 局部变量
    local a = 6
    b = 6   -- 对局部变量重新赋值，变为全局变量
    print(e, b);   --> 6 6
end
print(a, e, b)   -- a 在外部仍然为1全局变量

--测试赋值
print("------------------------------------------------")
a, b, c = 0, 1
print(a,b,c)   --> 0   1   nil
a, b = a+1, b+1, b+2   -- value of b+2 is ignored
print(a,b)   --> 1   2
a, b, c = 0   -- 常见错误
print(a,b,c)   --> 0   nil   nil

--测试索引
print("------------------------------------------------")
site = {}
site["key"] = "www.runoob.com"
print(site["key"])
print(site.key)
