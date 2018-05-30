#include "dual.h"
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

//--------------------sobrecarga de funciones-------------------
template <class T>
Dual<T> cos(Dual<T> c){
  T real= cos(c.get_real());
  T dual1= -1.*sin(c.get_real())*c.get_dual1();
  T dual2= (-0.5*cos(c.get_real())*(c.get_dual1()*c.get_dual1()))-(c.get_dual2()*sin(c.get_real()));
  return Dual<T>(real, dual1, dual2);

}

template <class T>
Dual<T> sin( Dual<T> c){
  T real= sin(c.get_real());
  T dual1= c.get_dual1()*cos(c.get_real());
  T dual2= (-0.5*sin(c.get_real())*(c.get_dual1()*c.get_dual1()))+(c.get_dual2()*cos(c.get_real()));
  return Dual<T>( real,  dual1,  dual2);

}

template <class T>
Dual<T> exp(Dual<T> c){
  T real= exp(c.get_real());
  T dual1= c.get_dual1()*exp(c.get_real());
  T dual2= (0.5*exp(c.get_real())*(c.get_dual1()*c.get_dual1()))+(c.get_dual2()*exp(c.get_real()));
  return Dual<T>(real, dual1, dual2);

}

template <class T>
Dual<T> log( Dual<T>  c){
  T real= log(c.get_real());
  T dual1= c.get_dual1()/c.get_real();
  T dual2= (-0.5*(c.get_dual1()*c.get_dual1())/(c.get_real()*c.get_real()))+(c.get_dual2()/c.get_real());
  return Dual<T>(real, dual1, dual2);
}


template <class T>
Dual<T> cosec( Dual<T>  c){
  T real=1.0/sin(c.get_real());
  T dual1= -1.*c.get_dual1()*cos(c.get_real())*pow(sin(c.get_real()),-2);
  T dual2= -0.5*pow(sin(c.get_real()),-1)+2.*pow(sin(c.get_real()),-3)*pow(c.get_dual1(),2) +  -1.*c.get_dual2()*cos(c.get_real())*pow(sin(c.get_real()),-2);
  return Dual<T>(real, dual1, dual2);
}


template <class T>
Dual<T> tan( Dual<T>  c){
  T real=tan(c.get_real());
  T dual1=c.get_dual1()/(cos(c.get_real())*cos(c.get_real()));
  T dual2=-0.5*pow(c.get_dual1(),2)*sin(c.get_real())*pow(cos(c.get_real()),-3)+ c.get_dual2()/(cos(c.get_real())*cos(c.get_real()));
  return Dual<T>(real, dual1, dual2);
}


int main()
{
  //Dual con complejo arreglan la salida
  Dual<complex<double>> z1(1.,1,0.);
  Dual<complex<double>> z2(-1.,1,0.);
  Dual<double> pi(3.14159,1.,0);
  Dual<double> z(1.,1.,0.);
  Dual<double> y(-1.,1.,0.);

  //Para probar la salida 
  cout<< sin(log(cosec(exp(tan(z1)))))<<endl; 
  cout<< sin(log(cosec(exp(tan(z2)))))<<endl; 

  
  //Para probar que se calculen cosenos de pi. 
  //cout << cos(pi).get_dual1() << endl;
  //cout << sin(pi).get_dual1() << endl;
}





