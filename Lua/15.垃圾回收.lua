test = {id = 1, name = "123123"}
print(collectgarbage("count"))
test = nil
collectgarbage("collect")
print(collectgarbage("count"))

-- lua中也有自动定时进行GC的方法，尽量使用手动释放