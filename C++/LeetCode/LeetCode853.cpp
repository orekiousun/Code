#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Car
{
public:
    int position;
    float time;
    Car(int position, float time)
    {
        this->position = position;
        this->time = time;
    }
    
};

class Mycompare
{
public:
    bool operator()(Car& c1, Car& c2)
    {
        return c1.position > c2.position;
    }
};

int main()
{
    int target = 10;
    vector<int> position;
    position.push_back(10);
    position.push_back(8);
    position.push_back(0);
    position.push_back(5);
    position.push_back(3);

    vector<int> speed;
    speed.push_back(2);
    speed.push_back(4);
    speed.push_back(1);
    speed.push_back(1);
    speed.push_back(3);

    int size = position.size();
    vector<Car> car;
    for(int i = 0; i < size; i++)
    {
        car.push_back( Car(position[i], ((float)target - position[i]) / speed[i]) );
        // 将speed更新为时间
    }
    sort(car.begin(), car.end(), Mycompare());
    int res = 1;
    for(int i = 1; i < size; i++)
    {
        if(car[i].time > car[i - 1].time)
        {
            res++;
        }
        else
        {
            car[i].time = car[i - 1].time;
        }
    }
    cout << res << endl;

    system("pause");
    return 0;
}