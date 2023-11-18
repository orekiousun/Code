--[[
    1.while
        while(condition) do
            statements
        end
        
    2.for:var 从 exp1 变化到 exp2，每次变化以 exp3 为步长递增 var，并执行一次 "执行体"。exp3 是可选的，如果不指定，默认为1
        for var=exp1,exp2,exp3 do  
            <执行体>  
        end  
        
    3.泛型for:通过迭代器遍历所有值
        a = {"one", "two", "three"}
        for i, v in ipairs(a) do   
            print(i, v)
        end 

    4.repeat...until:在当前循环结束后判断
        repeat
            statements
        until( condition )
    循环可以嵌套

    5.循环控制语句
        break   --退出当前循环或语句，并开始脚本执行紧接着的语句
        goto   --将程序的控制点转移到一个标签处
            local a = 1
            ::label:: print("--- goto label ---")

            a = a+1
            if a < 3 then
                goto label   -- a 小于 3 的时候跳转到标签 label
            end
            输出结果为：
            --- goto label ---
            --- goto label ---

    6.无限循环
        while( true )
        do
            print("循环将永远执行下去")
        end

    7.if判断语句 同样判断也可以嵌套
        if( 布尔表达式 1)
        then
            --[ 在布尔表达式 1 为 true 时执行该语句块 --]
        elseif( 布尔表达式 2)
        then
            --[ 在布尔表达式 2 为 true 时执行该语句块 --]
        elseif( 布尔表达式 3)
        then
            --[ 在布尔表达式 3 为 true 时执行该语句块 --]
        else 
            --[ 如果以上布尔表达式都不为 true 则执行该语句块 --]
        end
]]

--while 
print("------------------------------------------------")
a=10
while( a < 20 )
do
   print("a 的值为:", a)
   a = a+1
end

--for
print("------------------------------------------------")
for i=10,1,-1 do
    print(i)
end

for i, v in ipairs(a) do   
    print(i, v)
end 

--repeat until
print("------------------------------------------------")
a = 10
repeat
   print("a的值为:", a)
   a = a + 1
until( a > 15 )

--循环嵌套
print("------------------------------------------------")
j =2
for i=2,10 do
   for j=2,(i/j) , 2 do
      if(not(i%j))
      then
         break
      end
      if(j > (i/j))then
         print("i 的值为：",i)
      end
   end
end

--if
print("------------------------------------------------")
a = 100
if( a == 10 )
then
   print("a 的值为 10" )
elseif( a == 20 )
then  
   print("a 的值为 20" )
elseif( a == 30 )
then
   print("a 的值为 30" )
else
   print("没有匹配 a 的值" )
end
print("a 的真实值为: ", a )