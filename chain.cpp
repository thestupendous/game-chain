#include<iostream>
using namespace std;
typedef short int Y;

typedef struct q{
Y x,y;
q* next;
}Queue,*Queuep;

#include "2nei.cpp"



inline void input(Y &x,Y &y){ cout<<"next coordinates : "; cin>>x>>y; }



void qprint(Queuep h)
{
    Queuep p=h;
    while(p!=NULL)
    {
        cout<<"  "<<p->x<<','<<p->y;
	p=p->next;
    }
    cout<<endl;
}

void print(Y a[10][10],Y p[10][10])
{
	cout<<endl;
	
	cout<<"        ";
	for(Y y=0;y<3;y++)
       {
	for(Y v=0;v<10;v++){
		if(y==0)cout<<v<<"   ";
		else if(y==1)cout<<"|   ";
		else if(y==2) cout<<"v   ";
	}
	cout<<endl<<"        ";
       }
	cout<<endl;
	for(Y i=0;i<10;i++){
	cout<<"  "<<i<<"->   ";
	for(Y j=0;j<10;j++)
		       cout<<p[i][j]<<a[i][j]<<"  ";
	cout<<endl;
	}cout<<endl;
}

void update(Y a[10][10],Y thres[10][10],Y inq[10][10],Queuep &h,Queuep &t,Y x,Y y,Y pmat[10][10],Y turn)
{
	if(a[x][y]+1<thres[x][y]) { cout<<"updated here\n";pmat[x][y]=turn;++a[x][y]; return;}
	enq(h,t,x,y);
	inq[x][y]=1;

	while(!empty(h))
	{
cout<<"queue not empty\n";

		  Queuep p = neighbours(thres,h->x,h->y);
		  while(p!=NULL)
		  {
			  pmat[p->x][p->y]=turn;

			  if(a[p->x][p->y]+1 < thres[p->x][p->y] ) { ++ a[p->x][p->y]  ; }
			  else
			  {
				  if(inq[p->x][p->y]) { ++a[p->x][p->y]; }
				  else { enq(h,t,p->x,p->y);  inq[p->x][p->y] = 1; }
			  }
		  	  p=p->next;
		  }
		
		a[h->x][h->y] %= thres[h->x][h->y]-1 ;
		inq[h->x][h->y] = 0;
		pmat[h->x][h->y] = 0;
		deq (h,t);
	}

}
bool fin(Y a[10][10])
{
	for(Y i=0;i<100;i++)
		if(a[i/10][i%10]==0) return false;
	return true;
}


int main()
{
	Y vmat[10][10];
	Y pmat[10][10]={0}, turn=1;
	Y thres[10][10],in[10][10],del=4;
	Queuep h=NULL,t=NULL;
	

	initialise(vmat,0);
	initialise(thres,1);
	initialise(in,2);
	print(vmat,pmat);
	print(thres,pmat);
	while(!fin(vmat))
	{
		print(vmat,pmat);

		Y ix,iy;
		cout<<"\n\tNow turn for player :- "<<turn<<'\n';
		input(ix,iy);
		if(pmat[ix][iy]==turn || pmat[ix][iy]==0)
		{

			update(vmat,thres,in,h,t,ix,iy,pmat,turn);
			cout<<"\033[2J\033[1;1H";
			turn = (turn==1)?2:1;
		}
		else cout<<"wRONG pLACe tO PlACe YoUR mOvE!!\n";
	}
	qprint(h);

}
