#include <iostream>
using namespace std;

enum seasons
{
    spring = 34,
    summer = 4,
    autumn = 9,
    winter = 32
};
// enum named season is made and spring,summer ,autumn and winter are its member with values 34,5,9,32 respectively
int main()
{

    seasons s; // s is a variable of type seasons(enum)

    s = summer; // s is assigned value of summer
    cout << "Summer = " << s << endl;

    return 0;
}
