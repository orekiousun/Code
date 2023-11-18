--[[
    面向对象 类 其实都是基于table实现的
    1.封装
        利用table可以将变量和函数封装到一起
        实现实例化：定义一个new方法，返回一个新的空表以实例化对象。
            1.需要设置空表的metatable为原始的表本身，以获取到原始的表的属性
            2.仅进行1操作还不够，需要将定义元表的__index元方法，将__index = self，以此实例化，不然还是获取不到原来表内的属性
        本质上是声明了一张空表，只是利用了元表和元方法实现了对象的实例化
    
    2.继承
        利用_G表实现继承，利用G表生成一个空的表，将该表的元表设置为调用该方法的表，以实现对原来的表的继承
        由于该空表本身是没有元素的，每次访问某个元素时需要查找该表的元表的__index方法，所以需要将__index方法设置为改变的元表，以此实现继承

    3.多态
        多态的执行逻辑：同名函数，不同的执行逻辑
        通过在继承的时候定义一个base属性保存父类
        存在的问题：当有子类继承同一个父类对象，但是实例化多次时，由于父类对象只有一个，子类会共享父类的数据
]]

print("------------------------封装------------------------")
object = {id = 1};   -- 定义一个原始表
function object:Print()
    print("self.id: \t"..self.id);
end

-- 冒号，会自动将调用该函数的对象传入作为第一个参数
function object:new()
    -- self 代表默认传入的第一个参数
    -- 返回出去的内容，本质上就是表对象
    local obj = {};
    -- 结合元表的知识 __index 当找自己的变量找不到时，就会去寻找元表中__index指向的内容
    -- 将self作为空表的元表，以此实例化
    self.__index = self;
    setmetatable(obj, self);
    return obj;
end

local myObj = object:new();
print("myObj.id: \t"..myObj.id);
myObj:Print();
myObj.id = 2;
print("object.id: \t"..object.id);
print("myObj.id: \t"..myObj.id);


print("------------------------继承------------------------");
-- 写一个类用于继承方法
function object:subClass(className)
    -- _G总表，所有声明的全部变量都以键值对的形式存在其中
    _G[className] = {};
    local obj = _G[className];
    self.__index = self;
    -- 子类 定义一个base属性 base属性代表父类
    obj.base = self;
    setmetatable(obj, self);
end

object:subClass("Person");
print(Person.id);


print("------------------------多态------------------------");
-- 相同行为 不同表象 就是多态
-- 相同方法 不同执行逻辑 就是多态
object:subClass("GameObject");
GameObject.posX = 0;
GameObject.posY = 0;
function GameObject:Move()
    self.posX = self.posX + 1;
    self.posY = self.posY + 1;
    print(self.posX, self.posY);
end
GameObject:subClass("Player");
function Player:Move()
    -- 通过base保留父类方法，需要构建一个base
    -- 但是需要注意的是，base指的是GameObject表
    -- 这种方式调用 相当于是把基类表作为第一个参数传入方法中
    -- 避免把基类表传入到方法中
    -- 要执行父类逻辑，直接通过.调用，传入第一个参数
    self.base.Move(self);
end
local p1 = Player:new();
p1:Move();