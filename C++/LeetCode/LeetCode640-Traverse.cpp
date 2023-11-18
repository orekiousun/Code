#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    string equation = "30x+25-3+4x=36+21x-2";
    // int temp = equation[3];
    // cout << temp << endl;
    // 添加缺失的正号
    if(equation[0] != '-')
        equation.insert(0, "+");

    // 记录两边x的位置
    vector<int> leftX;
    vector<int> rightX;
    
    // 记录将常数放到右侧后的值
    int numsResToRight = 0;
    int i = 0;

    // 记录左侧常数和x的位置
    while (equation[i] != '=')
    {
        if(equation[i] == 'x')
        {
            leftX.push_back(i);
            i++;
        }
        else if(equation[i] == '+' || equation[i] == '-') 
        {
            i++;
        }
        else
        {
            int thisNum = 0;
            bool isPosotive = false;
            if(equation[i - 1] == '+') isPosotive = true;
            while (equation[i] != '+' && equation[i] != '-' && equation[i] != 'x' && equation[i] != '=' )
            {
                thisNum = thisNum * 10 + equation[i] - 48;
                i++;
            }
            if(equation[i] != 'x')
            {
                if(isPosotive) numsResToRight -= thisNum;
                else numsResToRight += thisNum;
            } 
        } 
    }

    i++;
    // 添加缺失的正号
    if(equation[i] != '-')
        equation.insert(i, "+");

    // 记录右侧常数和x的位置
    while (i < equation.size())
    {
        if(equation[i] == 'x')
        {
            rightX.push_back(i);
            i++;
        }
        else if(equation[i] == '+' || equation[i] == '-') 
        {
            i++;
        }
        else
        {
            int thisNum = 0;
            bool isPosotive = false;
            if(equation[i - 1] == '+') isPosotive = true;
            while (equation[i] != '+' && equation[i] != '-' && equation[i] != 'x' && i < equation.size() )
            {
                thisNum = thisNum * 10 + equation[i] - 48;
                i++;
            }
            if(equation[i] != 'x')
            {
                if(isPosotive) numsResToRight += thisNum;
                else numsResToRight -= thisNum;
            } 
        } 
    }
    

    cout << "numsResToRight = " << numsResToRight << endl;



    // 左侧x系数整合
    int leftXRes = 0;
    for (int i = 0; i < leftX.size(); i++)
    {
        if(equation[leftX[i] - 1] == '+')
            leftXRes += 1;
        else if(equation[leftX[i] - 1] == '-')
            leftXRes -= 1;
        else
        {
            int temp = leftX[i];
            temp --;
            int thisNum = 0, mul = 1;;
            while (equation[temp] != '+' && equation[temp] != '-')
            {
                thisNum = thisNum + (equation[temp] - 48) * mul;
                mul *= 10;
                temp --;
            }
            if(equation[temp] == '+')
                leftXRes = leftXRes + thisNum;
            else
                leftXRes = leftXRes - thisNum;
        }
    }
    cout << "leftXRes = " << leftXRes << endl;
    
    // 右侧x系数整合
    int rightXRes = 0;
    for (int i = 0; i < rightX.size(); i++)
    {
        if(equation[rightX[i] - 1] == '+')
            rightXRes += 1;
        else if(equation[rightX[i] - 1] == '-')
            rightXRes -= 1;
        else
        {
            int temp = rightX[i];
            temp --;
            int thisNum = 0, mul = 1;;
            while (equation[temp] != '+' && equation[temp] != '-')
            {
                thisNum = thisNum + (equation[temp] - 48) * mul;
                mul *= 10;
                temp --;
            }
            if(equation[temp] == '+')
                rightXRes = rightXRes + thisNum;
            else
                rightXRes = rightXRes - thisNum;
        }
    }
    cout << "rightXRes = " << rightXRes << endl;

    // x系数整合到左侧
    int xResToLeft = leftXRes - rightXRes;
    cout << "xResToLeft = " << xResToLeft << endl;

    if(xResToLeft == 0 && numsResToRight == 0) cout << "Infinite solutions" << endl;
    else if(xResToLeft == 0 && numsResToRight != 0) cout << "No solution" << endl;
    else
    {
        float res = (float)numsResToRight / (float)xResToLeft;
        cout << "x=" + to_string(res) << endl;
    }
    
    system("pause");
    return 0;
}