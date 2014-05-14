#include <cstdlib>
#include <iostream>

using namespace std;
class complex
{
protected:
    double re;
    double im;
    double Arg;
    double Modul;
public:
    complex();
    complex(double RE, double IM);
    complex(double RE);
    ~complex();
    complex operator-();// çðîáèòè
    complex operator+(complex &b); // ïðàâèëüíî
    complex operator-(complex &b);
    friend complex operator* (complex &a, complex &b);
    complex operator/ (complex &b);//ä³ëåííÿ ïåðåèìåíîâàëà 
    friend complex operator^(complex &a, double x);//ñòåï³íü ïðàâèëüíî
    double getRe();
    void setRe(double newRe);// update arg, modul
    double getIm();
    void setIm(double newIm);// update arg, modul
    double getArg();
    void setArg(double newArg);// update re, im
    double getModul();
    void setModul(double newModul);// update re, im
    
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
complex complex::operator+ (complex &b) // ?????????? ??????????????????
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

int main(int argc, char *argv[])
{
    complex a(8,1);
    complex b(5,1);
    complex c(0,0);
    (-a).show();
    cout<<endl;

    (a).show();
    cout<<endl;
    (b).show();
    c=a*b;
    c.show();
    system("PAUSE");
    return EXIT_SUCCESS;
}
