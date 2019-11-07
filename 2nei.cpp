
Queuep neighbours(Y thres[10][10],Y x,Y y)
{
	Queuep h;
	if(thres[x][y]==4)
	{
	 h = new Queue;
	 h->next = new Queue;
	 h->next->next = new Queue;
	 h->next->next->next = new Queue;
	 h->next->next->next->next = NULL;

	 h->x=x-1; h->y=y;
	 h->next->x=x; h->next->y=y-1;
	 h->next->next->x=x+1; h->next->next->y=y;
	 h->next->next->next->x=x; h->next->next->next->y=y+1;
	 
	 return h;
	}
	else if (thres[x][y]==3)
	{
	  h = new Queue;
	h->next = new Queue;
	h->next->next = new Queue;
	h->next->next->next = NULL;
	if(x==0)
	{
	h->x = h->next->x = x; h->y=y+1; h->next->y=y-1;
	h->next->next->x = x+1 ; h->next->next->y=y;
	}
	else if(y==0)
	{
	h->y = h->next->y= y; h->x = x+1; h->next->x=x-1;
	h->next->next->y=y+1; h->next->next->x=x;
	}
	else if(x==9)
	{
	h->x = h->next->x = x; h->y=y+1; h->next->y=y-1;
	h->next->next->x = x-1 ; h->next->next->y=y;
	}
	else if(y==9)
	{
	h->y = h->next->y = y; h->x=x+1; h->next->x=x-1;
	h->next->next->y = y-1 ; h->next->next->x=x;
	}
	return h;
	}

	else if(thres[x][y]==2)
	{
	h=new Queue;
	h->next = new Queue;
	h->next->next = NULL;
	if(x==0)
	{
		if(y==0)
		{
			h->x=1;h->y=0;h->next->x=0;h->next->y=1;
		}
		else
		{
			h->x=0;h->y=8;h->next->x=1;h->next->y=9;
		}
	}
	else
	{
		if(y==0)
		{
			h->x=8;h->y=0;h->next->x=9;h->next->y=1;
		}
		else
		{
			h->x=8;h->y=9;h->next->x=9;h->next->y=8;
		}
	}
	return h;
	}
	
}

void enq(Queuep &h,Queuep &t,Y a,Y b)
{
    Queuep n = new Queue;
    n->next = NULL;
    n->x=a;
    n->y=b;
    
    if(t==NULL) { h=n; t=n; return;}
    t->next = n;
    t=n;
    
}

void deq(Queuep &h, Queuep &t)
{	
    if(h->next==NULL)
    t=NULL;
    h=h->next;
}

void initialise(Y a[10][10],Y b){
	if(b==0 || b==2) for(Y i=0;i<10;i++)
		 for(Y j=0;j<10;j++)
		       a[i][j]=0;
	else if(b==1) for(Y i=0;i<10;i++)
	                for(Y j=0;j<10;j++)
	                {
	                   if((i==0 && j==0) || (i==0 && j==9) || (i==9 && j==0) || (i==9 && j==9) )
	                     a[i][j] = 2;
	                   else if(i==0 || j==0 || i==9 || j==9)
	                     a[i][j] = 3;
	                   else
	                     a[i][j] = 4;
	                }
}
bool empty(Queuep h)
{
	return (h==NULL)?1:0 ;
}
