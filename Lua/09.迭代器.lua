--[[
    1.泛型for迭代器，ipairs为默认迭代函数
        for k, v in pairs(t) do
            print(k, v)
        end
    2.无状态的迭代器 
        一个简单的无状态迭代器就是ipairs
            function iter (a, i)
                i = i + 1
                local v = a[i]
                if v then
                return i, v
                end
            end
            
            function ipairs (a)
                return iter, a, 0
            end
        ipairs相当于一个函数，可用于迭代
    3。多状态迭代器
        array = {"Google", "Runoob"}

        function elementIterator (collection)
        local index = 0
        local count = #collection
        -- 闭包函数
        return function ()
            index = index + 1
            if index <= count
            then
                --  返回迭代器的当前元素
                return collection[index]
            end
        end
        end

        for element in elementIterator(array)
        do
        print(element)
        end
]]

-- 泛型for迭代器
array = {"Google", "Runoob"}
for key,value in ipairs(array)
do
   print(key, value)
end