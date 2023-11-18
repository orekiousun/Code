--[[
    1.注释方法
        单行注释--
        多行注释<如外围所示>
        
    2.标识符
        以一个字母 A 到 Z 或 a 到 z 或下划线 _ 开头后加上 0 个或多个字母

    3.关键词：以下关键词不能用于定义变量
        and	break	do	else
        elseif	end	false	for
        function	if	in	local
        nil	not	or	repeat
        return	then	true	until
        while	goto		
        
    4.全局变量：在默认情况下，变量总是认为是全局的
        删除全局变量：将变量赋值位nil<类似于null>
]]
print(b)   -- 返回nil
b = 10
print(b)   -- 返回b的值
b = nil
print(b)   -- 返回nil