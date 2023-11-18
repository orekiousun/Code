--[[
    1.协程的创建
        创建方式一：co = coroutine.create(fun); 返回值是一个协程
        创建方式二：co = coroutine.wrap(fun); 返回值是一个函数

    2.协程的使用
        对于创建方式一：coroutine.resume(co);
        对于闯将方式二：co(); 由于返回值是一个函数，所以直接调用函数即可

    3.协程的挂起
        在协程内部添加coroutine.yield(i)语句，这里的i用于返回
        Lua协程的一些特性：当执行到yield语句时协程挂起，再次执行时会沿着之前的结果一起执行(例如函数内有一个局部变量i++的操作，再次执行时会接着之前的i加)
        协程的返回值
            创建方式一：返回两个变量，x, y = coroutine.resume(co) x表示协程是否执行成功，y表示协程的返回值（即couroutine.yield(x)中的x）
            创建方式二：x = co() 返回值即为couroutine.yield(x)中的x

    4.协程的状态
        coroutine.status(co);  返回协程的状态
        coroutine.running();   返回当前挂起的协程（一般只有在协程内部调用才找得到）

]]


print("------------------------协程的创建------------------------")
fun = function()
    print(123);
end

-- 使用coroutine.create方法创建
co = coroutine.create(fun);
-- 协程的本质是一个线程对象
print(co);
print(type(co));

-- 使用coroutine.wrap方法创建
co2 = coroutine.wrap(fun);
print(co2);
print(type(co2));


print("------------------------协程的运行------------------------")
-- 第一种方式利用coroutine.resume调用
coroutine.resume(co);
-- 第二种方式可以直接把创建的协程当作函数来调用
co2();




print("------------------------协程的挂起------------------------")
fun2 = function()
    local i = 0;
    while true do
        i = i + 1;
        print(i);
        -- 协程的挂起函数
        coroutine.yield()
    end
end

co3  = coroutine.create(fun2);
coroutine.resume(co3);  -- 第一次执行时协程挂起了
coroutine.resume(co3);  -- 第二次执行时协程被重启，i又上次的结果继续递增
coroutine.resume(co3);  -- 第二次执行时协程被重启，i又上次的结果继续递增

co4 = coroutine.wrap(fun2);
co4();
co4();  -- 两种方式相同，只是写法上不太一致

-- 同时协程可以有返回值
fun3 = function()
    local i = 0;
    while true do
        i = i + 1;
        print(i);
        print(coroutine.running());
        -- 协程的挂起函数
        coroutine.yield(i)
    end
end
co4 = coroutine.create(fun3);
x, y = coroutine.resume(co4);
print(x, y);
x, y = coroutine.resume(co4);
print(x, y);
-- 默认第一个返回值是协程是否启动成功，第二个返回值是yield里面的返回值
co5 = coroutine.wrap(fun3);
print("wrap:"..co5())   -- 利用wrap的方式创建的协程 也可以有返回值 只是没有默认第一个返回值了


print("------------------------协程的状态------------------------")
--couroutine.status(协程对象)
-- dead 死亡, suspended 暂停, running 进行中

print(coroutine.status(co3));  -- co3有挂起，执行完还没有结束
print(coroutine.status(co));   -- co没有挂起，执行完即结束
print(coroutine.running());    -- 打印当前正在运行的协程号