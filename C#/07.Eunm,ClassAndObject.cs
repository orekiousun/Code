using System;

/*
    复习
    1）值类型：直接存储数据
    2）引用类型：存储数据的引用（内存地址）
    3）方法执行在栈中，执行完毕清楚栈帧
    4）局部变量的值类型：声明在栈中，数据在栈中
    5）局部变量的引用类型：声明在栈中，数据在堆中，栈中存储数据的引用
    6）区分修改的是栈中存储的引用还是堆中的数据：看左值是一个引用类型还是一个值类型


    1.枚举：对内置的整型数据加一个标签  --  为了使数据与逻辑贴切
        枚举元素类型默认为int  --  值类型
    选择多个枚举值
    运算符 | 按位或：两个对应的二进制运算符有一个为1，结果为1
    条件：
        ·任意多个枚举值做 | 运算的结果不能与其他枚举值相同（值以2^n幂递增）
        ·定义枚举时使用[Flags]特性修饰，表示允许多选（不用[Flags]也可以多选，但是加入[Flags]会更可读，属于行业规定）
    判断标志枚举是否包含指定枚举值
    运算符 & 按位与：两个对应的二进制运算符都为1，结果为1
        ·将实参与选项做按位与，提取出其中的1，通过1在二进制中的不同位置选择


    2.类和对象  --  只有声明的类对象名保存在栈中，类中的成员都保存在堆中
    1）创建类：
        访问级别 class 类名
        {
            类成员......,
        }
    2）实例化对象：
        类名 引用名;
        引用名 = new 构造函数(参数列表);
            ·通常每个类都在一个独立的C#源文件中
            ·创建新的类意味着在当前项目中产生了一种新的数据类型  --  引用类型
        类在堆中开辟空间时还会额外开辟两块空间用于存储类型对象指针和同步块索引
    3）成员变量
        ·具有默认值
        ·可以与局部变量重名，成员变量通过this.访问
        ·所在类对象被实例化后，成员变量开辟在堆中，对象被回收时，成员变量从堆中清除
    5）属性：本事是两个方法 get和set方法
    6）访问级别
        private  --  只有类内部可以使用
        public   --  类内部和外部都能使用
    7）构造函数：提供了创建对象的方式，常常用于初始化类的数据成员
        ·一个类若没有构造函数，编译器会提供一个默认的无参构造
        ·一个类若有构造函数，编译器不会提供一个默认的无参构造
    没有返回值，与类同名   --  每次创建对象就是在new构造函数
    如果不想在类的外部被创建对象，就将构造函数私有化
        public 类名(参数列表);
    8）this关键字
    表示当前对象的引用
    访问当前类成员时使用this关键字可以提高代码可读性，没有歧义的情况下可以省略
 */
namespace Day07
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("--------------- test01 ---------------");
            int[,] doubleArr = new int[3, 4];
            move(doubleArr, Day07.Move.Right);
            move(doubleArr, Day07.Move.Up);
            move(doubleArr, Day07.Move.Down);
            move(doubleArr, Day07.Move.Left);
            // 枚举多选 -- 利用逻辑代数知识
            printPersonStyle(PersonStyle.tall | PersonStyle.rich);   // 通过|选择多个枚举值
            // 枚举数据类型转换
            printPersonStyle((PersonStyle)4);   // 整型转枚举类型0
            int enumNumber = (int)(PersonStyle.beauty | PersonStyle.rich);   // 枚举类型转整型
            Console.WriteLine(enumNumber);
            string beauty = "beauty";
            PersonStyle temp = (PersonStyle)Enum.Parse(typeof(PersonStyle), beauty);
            printPersonStyle(temp);   // 字符串类型转枚举类型
            Console.WriteLine(PersonStyle.handsome.ToString());   // 枚举转字符串





            // 类和对象
            Console.WriteLine("--------------- test02 ---------------");
            Person p1 = new Person("Lisa", "female", 24);
            Console.WriteLine(p1.getName() + " " + p1.getSex() + " " + p1.getAge().ToString());
            Person p2 = p1;   // 传递地址
            p2.setName("Aimer");
            Console.WriteLine(p1.getName());

            p2 = new Person();   // 新开辟了一块空间，修改了引用
            p2.setName("YOASOBI");
            p2.Age = 19;
            p2.Sex = "female";
            Console.WriteLine(p1.getName());   // 仍为Aimer

            Person p3 = new Person();
            p3.Name = "Justin";   // 本质上是在调用Name下的set方法
            p3.Age = 24;
            p3.Sex = "male";
            Console.WriteLine(p3.getName() + " " + p3.getSex() + " " + p3.getAge().ToString());



            // 练习
            Console.WriteLine("--------------- test03 ---------------");
            Person p4 = new Person("Yama", "female", 22);
            Person p5 = new Person();
            p5.Name = "Ikura";
            p5.Age = 18;
            p5.Sex = "female";

            Person[] personArr = new Person[6];   // 10个默认值均为空
            personArr[0] = p1;
            personArr[1] = p2;
            personArr[2] = p3;
            personArr[3] = p4;
            personArr[4] = p5;
            personArr[5] = new Person("ReoNa", "female", 21);
            Person minAgePerson = findMinAge(personArr);
            Console.WriteLine(minAgePerson.getName() + " " + minAgePerson.getSex() + " " + minAgePerson.getAge().ToString());


            Console.WriteLine("--------------- test04 ---------------");
            UserList ul = new UserList();
            ul.addUser(new User("Saber", "1"));
            ul.addUser(new User("Rider", "2"));
            ul.addUser(new User("Archer", "3"));
            ul.addUser(new User("Lancer", "4"));
            ul.addUser(new User("Caster", "5"));
            ul.addUser(new User("Assassin", "6"));
            ul.insertUser(new User("Berserker", "0"), 0);
            ul.printUserList();
            ul.deleteUser(3);
            Console.WriteLine("---------- 分隔符 ----------");
            ul.printUserList();
            ul.insertUser(new User("Archer", "3"), 3);
            Console.WriteLine("---------- 分隔符 ----------");
            ul.printUserList();
            User item = ul.getElement(4);
            Console.WriteLine("---------- 分隔符 ----------");
            Console.WriteLine("Id: " + item.LogInId + "\tPassword: " + item.Password);
        }
        // 枚举
        private static void move(int[,] map, Move direction)
        {
            switch(direction)
            {
                case Day07.Move.Up:
                    // moveUp(map);
                    break;
                case Day07.Move.Down:
                    // moveDown(map);
                    break;
                case Day07.Move.Left:
                    // moveLeft(map);
                    break;
                case Day07.Move.Right:
                    // moveRight(map);
                    break;
            }
        }

        private static void printPersonStyle(PersonStyle style)
        {
            if ((style & PersonStyle.tall) == PersonStyle.tall)
                Console.WriteLine("tall");
            if ((style & PersonStyle.rich ) == PersonStyle.rich)
                Console.WriteLine("rich");
            if ((style & PersonStyle.handsome) == PersonStyle.handsome)
                Console.WriteLine("handsome");
            if ((style & PersonStyle.white) == PersonStyle.white)
                Console.WriteLine("white");
            if ((style & PersonStyle.beauty) != 0)
                Console.WriteLine("beauty");
        }


        // 练习1：查找年龄最小的人
        private static Person findMinAge(Person[] personArr)
        {
            int minIndex = 0;
            for(int i = 0; i < personArr.Length; i++)
            {
                if (personArr[i].getAge() < personArr[minIndex].getAge())
                {
                    minIndex = i;
                }
            }
            return personArr[minIndex];
        }

        // 每日一练
        /*
            用户集合类 UserList
            使用：UserList = new UserList();
         */

    }
}
