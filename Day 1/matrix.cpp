#include <iostream>

using namespace std;

int b[8][8];

void set_zero()
{
	for ( int i = 0 ; i < 8 ; i++ )
		for ( int j = 0 ; j < 8 ; j++ )
			b[i][j] = 0;
}

void make ( int a[][10] )
{
	int k = 0 ;

	for ( int i = 0 ; i < 10 ; i++ )
		for ( int j = 0 ; j < 10 ; j++,k++ )
			a[i][j] = k;
}

void avg ( int a[][10] , int i , int j )
{
	int sum  = 0;

	for ( int k = i-1 ; k < i+2 ; k++ )
		for ( int l = j-1 ; l < j+2 ; l++ )
			sum = sum + a[k][l];

	b[i-1][j-1] = sum/9;
}

void work ( int a[][10] )
{
	for ( int i = 1 ; i < 9 ; i++ )
		for ( int j = 1 ; j < 9 ; j++ )
			avg(a,i,j);
}

void result ( int a[][10] )
{
	for ( int i = 1 ; i < 9 ; i++ )
		for ( int j = 1 ; j < 9 ; j++ )
			a[i][j] = b[i-1][j-1]; 
}

int main()
{
	int a[10][10];
	set_zero();
	make (a);
	work(a);
	result(a);

	for ( int i = 0 ; i < 10 ; i++ )
	{
		for ( int j = 0 ; j < 10 ; j++ )
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
	

	return 0;
}
