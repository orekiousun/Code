using System;
using System.Collections.Generic;

/*
    1.C#泛型集合  --  需要包含头文件using System.Collections.Generic;
        1）List数组  --   适合从头到尾读
            List<数据类型> 
            Add Insert Remove RemoveAt 
            通过索引获取listName[i]
        2）字典集合  --  适合通过键值寻找
            Dictionary<key数据类型，value数据类型>
            通过key值获取数据dicName[key]
    2.继承
        父类只能使用父类成员
        子类可以使用父类的public成员，继承过去了private成员，但不能使用
        protected的属性仅仅可在子类中使用，类外访问不到
        父类引用可以指向子类对象
    3.static
        静态成员变量：static关键字用于修饰成员变量
            ·静态成员变量属于类，类被加载时初始化，且只有一份  --  放在静态区（出现类名，类即被加载）
            ·实例成员变量属于对象，在每个对象被创建时初始化，每个对象一份
        特点：存在优先于对象，被所有对象共享，常驻与内存
        静态构造函数：不能出现public，private等访问修饰符
            ·初始化类的静态数据成员，只能访问静态成员
            ·执行时机：类加载时执行
            ·不能访问到非静态数据成员（实例成员）
        （在使用实例方法时，会隐式传递对象引用，以便在方法内部可以正确访问该对象的成员变量。实例方法可以访问实例成员，也可以访问静态成员）
        同时，所有对象共享一个方法
        静态类：使用static修饰的类
            不能实例化，只能包含静态成员
            静态类不能被继承，但是静态方法，属性都可以被继承
        -- 弊端：共享数据被多个对象访问会出现并发
    4.结构体
        用于封装小型相关变量的值类型
    与类的不同：
        结构体属于值类型
        类属于引用类型
    结构体不能包含无参构造函数，系统会默认提供无参构造函数（写了有参也会提供无参）
    如果使用类，将为每个对象分配更多空间，使用结构体更节约性能
 */

namespace Day08
{
    class Program
    {
        static void Main(string[] args)
        {
            // C#泛型集合
            Console.WriteLine("--------------- test01 ---------------");
            List<User> list01 = new List<User>();
            list01.Add(new User("Saber", "0"));
            list01.Insert(1, new User("Rider", "1"));
            for (int i = 0; i < list01.Count; i++)
            {
                Console.WriteLine(list01[i].LogInId + "\t" + list01[i].Password);
            }

            Dictionary<string, User> dic01 = new Dictionary<string, User>();
            dic01.Add("0", new User("Saber", "0"));
            User usr = dic01["0"];


            // 继承
            Console.WriteLine("--------------- test02 ---------------");
            Student s1 = new Student();
            s1.Name = "Saber";
            // 访问不到s1.a
            Person p1 = new Student();   // 多态  --  但是只能用父类成员
            // 如果需要访问该子类成员，需要强制类型转换
            Student stu01 = (Student)p1;
            // 子类与子类之间互相转换
            // Teacher teacher01 = (Teacher)p1;      // 代码可以这么写，但是允许会异常
            // Teacher teacher01 = p1 as Teacher;    // 通过此方法也可以转换，但是还是不能用，内部没有Teacher的成员 

            Student stu02 = new Student();
            Student stu03 = new Student();
            Console.WriteLine(Student.count);


            // 需求：在二维数组中，获取某个元素某个方向上的元素
            Console.WriteLine("--------------- test03 ---------------");
            Direction right = Direction.right;
            string[,] arr = new string[3, 4];
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    arr[i, j] = i.ToString() + j.ToString();
                }
            }
            string[] result = DoubleArrHelper.getElements(arr, 2, 0, Direction.right, 3);
            foreach (var item in result)
            {
                Console.Write(item + " ");
            }


            // 结构体
            Console.WriteLine("--------------- test02 ---------------");
            DirectionStruct dir01 = new DirectionStruct();   // =左右都放在栈中
            DirectionStruct[] dir02 = new DirectionStruct[5];   // =左边在栈中，右边在堆中


        }
    }
}
