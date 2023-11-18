--[[
    1.nil:空类型
        1)位变量赋值给nil相当于删除变量的作用
            x = nil
        2)nil作比较时应该加上双引号
            print(type(X)=="nil")

    2.boolean:布尔类型
        1)只有true/false,lua把false和nil看作false，其余（包括数字0）看作true

    3，number:数字类型
        2)lua默认只有一种 number 类型 -- double（双精度）类型

    4.string:字符串
        1)字符串由一对双引号或单引号来表示，也可以用两个双括号表示一块字符串<见下方>
            string1 = "this is string1"
            string2 = 'this is string2'
        2)对数字字符串上进行算术操作时，Lua 会尝试将这个数字字符串转成一个数字
            print("2" + 6)
        3)利用..拼接字符串
            string4 = "a" .. "b"
        4)在字符串之前加#返回字符串长度
            len = #string3

    5.table:表
        1)table 的创建是通过"构造表达式"来完成，最简单构造表达式是{}，用来创建一个空表。也可以在表里添加一些数据，直接初始化表
            local tbl1 = {}   --创建一个空表
            local tbl2 = {"apple", "pear", "orange", "grape"}   --直接初始化表
        2)lua语言里表的默认索引从1开始
        3)table 不会固定长度大小，有新数据添加时 table 长度会自动增长，没初始的 table 都是 nil
       
    6.function:函数
        1)在 Lua 中，函数是被看作是"第一类值（First-Class Value）"，函数可以存在变量里
            function myfun(val)
                ...
                ...
                return xx
            end
            调用：
                print(myfun(x))
                myfun_copy = myfun
                print(myfun_copy(x))
        2)function 可以以匿名函数（anonymous function）的方式通过参数传递

]]

--测试nil
print("------------------------------------------------")
print("nil test")
print(X)
print(type(X)==nil)   -- 错误用法
print(type(X)=="nil")

--测试boolean
print("------------------------------------------------")
print("boolean test")
print(type(true))
print(type(false))
print(type(nil))
if false or nil then
    print("至少有一个是 true")
else
    print("false 和 nil 都为 false")
end
if 0 then
    print("数字 0 是 true")
else
    print("数字 0 为 false")
end

--测试number
print("------------------------------------------------")
print("number test")
print(type(2e+1))

--测试string
print("------------------------------------------------")
print("string test")
string1 = "this is string1"
print(string1)
string2 = 'this is string2'
print(string2)
string3 = [[
    line1
    line2
    line3
]]
print(string3)
print("2" + 6)
print("2" + "6")   -- 字符串自动转化为数字运算
string4 = "a" .. "b"
print(string4)
len = #string3
print(len)

--测试table
print("------------------------------------------------")
print("table test")
a = {}
a["key"] = "value"   --键值对
key = 10
a[key] = 22
a[key] = a[key] + 11
for k, v in pairs(a) do
    print(k .. " : " .. v)
end

tbl = {"apple", "pear", "orange", "grape"}
for key, val in pairs(tbl) do
    print("Key", key)
end

a3 = {}
for i = 1, 10 do
    a3[i] = i
end
a3["key"] = "val"
print(a3["key"])
print(a3["none"])
print(#a3)

--测试function
print("------------------------------------------------")
print("function test")

function factorial1(n)   -- 使用递归实现阶乘
    if n == 0 then
        return 1
    else
        return n * factorial1(n - 1)
    end
end   
print(factorial1(5))
factorial2 = factorial1
print(factorial2(5))

--匿名函数方法
function testFun(tab,fun)
    for k ,v in pairs(tab) do
            print(fun(k,v));
    end
end

tab={key1="val1",key2="val2"};
testFun(tab,
function(key,val)   -- 匿名函数<顾名思义，没有名字，直接调用>
    return key.."="..val;
end
);
