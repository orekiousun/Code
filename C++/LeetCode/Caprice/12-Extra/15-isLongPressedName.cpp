//
// Created by ousun on 2025/09/30.
// 长按键入：https://www.programmercarl.com/0925.%E9%95%BF%E6%8C%89%E9%94%AE%E5%85%A5.html#%E6%80%9D%E8%B7%AF
// 长按键入：https://leetcode.cn/problems/long-pressed-name/
//

#include <iostream>
using namespace std;
#include <vector>

// pyplrz ppyypllr
bool isLongPressedName(string name, string typed) {
    if (name.size() > typed.size())
        return false;
    
    int nameIdx = 0, typedIdx = 0;
    while (typedIdx < typed.size()) {
        if (name[nameIdx] == typed[typedIdx])
            // 刚好匹配
            nameIdx++, typedIdx++;
        else if(nameIdx > 0 && name[nameIdx - 1] == typed[typedIdx])
            // 冗余输入
            typedIdx++;
        else
            return false;
    }
 
    return nameIdx >= name.size();
}

int main() {
    return 0;
}