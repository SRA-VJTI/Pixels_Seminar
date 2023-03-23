#include<iostream>
using namespace std;
/* Usage of pointer to an array */ 
int main() 
{  
     int  a[4][2] = {
          {1, 2},
          {1, 2},
          {1, 2},
          {1, 2}
          } ;
          
     int (*ptr)[2] ;
     int  i, j;
     for (i = 0 ; i <= 3 ; i++)
     {
     		ptr=&a[i];
     		cout<<"Row"<<i<<":";
            for (j = 0; j <= 1; j++)
               cout<<"\t"<<*(*ptr+j);
            cout<<endl;
     } 
   return 0;  
}