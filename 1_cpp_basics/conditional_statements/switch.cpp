#include <iostream>
using namespace std;
int main()
{
int day = 4;
switch (day) {//Switch statement with day given as condition for cases
  case 1://If day=1 then case1 is executed
    cout << "Monday";
    break;//if case1 is executed then break is executed and exits switch statement
  case 2://If day=2 then case2 is executed
    cout << "Tuesday";
    break;//if case2 is executed then break is executed and exits switch statement
  case 3:
    cout << "Wednesday";
    break;
  case 4:
    cout << "Thursday";
    break;
  case 5:
    cout << "Friday";
    break;
  case 6:
    cout << "Saturday";
    break;
  case 7:
    cout << "Sunday";
    break;
   default:// If none of the case is satisfied then default statement is executed.
   cout<<"Not a day";
   break; 
}
return 0;
}