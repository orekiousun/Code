--[[
    普通的表无法对两个table进行操作，元表允许改变table的行为，关联了对应的方法
    1.对表设置元表
        setmetatable(table,metatable)   -- 对指定 table 设置元表(metatable)
        getmetatable(table)   -- 返回对象的元表(metatable)

    2.__index 元方法
        通过键访问 table 时，如果这个键没有值，那么Lua就会寻找该table的metatable（假定有metatable）中的__index 键
    Lua 查找一个表元素时的规则，其实就是如下 3 个步骤:
    1)在表中查找，如果找到，返回该元素，找不到则继续
    2)判断该表是否有元表，如果没有元表，返回 nil，有元表则继续。
    3)判断元表有没有 __index 方法，如果 __index 方法为 nil，则返回 nil；如果 __index 方法是一个表，则重复 1、2、3；如果 __index 方法是一个函数，则返回该函数的返回值
    补充：rawget方法可以绕开_index，直接获取索引

    3.__newindex 元方法:
        __newindex 元方法用来对表更新，__index则用来对表访问
        当给表的一个缺少的索引赋值，解释器就会查找__newindex 元方法：如果存在则调用这个函数而不进行赋值操作
    补充：rawset方法可以绕开__newindex，直接设置索引

    4.为表添加操作符
        __add	对应的运算符 '+'.
        __sub	对应的运算符 '-'.
        __mul	对应的运算符 '*'.
        __div	对应的运算符 '/'.
        __mod	对应的运算符 '%'.
        __unm	对应的运算符 '-'.
        __concat	对应的运算符 '..'.
        __eq	对应的运算符 '=='.
        __lt	对应的运算符 '<'.
        __le	对应的运算符 '<='.
    
    5.__call 元方法：在 Lua 调用一个值时调用

    6. __tostring 元方法：用于修改表的输出行为

]]

-- 对表设置元表
print("------------------------------------------------")
mytable = {}                          -- 普通表
mymetatable = {}                      -- 元表
setmetatable(mytable,mymetatable)     -- 把 mymetatable 设为 mytable 的元表
getmetatable(mytable)                 -- 这会返回 mymetatable


-- __index 元方法
print("------------------------------------------------")
mytable = setmetatable({key1 = "value1"}, {
    __index = function(mytable, key)
        if key == "key2" then
            return "metatablevalue"
        else
            return nil
        end
    end
})
print(mytable.key1,mytable.key2)

mytable = setmetatable({key1 = "value1"}, { __index = { key2 = "metatablevalue" } })
print(mytable.key1,mytable.key2)   -- 简化写法

-- __newindex 元方法
print("------------------------------------------------")
mymetatable = {}
mytable = setmetatable({key1 = "value1"}, { __newindex = mymetatable })
print(mytable.key1)
mytable.newkey = "新值2"
print(mytable.newkey,mymetatable.newkey)
mytable.key1 = "新值1"
print(mytable.key1,mymetatable.key1)

mytable = setmetatable({key1 = "value1"}, {
    __newindex = function(mytable, key, value)
        rawset(mytable, key, "\""..value.."\"")
    end
})   -- 利用rawset函数更新表
mytable.key1 = "new value"
mytable.key2 = 4
print(mytable.key1,mytable.key2)

-- 为表添加操作符
print("------------------------------------------------")
-- 两表相加操作
function table_maxn(t)
    local mn = 0
    for k, v in pairs(t) do
        if mn < k then
            mn = k
        end
    end
    return mn
end   -- 定义一个获得最大值的函数
mytable = setmetatable({ 1, 2, 3 }, {
    __add = function(mytable, newtable)
        for i = 1, table_maxn(newtable) do
            table.insert(mytable, table_maxn(mytable)+1,newtable[i])
        end
        return mytable
    end
})

secondtable = {4,5,6}
mytable = mytable + secondtable
for k,v in ipairs(mytable) do
    print(k,v)
end

-- __call 元方法
mytable = setmetatable({10}, {
    __call = function(mytable, newtable)
        sum = 0
        for i = 1, table_maxn(mytable) do
            sum = sum + mytable[i]
        end
        for i = 1, table_maxn(newtable) do
            sum = sum + newtable[i]
        end
        return sum
    end
})
newtable = {10,20,30}
print(mytable(newtable))

-- __tostring 元方法
mytable = setmetatable({ 10, 20, 30 }, {
    __tostring = function(mytable)
        sum = 0
        for k, v in pairs(mytable) do
            sum = sum + v
        end
        return "表所有元素的和为 " .. sum
    end
  })
print(mytable)
