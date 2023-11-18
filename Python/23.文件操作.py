# coding:utf-8


"""
    1.利用内置函数open获取文件对象：生成文件对象，进行创建，读写操作
        open(path,mode)
        # path:文件路径
        # mode:操作模式
        # 返回文件对象
        f=open('d://a.text','w') # w表示write
    2.文件的操作模式
        w 创建文件  w+创建并读取文件  wb 二进制形式创建文件 
        wb+ 二进制形式创建或者追加内容  a 追加内容  a+ 读写模式的追加  
        ab+ 二进制形式的读写追加  
    3.文件对象的操作方法
        write 参数为Message 写入信息 f.write('hello\n')
        writelines 参数为Message_list 批量写入 f.writelines(['hello\n','world\n'])
        close 没有参数 关闭并保存文件 f.close()
        操作完成文件对象后，一定要使用close函数
"""