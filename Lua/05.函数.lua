--[[
    1.函数定义
        (local) function function_name( argument1, argument2, argument3..., argumentn)
            function_body
            return result1, resul2
        end
        ·默认为全局函数，如果要设置成局部函数则需要在function之前添加关键字local
        ·函数参数，多个参数以逗号隔开，函数也可以不带参数
        ·返回值可以有多个，每个以逗号隔开
            function max(num1, num2)
                if (num1 > num2) then
                result = num1;
                else
                result = num2;
                end
                return result;
            end
            -- 调用函数
            print("两值比较最大值为 ",max(10,4))
            print("两值比较最大值为 ",max(5,6))

    2.可以将函数作为参数传递给函数
        myprint = function(param)
        print("这是打印函数 -   ##",param,"##")
        end

        function add(num1,num2,functionPrint)
        result = num1 + num2
        -- 调用传递的函数参数
        functionPrint(result)
        end
        myprint(10)
        -- myprint 函数作为参数传递
        add(2,5,myprint)

    3.多返回值：函数可以有多个返回值
        function maximum (a)
            local mi = 1             -- 最大值索引
            local m = a[mi]          -- 最大值
            for i,val in ipairs(a) do
            if val > m then
                mi = i
                m = val
            end
            end
            return m, mi
        end
        调用：
        print(maximum({8,10,23,12,5}))

    4.可变参数：Lua 函数可以接受可变数目的参数，和 C 语言类似，在函数参数列表中使用三点 ... 表示函数有可变的参数<注意是三个点>
        function add(...)  
        local s = 0  
        for i, v in ipairs{...} do   --> {...} 表示一个由所有变长参数构成的数组  
            s = s + v  
        end  
        return s  
        end  
        print(add(3,4,5,6,7))  --->25，可以输入多个参数

        通过select获取可变参数的数量
        function average(...)
            result = 0
            local arg={...}
            for i,v in ipairs(arg) do
                result = result + v
            end
            print("总共传入 " .. select("#",...) .. " 个数")
            return result/select("#",...)
        end
        print("平均值为",average(10,5,3,4,5,6))

        固定参数加上可变参数，固定参数要放在变长参数之前
        function fwrite(fmt, ...)  ---> 固定的参数fmt
            return io.write(string.format(fmt, ...))    
        end
        fwrite("runoob\n")       --->fmt = "runoob", 没有变长参数。  
        fwrite("%d%d\n", 1, 2)   --->fmt = "%d%d", 变长参数为 1 和 2
        
    5.通过select访问变长参数
        select('#', …) 返回可变参数的长度
        select(n, …) 用于返回从起点 n 开始到结束位置的所有参数列表
]]

-- 函数定义
print("------------------------------------------------")
function max(num1, num2)
    if (num1 > num2) then
       result = num1;
    else
       result = num2;
    end
    return result;
 end
 print("两值比较最大值为 ",max(10,4))
 print("两值比较最大值为 ",max(5,6))

-- 将函数作为参数传参
print("------------------------------------------------")
myprint = function(param)
    print("这是打印函数 -   ##",param,"##")
end
function add(num1,num2,functionPrint)
    result = num1 + num2
    -- 调用传递的函数参数
    functionPrint(result)
end
myprint(10)
-- myprint 函数作为参数传递
add(2,5,myprint)

-- 多返回值
print("------------------------------------------------")
function maximum (a)
    local mi = 1             -- 最大值索引
    local m = a[mi]          -- 最大值
    for i,val in ipairs(a) do
    if val > m then
        mi = i
        m = val
    end
    end
    return m, mi
end
print(maximum({8,10,23,12,5}))

-- 可变参数
print("------------------------------------------------")
function add(...)  
    local s = 0  
    for i, v in ipairs{...} do   --> {...} 表示一个由所有变长参数构成的数组  
        s = s + v  
    end  
    return s  
end  
print(add(3,4,5,6,7))  --->25，可以输入多个参数

-- 变长参数
print("------------------------------------------------")
function fwrite(fmt, ...)  ---> 固定的参数fmt
    return io.write(string.format(fmt, ...))    
end
fwrite("runoob\n")       --->fmt = "runoob", 没有变长参数。  
fwrite("%d%d\n", 1, 2)   --->fmt = "%d%d", 变长参数为 1 和 2

-- select
print("------------------------------------------------")
function f(...)
    a = select(3,...)  -->从第三个位置开始，变量 a 对应右边变量列表的第一个参数
    print (a)
    print (select(3,...)) -->打印所有列表参数
end
f(0,1,2,3,4,5)

function foo(...)  
    for i = 1, select('#', ...) do  -->获取参数总数
        local arg = select(i, ...); -->读取参数，arg 对应的是右边变量列表的第一个参数
        print("arg", arg);  
    end  
end  

foo(1, 2, 3, 4);  