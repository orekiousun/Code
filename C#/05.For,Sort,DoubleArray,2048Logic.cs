using System;

namespace Day05
{
    class Program
    {
        static void Main(string[] args)
        {
            // 复习
            Console.WriteLine("--------------- test01 ---------------");
            float[] fArray = new float[] { 1.5f, 1.9f, 2.0f };
            fArray[2] = 3.0f;
            foreach (float item in fArray)
            {
                Console.Write(item + " ");
            }
            Console.Write("\n");
            for(int i = 0;i < fArray.Length; i++)
            {
                Console.Write(fArray[i] + " ");
            }
            Console.Write("\n");



            // for循环嵌套
            Console.WriteLine("--------------- test02 ---------------");
            int[] iArray1 = new int[] { 2, 1, 4, 7, 5, 9, 0, 6, 8, 3 };
            int[] iArray2 = new int[] { 2, 1, 4, 7, 5, 1, 0, 6, 8, 3 };
            for (int i = 0; i <= 4; i++)
            {
                for (int j = 0; j < 4 - i; j++)
                {
                    Console.Write(" ");
                }
                for (int j = 0; j < i * 2; j++)
                {
                    Console.Write("#");
                }
                Console.WriteLine();
            }
            // 选择排序
            selectSort(iArray1);
            printArray(iArray1);
            // 冒泡排序
            bubbleSort(iArray2);
            printArray(iArray2);
            Console.WriteLine("findSameElement(iArray1) = " + findSameElement(iArray1));
            Console.WriteLine("findSameElement(iArray2) = " + findSameElement(iArray2));



            // 二维数组
            Console.WriteLine("--------------- test03 ---------------");
            int[,] doubleArray = new int[5, 3];   // 创建5行3列的二维数组
            Console.WriteLine("doubleArray.Length = ", doubleArray.Length);
            doubleArray[0, 2] = 6;                // 第一行第三列赋值为6
            doubleArray[3, 1] = 5;
            doubleArray[1, 0] = 13;
            printDoubleArray(doubleArray);
            // 二维数组初始化
            int[,] doubleArray2 = new int[5, 3]
            {
                {1, 2, 3 },
                {1, 2, 3 },
                {1, 2, 3 },
                {1, 2, 3 },
                {1, 2, 3 }
            };



            // 2048
            Console.WriteLine("--------------- 2048 ---------------");
            game2048();

            // 交错数组
        }
        private static void bubbleSort(int[] iArray)    // 冒泡排序
        {
            for(int i = 0; i < iArray.Length - 1; i++)  // 索引设置为Length - 1，最后一次交换可以不用做
            {
                for(int j = i + 1; j < iArray.Length; j++)
                {
                    if(iArray[j] <= iArray[i])
                    {
                        int temp = iArray[i];
                        iArray[i] = iArray[j];
                        iArray[j] = temp;
                    }
                }
            }
        }

        private static void selectSort(int[] iArray)    // 选择排序
        {
            for (int i = 0; i < iArray.Length - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < iArray.Length; j++)
                {
                    if (iArray[j] <= iArray[min])
                    {
                        min = j;
                    }
                }
                if (min != i)
                {
                    int temp = iArray[min];
                    iArray[min] = iArray[i];
                    iArray[i] = temp;
                }
            }
        }

        private static void printArray(Array arr)
        {
            foreach(var item in arr)
            {
                Console.Write(item + "\t");
            }
            Console.WriteLine();
        }

        private static bool findSameElement(int[] arr)
        {
            int flag = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = 0; j < arr.Length; j++)
                {
                    if (j == i)
                        continue;
                    if (arr[i] == arr[j])
                        flag = 1;
                }
            }
            if (flag == 0)
                return false;
            else
                return true;
        }

        private static void printDoubleArray(int[,] arr)
        {
            for (int i = 0; i < arr.GetLength(0); i++)   // arr.GetLength(i) 获取指定维数的长度
            {
                for (int j = 0; j < arr.GetLength(1); j++)
                {
                    Console.Write(arr[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }

        static Random random = new Random();   // 创建一个随机数工具
        
        private static void game2048()
        {
            int[,] game = initGame();
            while(true)
            {
                // 游戏进程
                printDoubleArray(game);
                Console.Write("请输入操作：上移W，下移S，左移A，右移D：");
                string keyRead = Console.ReadLine();
                if (keyRead == "W")   // 上移
                {
                    getKeyWNew(game);
                }
                else if (keyRead == "S")
                {
                    getKeySNew(game);
                }
                else if (keyRead == "A")   // 左移
                {
                    getKeyANew(game);
                }
                else if (keyRead == "D")   // 右移
                {
                    getKeyDNew(game);
                }
                else
                {
                    Console.WriteLine("输入错误");
                    break;
                }
                // 判断达成条件
                if (isSucess(game))
                {
                    Console.WriteLine("恭喜游戏通关！");
                    break;
                }
                else if (isFail(game))
                {
                    Console.WriteLine("游戏失败！");
                    break;
                }
                else
                {
                    genNewNumber(game);
                }
            }
        }


        private static int[,] initGame()
        {
            int[,] game = new int[4, 4];
            int[] arr = new int[2] { 2, 4 };
            int number1 = random.Next(0, 16);
            int number2 = random.Next(0, 16);
            while (number1 == number2)
            {
                number2 = random.Next(0, 16);
            }
            game[number1 / 4, number1 % 4] = arr[random.Next(0, 2)];
            game[number2 / 4, number2 % 4] = arr[random.Next(0, 2)];
            return game;
        }
        // 我的方法
        private static void getKeyW(int[,] game)
        {
            for (int i = 0; i < game.GetLength(1); i++)
            {
                // 1.移除0
                for (int j = 0; j < game.GetLength(0); j++)
                {
                    int k = j;
                    while (game[k, i] == 0)
                    {
                        if (k == 3)
                            break;
                        k++;
                        if (k == 3)
                            break;
                    }
                    if (k != j)
                    {
                        game[j, i] = game[k, i];   // 找到第一个不为0的数
                        game[k, i] = 0;
                    }
                }

                // 2.合并
                for (int j = 0; j < game.GetLength(0) - 1; j++)
                {
                    if (game[j, i] == game[j + 1, i])
                    {
                        game[j, i] += game[j + 1, i];
                        game[j + 1, i] = 0;
                    }
                }

                for (int j = 0; j < game.GetLength(0); j++)
                {
                    int k = j;
                    while (game[k, i] == 0)
                    {
                        if (k == 3)
                            break;
                        k++;
                        if (k == 3)
                            break;
                    }
                    if (k != j)
                    {
                        game[j, i] = game[k, i];   // 找到第一个不为0的数
                        game[k, i] = 0;
                    }
                }
            }
        }
        private static void getKeyS(int[,] game)
        {
            for (int i = 0; i < game.GetLength(1); i++)
            {
                // 1.移除0
                for (int j = game.GetLength(0) - 1; j > 0; j--)
                {
                    int k = j;
                    while (game[k, i] == 0)
                    {
                        if (k == 0)
                            break;
                        k--;
                        if (k == 0)
                            break;
                    }
                    if (k != j)
                    {
                        game[j, i] = game[k, i];   // 找到第一个不为0的数
                        game[k, i] = 0;
                    }
                }

                // 2.合并
                for (int j = 0; j < game.GetLength(0) - 1; j++)
                {
                    if (game[j, i] == game[j + 1, i])
                    {
                        game[j, i] += game[j + 1, i];
                        game[j + 1, i] = 0;
                    }
                }

                for (int j = game.GetLength(0) - 1; j > 0; j--)
                {
                    int k = j;
                    while (game[k, i] == 0)
                    {
                        if (k == 0)
                            break;
                        k--;
                        if (k == 0)
                            break;
                    }
                    if (k != j)
                    {
                        game[j, i] = game[k, i];   // 找到第一个不为0的数
                        game[k, i] = 0;
                    }
                }
            }
        }
        private static void getKeyA(int[,] game)
        {
            for (int i = 0; i < game.GetLength(0); i++)
            {
                // 1.移除0
                for (int j = 0; j < game.GetLength(1); j++)
                {
                    int k = j;
                    while (game[i, k] == 0)
                    {
                        if (k == 3)
                            break;
                        k++;
                        if (k == 3)
                            break;
                    }
                    if (k != j)
                    {
                        game[i, j] = game[i, k];   // 找到第一个不为0的数
                        game[i, k] = 0;
                    }
                }

                // 2.合并
                for (int j = 0; j < game.GetLength(1) - 1; j++)
                {
                    if (game[i, j] == game[i, j + 1])
                    {
                        game[i, j] += game[i, j + 1];
                        game[i, j + 1] = 0;
                    }
                }

                // 3.移除0
                for (int j = 0; j < game.GetLength(1); j++)
                {
                    int k = j;
                    while (game[i, k] == 0)
                    {
                        if (k == 3)
                            break;
                        k++;
                        if (k == 3)
                            break;
                    }
                    if (k != j)
                    {
                        game[i, j] = game[i, k];   // 找到第一个不为0的数
                        game[i, k] = 0;
                    }
                }
            }
        }
        private static void getKeyD(int[,] game)
        {
            for (int i = 0; i < game.GetLength(0); i++)
            {
                // 1.移除0
                for (int j = game.GetLength(1) - 1; j > 0; j--)
                {
                    int k = j;
                    while (game[i, k] == 0)
                    {
                        if (k == 0)
                            break;
                        k--;
                        if (k == 0)
                            break;
                    }
                    if (k != j)
                    {
                        game[i, j] = game[i, k];   // 找到第一个不为0的数
                        game[i, k] = 0;
                    }
                }

                // 2.合并
                for (int j = 0; j < game.GetLength(1) - 1; j++)
                {
                    if (game[i, j] == game[i, j + 1])
                    {
                        game[i, j] += game[i, j + 1];
                        game[i, j + 1] = 0;
                    }
                }

                for (int j = game.GetLength(1) - 1; j > 0; j--)
                {
                    int k = j;
                    while (game[i, k] == 0)
                    {
                        if (k == 0)
                            break;
                        k--;
                        if (k == 0)
                            break;
                    }
                    if (k != j)
                    {
                        game[i, j] = game[i, k];   // 找到第一个不为0的数
                        game[i, k] = 0;
                    }
                }
            }
        }



        // 教程里的方法 -- 复用性更高
        // 先把需要的数据根据操作按不同的顺序读入数组中，然后去0，合并，在去零，最后再返回相同的数据方向
        private static void getKeyWNew(int[,] game)
        {
            for (int i = 0; i < game.GetLength(1); i++)
            {
                int[] temp = new int[game.GetLength(0)];
                for (int j = 0; j < game.GetLength(0); j++)
                {
                    temp[j] = game[j, i];
                }
                removeZero(temp);
                mergeArray(temp);
                removeZero(temp);
                for (int j = 0; j < game.GetLength(0); j++)
                {
                    game[j, i] = temp[j];
                }
            }
        }
        private static void getKeyANew(int [,] game)
        {
            for (int i = 0; i < game.GetLength(0); i++)
            {
                int[] temp = new int[game.GetLength(1)];
                for (int j = 0; j < game.GetLength(1); j++)
                {
                    temp[j] = game[i, j];
                }
                removeZero(temp);
                mergeArray(temp);
                removeZero(temp);
                for (int j = 0; j < game.GetLength(1); j++)
                {
                    game[i, j] = temp[j];
                }
            }
        }
        private static void getKeySNew(int[,] game)
        {
            for (int i = 0; i < game.GetLength(1); i++)
            {
                int[] temp = new int[game.GetLength(0)];
                int k = 0;
                for (int j = game.GetLength(0) - 1; j >= 0; j--)
                {
                    temp[k] = game[j, i];
                    k++;
                }
                removeZero(temp);
                mergeArray(temp);
                removeZero(temp);
                // printArray(temp);
                k = 0;
                for (int j = game.GetLength(0) - 1; j >= 0; j--)
                {
                    game[j, i] = temp[k];
                    k++;
                }
            }
        }
        private static void  getKeyDNew(int[,] game)
        {
            for (int i = 0; i < game.GetLength(0); i++)
            {
                int[] temp = new int[game.GetLength(1)];
                int k = 0;
                for (int j = game.GetLength(1) - 1; j >= 0; j--)
                {
                    temp[k] = game[i, j];
                    k++;
                }
                removeZero(temp);
                mergeArray(temp);
                removeZero(temp);
                k = 0;
                for (int j = game.GetLength(1) - 1; j >= 0; j--)
                {
                    game[i, j] = temp[k];
                    k++;
                }
            }
        }
        private static void removeZero(int[] temp)
        {
            int j = 0;
            for (int i = 0; i < temp.Length; i++)
            {
                if (temp[i] != 0)
                {
                    if (j != i)
                    {
                        temp[j] = temp[i];
                        temp[i] = 0;
                    }
                    j++;
                }
            }
        }
        private static void mergeArray(int[] temp)
        {
            for (int j = 0; j < temp.Length - 1; j++)
            {
                if (temp[j] == temp[j + 1])
                {
                    temp [j] += temp[j + 1];
                    temp[j + 1] = 0;
                }
            }
        }
        


        private static int[,] genNewNumber(int[,] game)
        {
            if (isFull(game))
            {
                Console.WriteLine("移动失败");
            }
            else
            {
                int[] arr = new int[2] { 2, 4 };
                int number3 = random.Next(0, 16);
                // 生成新的数
                while (game[number3 / 4, number3 % 4] != 0)
                {
                    number3 = random.Next(0, 16);
                }
                game[number3 / 4, number3 % 4] = arr[random.Next(0, 2)];
            }
            return game;
        }
        private static bool isSucess(int[,] game)
        {
            foreach (var item in game)
            {
                if (item == 2048)
                {
                    return true;
                }
            }
            return false;
        }
        private static bool isFull(int[,] game)
        {
            int count = 0;
            foreach (var item in game)
            {
                if (item != 0)
                {
                    count++;
                }
            }
            if (count == game.GetLength(0) * game.GetLength(1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private static bool isFail(int[,] game)
        {
            if (isFull(game))  // 填满
            {
                int flag = 0;
                for (int i = 0; i < game.GetLength(0) - 1; i++)
                {
                    for (int j = 0; j < game.GetLength(1) - 1; j++)
                    {
                        if (game[i, j] == game[i + 1, j] || game[i, j] == game[i, j + 1])
                        {
                            flag = 1;
                            return false;
                        }
                    }
                }
                for (int i = 0; i < game.GetLength(1) - 1; i++)  // 判断最下面一行
                {
                    if(game[game.GetLength(0) - 1, i] == game[game.GetLength(0) - 1, i + 1])
                    {
                        flag = 1;
                        return false;
                    }
                }
                for (int i = 0; i < game.GetLength(0) - 1; i++)   // 判断最右边一列
                {
                    if (game[i, game.GetLength(1) - 1] == game[i + 1, game.GetLength(1) - 1])
                    {
                        flag = 1;
                        return false;
                    }
                }
                if (flag == 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else  // 未填满
            {
                return false;
            }
        }

    }
}
