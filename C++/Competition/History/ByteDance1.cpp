#include<iostream>
using namespace std;
#include<vector>



int main() {
    int origin0, origin1, origin2;
    cin >> origin0 >> origin1 >> origin2;
    if(origin0 > origin1) {
        int temp = origin0;
        origin0 = origin1;
        origin1 = temp;
    }
    if(origin1 > origin2) {
        int temp = origin1;
        origin1 = origin2;
        origin2 = temp;
    }
    if(origin0 > origin1) {
        int temp = origin0;
        origin0 = origin1;
        origin1 = temp;
    }
    int n;
    cin >> n;
    int edge[n][3];
    for (int i = 0; i < n; i++) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        if(edge[i][0] > edge[i][1]) {
            int temp = edge[i][0];
            edge[i][0] = edge[i][1];
            edge[i][1] = temp;
        }
        if(edge[i][1] > edge[i][2]) {
            int temp = edge[i][1];
            edge[i][1] = edge[i][2];
            edge[i][2] = temp;
        }
        if(edge[i][0] > edge[i][1]) {
            int temp = edge[i][0];
            edge[i][0] = edge[i][1];
            edge[i][1] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        if(edge[i][0] + edge[i][1] > edge[i][2]) {
            int x = edge[i][0], y = edge[i][1], z = edge[i][2];
            if(x >= origin0) {
                int num = x / origin0;
                if(x % origin0 == 0 && y % origin1 == 0 && z % origin2 == 0 && y / origin1 == num && z / origin2 == num)
                    cout << "similar" << endl;
                else
                    cout << "Can form a triangle but not similar" << endl;
            }
            else {
                int num = origin0 / x;
                if(origin0 % x == 0 && origin1 % y == 0 && origin2 % z == 0 && origin1 / y == num && origin2 / z == num)
                    cout << "similar" << endl;
                else
                    cout << "Can form a triangle but not similar" << endl;
            }
        }
        else {
            cout << "Cannot form a triangle" << endl;
        }
    }

    system("pause");
    return 0;
}