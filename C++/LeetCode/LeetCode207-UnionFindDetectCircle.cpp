#include<iostream>
using namespace std;
#include<vector>
#include<functional>

/*
    你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1
    在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi
    例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1
    请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false
*/

// 并查集检查环
bool detectCircle(vector<vector<int>>& G, vector<int> leader, vector<bool>& detected, int begin) {
    bool result = 0;
    for (int i = 0; i < G[begin].size(); i++) {
        int end = G[begin][i];
        if(detected[end] == 1)
            continue;
        vector<int> leaderTemp = leader;
        if(leaderTemp[end] == leaderTemp[begin])
            return 1;
        leaderTemp[end] = leaderTemp[begin];
        result = result || detectCircle(G, leaderTemp, detected, end);
    }
    detected[begin] = 1;
    return result;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // 初始化图
    vector<vector<int>> G;           
    vector<int> temp;         
    G.resize(numCourses, temp);

    // 为图增加边
    for (int i = 0; i < prerequisites.size(); i++) {
        G[prerequisites[i][0]].push_back(prerequisites[i][1]);   
    }

    // 初始化结果数组
    vector<int> leader;
    for (int i = 0; i < numCourses; i++) {
        leader.push_back(i);
    }

    // 并查集检查环
    vector<bool> detected;
    detected.resize(numCourses, 0);
    int index = 0;
    bool result = 0;
    while (result == 0 && index < numCourses) {
        if(detected[index] == 0)
            result = detectCircle(G, leader, detected, index);
        index++;
    }
    return !result;
}

int main() {
    int numCourses = 8;
    vector<int> course0{1, 0};
    vector<int> course1{2, 6};
    vector<int> course2{1, 7};
    vector<int> course3{6, 4};
    vector<int> course4{7, 0};
    vector<int> course5{0, 5};

    vector<vector<int>> prerequisites{course0, course1, course2, course3, course4, course5};
    cout << canFinish(numCourses, prerequisites) << endl;
    system("pause");
    return 0;
}