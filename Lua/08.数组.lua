--[[
    1.数组定义：相同数据类型的元素按一定顺序排列的集合
    2.一维数组，索引从1开始
      在 Lua 索引值是以 1 为起始，但你也可以指定 0 开始，把0作为key来使用，同理也可以将负数作为索引
    2.多维数组：包含数组或一维数组的索引键对应一个数组
]]

-- 一维数组
print("------------------------------------------------")
array = {"Lua", "Tutorial"}
for i= 0, 2 do
    print(array[i])
end   -- 第一个结果会返回nil

array = {}
for i= -2, 2 do
   array[i] = i *2
end

for i = -2,2 do
   print(array[i])
end

-- 多维数组
print("------------------------------------------------")
array = {}
for i=1,3 do
   array[i] = {}
      for j=1,3 do
         array[i][j] = i*j
      end
end
for i=1,3 do
    for j=1,3 do
       print(array[i][j])
    end
end