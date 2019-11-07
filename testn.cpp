#include<iostream>
using namespace std;
typedef short int Y;
typedef struct q{
	Y x,y;
	q* next;
}Queue,*Queuep;

#include "nei.cpp"

int main()
{
	Y thres[10][10];
	initialise(thres,1);
	int x,y;
	cin>>x>>y;
	Queuep p = neighbours(thres,x,y);
	while(p!=NULL)
	{
		cout<<"( "<<p->x<<","<<p->y<<" )  ,   ";
		p=p->next;
	}
	cout<<'\n';
	return 0;
}
