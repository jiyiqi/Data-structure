#include <iostream>
using namespace std;

struct list
{
 int coef;//系数
 int exp;//指数
 list *next;
};

list *input()
{
 list *head,*ptr,*s;
 cout<<"输入多项式的项数"<<endl;
 int m;
 cin>>m;
 cout<<"按照降幂顺序输入系数和指数"<<endl;
 ptr=head=new list;
 head->next=NULL;
 int n=0;
 while(n<m)
 {
  s=new list;
  cin>>s->coef>>s->exp;
  if(s->coef==0)
   break;
  if(head->next==NULL)
  {
   ptr=s;
   head->next=ptr;
  }
  else
  {
   ptr->next=s;
   ptr=s;
  }
  n++;
 }
 ptr->next=NULL;
 return head;
}

void output(list *h)//输出链表
{
 list *p;
 p=h->next;
 cout<<"f(x)=";
 while(p)
 {
  if(p->next!=NULL)
     cout<<p->coef<<"X^"<<p->exp<<"+";
  else
   cout<<p->coef<<"X^"<<p->exp;
  p=p->next;
 }
 cout<<endl;
}

list *hebing(list *h1)//合并同类项
{
 list *p1,*q1,*q2;
   for(p1=h1->next;p1;p1=p1->next)
  for(q1=p1,q2=q1->next;q2;q1=q2,q2=q2->next)
   if(p1->exp==q2->exp)
   {
    p1->coef+=q2->coef;
    q1->next=q2->next;
    delete q2;
    q2=q1;//q2=q1->next;
   }
 return h1;
}

list *Multiply(list *h1,list *h2)
{ 
    list *result = new list;
    result->next = NULL;
    list *temp = result;

    list *p1, *p2; 

    p1 = h1->next;
    while (p1)
    {
        p2 = h2->next;
        while (p2)
        {
            list *q = new list;
            q->coef = p1->coef * p2->coef;
            q->exp = p1->exp + p2->exp;
            
            temp->next = q;
            q->next = NULL;
            temp = q;

            p2 = p2->next;
        }
        p1 = p1->next;
    }

    result = hebing(result);
    return result; 
}

int main()
{
 list *h1,*h2;

 h1=input();
 output(h1);

 h2=input();
 output(h2);
 h1=Multiply(h1,h2);
 output(h1);
 system("pause");
}