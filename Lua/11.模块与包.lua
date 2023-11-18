--[[
    1.模块结构：就是一个table结构，可以像调用table内元素那用调用模块中的函数和常量
    2.requre：用于加载模块
        require("<模块名>")
        require "<模块名>"
    require 用于搜索 Lua 文件的路径是存放在全局变量 package.path 中
    3.使用c语言为lua写包
    与Lua中写包不同，C包在使用以前必须首先加载并连接，在大多数系统中最容易的实现方式是通过动态连接库机制
    调用案例：
        local path = "/usr/local/lua/lib/libluasocket.so"
        local f = loadlib(path, "luaopen_socket")

        local path = "/usr/local/lua/lib/libluasocket.so"
        -- 或者 path = "C:\\windows\\luasocket.dll"，这是 Window 平台下
        local f = assert(loadlib(path, "luaopen_socket"))
        f()  -- 真正打开库
    
]]

-- 模块调用
print("------------------------------------------------")
require("module")
print(module.constant)
module.func3()

-- 加载别名变量方便调用
print("------------------------------------------------")
local m = require("module")
print(m.constant)
m.func3()