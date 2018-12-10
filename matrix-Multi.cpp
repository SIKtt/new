/*************************
 **作者：高俊峰
 **创始时间：2018-11-16
 **描述：
 **矩阵类的创建，以及基本操作
 ****************************/
#include<iostream>
using namespace std;
///<summary>
///矩阵类，m为行数，n为列数
///</summary>
class Matrix{
public : int m;
public : int n;
public : int **matr_;
  Matrix(int _m,int _n)
  {
    m=_m;
    n=_n;
    //动态分配内存
    matr_=new int*[m];
    for(int i=0;i<m;i++)
      matr_[i]=new int[n];
  }
};
///<summary>
///矩阵相乘
///<summary/>
Matrix *Multi(Matrix a,Matrix b)
  {
    if(a.n!=b.m)
      return 0; 
  int s=0;
  int m_a =a.m;
  int p =a.n;
  int n_b =b.n;
  Matrix *mt = new Matrix(m_a,n_b); 
  for(int i=0;i<m_a;i++)
{
  for(int k=0;k<n_b;k++)
    {      
  for(int j=0;j<p;j++)      
	s=s+(a.matr_)[i][j]*(b.matr_)[j][k];       
       (mt->matr_)[i][k]=s;
       s=0;
    }
}
  return mt;
  }
///<summary>
///转置
///<summary/>
Matrix *Transpose(Matrix a)
{
  Matrix *b=new Matrix(a.n,a.m);
  for(int i=0;i<a.m;i++)
    for(int j=0;j<a.n;j++)
      (b->matr_)[j][i]=(a.matr_)[i][j];
  return b;
}
int main()
{ 
  Matrix *a=new Matrix(2,2);
  (a->matr_)[0][0]=1;
  (a->matr_)[0][1]=2;
  (a->matr_)[1][0]=1;
  (a->matr_)[1][1]=3;
  Matrix *b=new Matrix(2,2);
  (b->matr_)[0][0]=1;
  (b->matr_)[0][1]=2;
  (b->matr_)[1][0]=2;
  (b->matr_)[1][1]=3;
  Matrix *c=Multi(*a,*b);
  Matrix *d=Transpose(*c);
  for(int i=0;i<(c->m);i++)
    {
      cout<<"\n";
    for(int j=0;j<(c->n);j++)
      cout<<(c->matr_)[i][j]<<"  ";
    }  
for(int i=0;i<(c->m);i++)
    {
      cout<<"\n";
    for(int j=0;j<(c->n);j++)
      cout<<(d->matr_)[i][j]<<"  ";
    }
}
