#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

// 优化前：简单遍历：性能不好
// int main()
// {
//     vector<int> height{1,8,6,2,5,4,8,3,7};
//     int size = height.size();
//     int left = 0, right = size - 1;
//     int res = min(height[left], height[right]) * (right - left);
//     for (left = 0; left < size; left++)
//     {
//         if(height[left] < height[0]) continue;
//         else
//         {
//             for (right = size - 1; right > left; right--)
//             {
//                 if(height[right] >= height[left])
//                 {
//                     int tempRes = min(height[left], height[right]) * (right - left);
//                     if(tempRes > res) res = tempRes;
//                     break;
//                 }
//                 else if(height[right] < height[size - 1])
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     int tempRes = min(height[left], height[right]) * (right - left);
//                     if(tempRes > res) res = tempRes;
//                 }
//             }   
//         }
//     }
//     cout << res << endl;
//     system("pause");
//     return 0;
// }

// 双指针：每次移动对应数字较小的指针
/*
    双指针代表的是 可以作为容器边界的所有位置的范围
    在一开始，双指针指向数组的左右边界，表示 数组中所有的位置都可以作为容器的边界，因为我们还没有进行过任何尝试
    在这之后，我们每次将 对应的数字较小的那个指针 往 另一个指针 的方向移动一个位置，就表示我们认为 这个指针不可能再作为容器的边界了
    这么做的原因：由于容器的高度是由较矮的一端决定的
        1-如果移动较高的一端，容器的高度只可能更矮或者不变，容器的宽度一定变短，容器体积一定变小
        2-如果移动较矮的一端，容器的高度可能变矮、变高或者不变，容器的宽度一定变短，但是体积可能变大
*/
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int res = 0;
    while (left < right)
    {
        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
        int tempRes = min(height[left], height[right]) * (right - left);
        if(tempRes > res) res = tempRes;
    }
    return res;
}

int main()
{
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    system("pause");
    return 0;
}