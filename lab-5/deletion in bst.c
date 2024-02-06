void delet(int i)
{
	temp=root;
	t=root;
	int l=0;
	while(temp!=0)
	{
		if(i==temp->n)
		{
			
			if(t==root)
			{
					if(t->next==0&&t->pre==0)
					{
						c=0;
						root=0;
					}
					else if((t->next!=0&&t->pre==0)||(t->next==0&&t->pre!=0))
					{
						if(t->next!=0)
						root=root->next;
						else
						root=root->pre;
					}
					else if((t->next!=0&&t->pre!=0))
					{
							h=t->pre;
					p=temp;
					l=0;
					while(h->next!=0)
					{
						l=1;
						p=h;
						h=h->next;
					}
					if(l==1){
					
					p->next=0;
					root->n=h->n;
					}
					else if(l==0)
					{
						root->n=h->n;
						root->pre=0;
					}
				}
					
			}
			if(t->next==temp)
			{
				if(temp->next==0&&temp->pre==0)
				t->next=0;
				else if((temp->next!=0 && temp->pre==0)||(temp->next==0 && temp->pre!=0))
				{
				if(temp->next!=0)
				t->next=temp->next;
				else
				t->next=temp->pre;
				}
				else if(temp->next!=0 && temp->pre!=0)
				{
					h=temp->pre;
					p=temp;
					l=0;
					while(h->next!=0)
					{
						l=1;
						p=h;
						h=h->next;
					}
					if(l==1){
					
					p->next=0;
					temp->n=h->n;
					}
					else if(l==0)
					{
						temp->n=h->n;
						temp->pre=0;
					}
				}
			}
			else if(t->pre==temp)
			{
				if(temp->next==0&&temp->pre==0)
				t->pre=0;
				else if((temp->next!=0 && temp->pre==0)||(temp->next==0 && temp->pre!=0))
				{
				if(temp->next!=0)
				t->pre=temp->next;s
				else
				t->pre=temp->pre;
				}
				else if(temp->next!=0 && temp->pre!=0)
				{
					h=temp->pre;
					p=temp;
					l=0;
					while(h->next!=0)
					{
						l=1;
						p=h;
						h=h->next;
					}
					if(l==1){
					
					p->next=0;
					temp->n=h->n;
					}
					else if(l==0)
					{
						temp->n=h->n;
						temp->pre=0;
					}
				}
			}
				break;
		}
		t=temp;
		if(i<temp->n)
		temp=temp->pre;
		if(i>temp->n)
		temp=temp->next;
	
	}


