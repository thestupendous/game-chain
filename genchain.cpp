#include<iostream>
using namespace std;
typedef short int Y;
#define max 5																																																																																																													
typedef struct q{
Y x,y;
q* next;
}Queue,*Queuep;

#include "nei.cpp"



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

void print(Y a[max][max],Y p[max][max])
{
	cout<<endl;
	
	cout<<"        ";
	for(Y y=0;y<3;y++)
       {
	for(Y v=1;v<=max;v++){
		if(y==0)cout<<v<<"   ";
		else if(y==1)cout<<"|   ";
		else if(y==2) cout<<"v   ";
	}
	cout<<endl<<"        ";
       }
	cout<<endl;
	for(Y i=0;i<max;i++){
	cout<<"  "<<i+1<<"->   ";
	for(Y j=0;j<max;j++)
		       cout<<char(p[i][j]+96)<<a[i][j]<<"  ";
	cout<<endl;
	}cout<<endl;
}

void update(Y a[max][max],Y thres[max][max],Y inq[max][max],Queuep &h,Queuep &t,Y &x,Y &y,Y pmat[max][max],Y &turn)
{
	if(a[x][y]+1<thres[x][y]) { cout<<"updated here\n";pmat[x][y]=turn;++a[x][y]; return;}
	enq(h,t,x,y);
	inq[x][y]=1;

	while(!empty(h))
	{
cout<<"queue not empty\n";
		  if(won(pmat)) return;
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

}/*
bool fin(Y a[max][max])
{
	for(int i=0;i<max*max;i++)
		if(a[i/max][i%max]==0) return false;
	return true;
}
*/


int main()
{
	Y vmat[max][max];
	Y pmat[max][max]={0}, turn=1;
	Y thres[max][max],in[max][max],del=4;
	Queuep h=NULL,t=NULL;
	unsigned int moves=0;
	bool notend=true;
	

	initialise(vmat,0);
	initialise(thres,1);
	initialise(in,2);
	while(notend)//!won(pmat))
	{
		print(vmat,pmat);

		Y ix,iy;
		cout<<"\n\tNow turn for player :- "<<turn<<'\n';
		input(ix,iy);--ix;--iy;
		if(pmat[ix][iy]==turn || pmat[ix][iy]==0)
		{
			++moves;
			update(vmat,thres,in,h,t,ix,iy,pmat,turn);
			cout<<"\033[2J\033[1;1H";
			turn = (turn==1)?2:1;
			notend = !won(pmat);
			if(moves==1) notend = true;
		}
		else cout<<"wRONG pLACe tO PlACe YoUR mOvE!!\n";
	}
	int w=turn%2;
	cout<<"\n\t\tCongratulations player "<<w+1<<" has won!!\n";
	cout<<"reached end\n";
	//qprint(h);

}
