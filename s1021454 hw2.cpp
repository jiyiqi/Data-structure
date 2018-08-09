#include<iostream>
#include<list>
using namespace std;

class pol
{
public:
	pol(){};
	pol(int a,int b)
		:coef(a),exp(b)
	{}
	int coef;
	int exp;
};

class polyarith
{
public:
	polyarith()
	{};
	void input();
	void output();
	void mul();
private:
	list<pol> first;
	list<pol>second;
	list<pol>result;
	list<pol> Add(list<pol>& first ,list<pol>& second);
};

void polyarith::mul()
{
 list<pol> result1;
 list<pol>::iterator iter_first=first.begin();
 for(;iter_first!=first.end();iter_first++)
 {
  list<pol> poly_tmp;
  list<pol>::iterator iter_second=second.begin();
  for(;iter_second!=second.end();iter_second++)
  {
   pol t_tmp;
   pol t_first=(pol)*iter_first;
   pol t_second=(pol)*iter_second;
   t_tmp.coef=t_first.coef*t_second.coef;
   t_tmp.exp=t_first.exp+t_second.exp;
   poly_tmp.push_back(t_tmp);
  }//��һ������ʽ�ĵ�һ��͵ڶ�������ʽȫ���˺�
  result1=Add(poly_tmp,result1);
 }
 result=result1;
}


list<pol> polyarith::Add(list<pol>& tmp,list<pol>& res)
{
 list<pol> result2;//�洢���
 list<pol>::iterator iter_first=tmp.begin();
 list<pol>::iterator iter_second=res.begin();
 while((iter_first!=tmp.end())&&(iter_second!=res.end()))//������������û��ָ��β��
 {
  pol t_tmp;
  pol t_first=(pol)*iter_first;
  pol t_second=(pol)*iter_second;//�洢ֵ
  if(t_first.exp>t_second.exp)
  {
   result2.push_back(t_first);
   iter_first++;
  }
  else if(t_second.exp>t_first.exp)
  {
   result2.push_back(t_second);
   iter_second++;
  }
  else
  {
   t_tmp.coef=t_first.coef+t_second.coef;
    t_tmp.exp=t_first.exp;
    result2.push_back(t_tmp);
   iter_first++;
   iter_second++;
  }
 }
 for(;iter_first!=tmp.end();iter_first++)//��һ��û��ָ��β�� �ڶ���ָ��β��
 result2.push_back(*iter_first);
 for(;iter_second!=res.end();iter_second++)//�ڶ���û��ָ��β�� ��һ��ָ��β��
  result2.push_back(*iter_second);
 return result2;
}

void polyarith::input()
{
	int n;
	cout<<" �����һ������ʽ����"<<endl;
	cin>>n;
	cout<<"���ս���˳������ϵ����ָ��"<<endl;
	for(int i=1;i<=n;i++)
	{
	pol a;
	cout<<"�����"<<i<<"��ϵ����ָ��"<<endl;
	cin>>a.coef;
	cin>>a.exp;
	first.push_back(a);
	}

		cout<<" ����ڶ�������ʽ����"<<endl;
	cin>>n;
	cout<<"���ս���˳������ϵ����ָ��"<<endl;
	for(int i=1;i<=n;i++)
	{
	pol a;
	cout<<"�����"<<i<<"��ϵ����ָ��"<<endl;
	cin>>a.coef;
	cin>>a.exp;
	second.push_back(a);
	}
}

void polyarith::output()
{
	list<pol>::iterator b=first.begin();
	cout<<"��һ������ʽ�ǣ�";
	while(b!=first.end())
	{
	  pol c=*b;
	  cout<<c.coef<<"x^"<<c.exp;
	  if(++b!=first.end())
	  {
	  cout<<"+";
	  }
	}
	cout<<endl;

	b=second.begin();
	cout<<"�ڶ�������ʽ�ǣ�";
		while(b!=second.end())
	{
	  pol c=*b;
	  cout<<c.coef<<"x^"<<c.exp;
	  if(++b!=second.end())
	  {
	  cout<<"+";
	  }
	}
	cout<<endl;

		b=result.begin();
	cout<<"����ǣ�";
		while(b!=result.end())
	{
	  pol c=*b;
	  cout<<c.coef<<"x^"<<c.exp;
	  if(++b!=result.end())
	  {
	  cout<<"+";
	  }
	}
	cout<<endl;
}

int main()
{
	polyarith a;
	a.input();
	a.mul();
	cout<<"����ʽ�˷������"<<endl;
	a.output();
	system("pause");
};