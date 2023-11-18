# coding:utf-8



"""
    1.包
    ·包就是文件夹，包中还可以有包，就是子文件夹
    ·一个个python文件就是模块
    包->模块->函数
    2.包的身份证
    ·__init__.py是python包里必须存在的文件
    3.如何创建一个包
    ·要有一个主题明确功能，方便使用
    ·层次分明，调用清晰
    ·文件下要有一个__init__.py
    4.包的导入import:将python中的某个包（或模块），导入到当前py文件中
        import package
        # package为被导入的包的名字
        ·只会拿到对应包下__init__中的功能或当前模块下的功能（此模块需和这个包同级别）
    5.模块的导入 from  import   
        from package import module
        # package来源包名
        # module包中的目标模块
        # 类也可以通过这种方式直接导入
        举例:
        from animal import dog
        dog.run()
        ·当不同的包中有相同的函数名时可以通过as来改名
        from animal.cat,action import run as cat_run   
    
    

"""
