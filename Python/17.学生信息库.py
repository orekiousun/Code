# coding:utf-8

class StudentInfo(object):
    def __init__(self,students):
        self.students=students

    def get(self):
        for id_,value in self.students.items():
            print('学号:{},姓名:{},年龄:{},性别:{},班级:{}'.format(id_,value['name'],value['age'],value['sex'],value['class_number']))
        return self.students

    def check_user_info(self,**kwargs):
        if 'name' not in kwargs:
            return '没有发现学生姓名'
        if 'age' not in kwargs:
            return '缺少学生年龄'
        if 'sex' not in kwargs:
            return '缺少学生性别'
        if 'class_number' not in kwargs:
            return '缺少学生班级'
        return True

    def __add(self,**student):
        new_id=max(self.students)+1
        self.students[new_id]=student

    def add(self,**student):
        check=self.check_user_info(**student)
        if check!=True:
            print(check)
            return
        self.__add(**student)

    def adds(self,new_students):
        for student in new_students:
            check=self.check_user_info(**student)
            if check!=True:
                print(check,student.get('name'))
                continue # 这里不能写return，写了return函数会结束运行，假设有第二个学生就无法添加进去了
            self.__add(**student)

    def delete(self,student_id):
        if student_id not in self.students:
            print('{}并不存在'.format(student_id))
        else:
            student_info=self.students.pop(student_id) # 将删除的学生信息存在新的字典中
            print('学号是{},{}同学的信息已经被删除了'.format(student_id,student_info['name']))

    def deletes(self,ids):
        for id_ in ids:
            self.delete(id_)

    def update(self,student_id,**kwargs):
        if student_id not in self.students:
            print('并不存在这个学号:{}'.format(student_id))
        check=self.check_user_info(**kwargs)
        if check!=True:
            print(check)
            return
        self.students[student_id]=kwargs
        print('同学信息更新完毕')
    
    def updates(self,students):
        for student in students:
            id=list(student.keys())[0]
            info=student[id]
            self.update(id,**info)

    def get_by_id(self,student_id):
        return self.students.get(student_id)

    def search_users(self,**kwargs):
        values=list(self.students.values())
        key=None
        value=None
        result=[]
        if 'name' in kwargs:
            key='name'
            value=kwargs[key]
        elif 'sex' in kwargs:
            key='sex'
            value=kwargs[key]
        elif 'age' in kwargs:
            key='age'
            value=kwargs[key]
        elif 'class_number' in kwargs:
            key='class_number'
            value=kwargs[key]
        else:
            print('没有发现搜索关键字')
            return
        for user in values:
            if value in user[key]:
                result.append(user)
        return result

if __name__=='__main__':
    students={
        1:{
            'name':'xiaomu',
            'age':18,
            'class_number':1,
            'sex':'girl'
        },
        2:{
            'name':'xiaoyun',
            'age':15,
            'class_number':4,
            'sex':'boy'
        },
        3:{
            'name':'xiaogao',
            'age':17,
            'class_number':2,
            'sex':'boy'
        },
        4:{
            'name':'xiaohong',
            'age':16,
            'class_number':3,
            'sex':'girl'
        },
        5:{
            'name':'xiaowang',
            'age':19,
            'class_number':5,
            'sex':'boy'
        }
    }
    student_info=StudentInfo(students)
    # 测试get_by_id
    user=student_info.get_by_id(2)
    print(user)
    # 测试add,adds
    student_info.add(name='xiaoai',age=33,sex='girl')
    student_info.add(name='dewei',age=33,sex='boy',class_number=4)
    user=[
        {'name':'xiaoming','age':17,'sex':'boy','class_number':6},
        {'name':'xiaozhang','age':17,'sex':'girl','class_number':6}
    ]
    student_info.adds(user)
    # 测试delete，deletes
    student_info.delete(3)
    student_info.deletes([1,3])
    # 测试update，updates
    student_info.updates([
        {7:{'name':'xiaoming','age':17,'sex':'boy','class_number':7}},
        {8:{'name':'xiaozhang','age':17,'sex':'girl','class_number':8}}
    ])
    # 测试模糊查找
    result=student_info.search_users(name='d')
    print(result)