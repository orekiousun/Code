--[[
    1.表的构造
        利用{}构造一个空表
        mytable = {}   -- 初始化表
        mytable[1]= "Lua"   -- 指定值
        mytable = nil   -- 移除引用
    2.相关函数
        1)连接：table.concat()
        2)插入和移除：table.insert() / table.remove()
        3)排序：table.sort()
        4)最大值：table.maxn()   -- 在lua5.2之后不存在，自己定义实现
]]

-- 简单的 table
print("------------------------------------------------")
mytable = {}
print("mytable 的类型是 ",type(mytable))
mytable[1]= "Lua"
mytable["wow"] = "修改前"
print("mytable 索引为 1 的元素是 ", mytable[1])
print("mytable 索引为 wow 的元素是 ", mytable["wow"])
alternatetable = mytable   -- alternatetable和mytable的是指同一个 table
print("alternatetable 索引为 1 的元素是 ", alternatetable[1])
print("mytable 索引为 wow 的元素是 ", alternatetable["wow"])
alternatetable["wow"] = "修改后"
print("mytable 索引为 wow 的元素是 ", mytable["wow"])
alternatetable = nil   -- 释放变量
print("alternatetable 是 ", alternatetable)
print("mytable 索引为 wow 的元素是 ", mytable["wow"])   -- mytable 仍然可以访问
mytable = nil
print("mytable 是 ", mytable)

-- 连接
print("------------------------------------------------")
fruits = {"banana","orange","apple"}   -- 返回 table 连接后的字符串
print("连接后的字符串 ",table.concat(fruits))
print("连接后的字符串 ",table.concat(fruits,", "))   -- 指定连接字符
print("连接后的字符串 ",table.concat(fruits,", ", 2,3))   -- 指定索引来连接 table

-- 插入移除
print("------------------------------------------------")
fruits = {"banana","orange","apple"}
table.insert(fruits,"mango")   -- 在末尾插入
print("索引为 4 的元素为 ",fruits[4])
table.insert(fruits,2,"grapes")   -- 在索引为 2 的键处插入
print("索引为 2 的元素为 ",fruits[2])
print("最后一个元素为 ",fruits[5])
table.remove(fruits)
print("移除后最后一个元素为 ",fruits[5])

-- 排序
print("------------------------------------------------")
fruits = {"banana","orange","apple","grapes"}
table.sort(fruits)
for k,v in ipairs(fruits) do
    print(k,v)
end

-- 最大值
function table_maxn(t)
    local mn=nil;
    for k, v in pairs(t) do
      if(mn==nil) then
        mn=v
      end
      if mn < v then
        mn = v
      end
    end
    return mn
end
tbl = {[1] = 2, [2] = 6, [3] = 34, [26] =5}
print("tbl 最大值：", table_maxn(tbl))
print("tbl 长度 ", #tbl)