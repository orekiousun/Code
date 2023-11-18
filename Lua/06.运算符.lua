--[[
    1.算术运算符
        + 加法 
        - 减法
        * 乘法 
        / 除法
        % 取余
        ^ 乘幂
        - 负号

    2.关系运算符
        == 等于，检测两个值是否相等，相等返回 true，否则返回 false
        ~= 不等于，检测两个值是否相等，不相等返回 true，否则返回 false
        >  大于，如果左边的值大于右边的值，返回 true，否则返回 false
        <  小于，如果左边的值大于右边的值，返回 false，否则返回 true
        >= 大于等于，如果左边的值大于等于右边的值，返回 true，否则返回 false
        <= 小于等于， 如果左边的值小于等于右边的值，返回 true，否则返回 false

    3.逻辑运算符<true为1，false为0>
        and 逻辑与操作符, 若 A 为 false，则返回 A，否则返回 B
        or  逻辑或操作符, 若 A 为 true，则返回 A，否则返回 B
        not 逻辑非操作符, 与逻辑运算结果相反，如果条件为 true，逻辑非为 false

    4.其他运算符
        ..  连接两个字符串
        #   返回当前字符串或表的长度

    5.运算符优先级：符合数学规律<从上到下>
        ^
        not    - (unary)
        *      /       %
        +      -
        ..
        <      >      <=     >=     ~=     ==
        and
        or
]]

-- 算术运算符
print("------------------------------------------------")
a = 21
b = 10
c = a + b
print("Line 1 - c 的值为 ", c )
c = a - b
print("Line 2 - c 的值为 ", c )
c = a * b
print("Line 3 - c 的值为 ", c )
c = a / b
print("Line 4 - c 的值为 ", c )
c = a % b
print("Line 5 - c 的值为 ", c )
c = a^2
print("Line 6 - c 的值为 ", c )
c = -a
print("Line 7 - c 的值为 ", c )

-- 关系运算符
print("------------------------------------------------")
a = 21
b = 10
if( a == b )
then
   print("Line 1 - a 等于 b" )
else
   print("Line 1 - a 不等于 b" )
end
if( a ~= b )
then
   print("Line 2 - a 不等于 b" )
else
   print("Line 2 - a 等于 b" )
end
if ( a < b )
then
   print("Line 3 - a 小于 b" )
else
   print("Line 3 - a 大于等于 b" )
end
if ( a > b )
then
   print("Line 4 - a 大于 b" )
else
   print("Line 5 - a 小于等于 b" )
end
a = 5
b = 20
if ( a <= b )
then
   print("Line 5 - a 小于等于  b" )
end
if ( b >= a )
then
   print("Line 6 - b 大于等于 a" )
end

--逻辑运算符
print("------------------------------------------------")
a = true
b = true
if ( a and b )
then
   print("a and b - 条件为 true" )
end
if ( a or b )
then
   print("a or b - 条件为 true" )
end
a = false
b = true
if ( a and b )
then
   print("a and b - 条件为 true" )
else
   print("a and b - 条件为 false" )
end
if ( not( a and b) )
then
   print("not( a and b) - 条件为 true" )
else
   print("not( a and b) - 条件为 false" )
end

-- 其他运算符
print("------------------------------------------------")
a = "Hello "
b = "World"
print("连接字符串 a 和 b ", a..b )
print("b 字符串长度 ",#b )
print("字符串 Test 长度 ",#"Test" )


