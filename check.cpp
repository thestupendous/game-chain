#include<iostream>
using namespace std;
typedef short int Y;
#define max 3
bool won(Y pmat[max][max])
{
	Y a=-1,b=-1;
	for(Y i=0;i<max*max;i++)
	{
		if (a!=-1) b=a;
		if(pmat[i/max][i%max])
		{
			a=pmat[i/max][i%max];
			cout<<"updated a\n at "<<(i/max)<<','<<(i%max)<<"  as "<<a<<endl;
		}
		if(b!=a && b!=-1) return false;
	}
	if(a==b && b==-1) return false;
	return true;
}

int main()
{
	Y pmat[max][max]={ {0,0,0}, {0,0,0}, {0,0,0} };
	cout<<won(pmat);
	return 0;
}
	

