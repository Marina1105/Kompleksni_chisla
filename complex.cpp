#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
class complex
{
protected:
    double re;
    double im;
    double arg;
    double module;
public:
    complex();
    complex(double RE, double IM);
    complex(double RE);
    ~complex();
    complex operator-();// Ã§Ã°Ã®Ã¡Ã¨Ã²Ã¨
    complex operator+(complex &b); // Ã¯Ã°Ã Ã¢Ã¨Ã«Ã¼Ã­Ã®
    complex operator-(complex &b);
    friend complex operator* (complex &a, complex &b);
    complex operator/ (complex &c);//Ã¤Â³Ã«Ã¥Ã­Ã­Ã¿ Ã¯Ã¥Ã°Ã¥Ã¨Ã¬Ã¥Ã­Ã®Ã¢Ã Ã«Ã  
    friend complex operator^(complex &a, double x);//Ã±Ã²Ã¥Ã¯Â³Ã­Ã¼ Ã¯Ã°Ã Ã¢Ã¨Ã«Ã¼Ã­Ã®
    double getre();
    void setre(double newre);// update arg, modul
    double getim();
    void setim(double newim);// update arg, modul
    double getarg();
    void setarg(double newarg);// update re, im
    double getmodul();
    void setmodul(double newmodul);// update re, im
    void alg_to_trig();
    void trig_to_alg();
    
    void show();
    complex operator=(complex b)
    {
        re=b.re;
        im=b.im;
    }
};


complex::complex(double RE, double IM)
{
    re=RE;
    im=IM; 
}


complex::complex(double RE)
{
    re=RE;
    im=0;
}

complex::~complex()
{
}

complex complex::operator-()
{
    complex x(-re, -im);
    return x;
}

complex complex::operator-(complex &a)
{
    complex x(re, im);
    x.re=re - a.re;
    x.im=re - a.im;
    return x;
}

void complex:: show()
{
    if (im>0)
        cout <<re<<"+"<<im<<"*i";
    else
        cout<<re<<im<<"*i";
}
complex complex::operator+ (complex &b) // ???????????????????????????
{
    complex x(re, im);

    x.re = re + b.re;
    x.im = im + b.im;

    return x;
}

complex operator* (complex &a,complex &b)
{
    complex c(0,0);
    c.re=a.re*a.re-b.im*b.im;
    c.im=a.re*b.im+b.re*a.im;

    return c;
}
complex operator/ (complex &c)
{
    complex temp;

    double r = c.re * c.re + c.im * c.im;
    temp.re = (re * c.re + im * c.im) / r;
    temp.im = (im * c.re - re * c.im) / r;

    return temp;
  }
  
 double getre()
 {
        return re;
 }
 
 void setre(double newre)
 {
      re=newre;
 }
 
 double getim()
 {
        return im;
 }
    void setim(double newim) // update arg, modul
    {
      im=newim;
 }
    double getarg()
    {
        return arg;
 }
    void setarg(double newarg)// update re, im
    {
      arg=newarg;
 }
    double getmodul()
    {
        return modul;
 }
    void setmodul(double newmodul)
    {
      modul=newmodul;
 }
 complex::void trig_to_alg()
 {    
      re= modul*cos(arg);
      im= modul*in(arg);
 }
 
complex:: void alg_to_trig();
 {  
      modul=sqrt(re^2+im^2);
      arg=3.14/2;
      
 }
 
complex operator^(complex &a, double x)
{
    complex z(0,0);
    z.module=pow(a.modul,x);
    z.arg=a.arg*x;
    z.trig_to_alg();
    return z;    
}

int main(int argc, char *argv[])
{
    complex a(8,1);
    complex b(5,1);
    complex c(0,0);
    complex a1(2,0);
    complex a2(0,2);
    a2=a1^a2;
    a2.show();
    
    (-a).show();
    cout<<endl;

    (a).show();
    cout<<endl;
    (b).show();
    c.show();
    c=a*b;
    c.show();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
