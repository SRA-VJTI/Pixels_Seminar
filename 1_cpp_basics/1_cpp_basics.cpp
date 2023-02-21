
using namespace std;

int main() 
{  
      int  s[5][2] = {
           {1, 2},
           {1, 2},
           {1, 2},
           {1, 2}
           } ;
           
      int (*p)[2] ;
      int  i, j;
      //Usage of pointer to an array 
      for (i = 0 ; i <= 3 ; i++)
      {
      		p=&s[i];
      		cout<<"Row"<<i<<":";
            for (j = 0; j <= 1; j++)
                cout<<"\t"<<*(*p+j);
            cout<<endl;
      } 
      
  int  a[3][4] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21} ; 
  //Passing a 2D array pointer to function as an argument
  show (a, 3, 4);
  print (a, 3, 4);
}

void show(int (*q)[4], int  row, int  col)
{
	int  i, j ;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
    		cout<<"\t"<<*(*(q + i)+j); 
		cout<<"\n";
	}  
    cout<<"\n";
} 
 
void print(int  q[][4], int row, int col)
{
    int  i, j; 
    for(i=0;i<row;i++)
    {   
	 for(j=0;j<col;j++)
   	    	cout<<"\t"<<q[i][j];
   	 cout<<"\n";
	}
   cout<<"\n";
}
 