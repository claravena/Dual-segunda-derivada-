//--------- Archivo Complejos.cc-------
#include "dual.h"
#include "cmath"
#include <iostream>

//constructor
template <class T>
Dual<T>::Dual( T x,  T y,  T z){
  real=x;
  dual1=y;
  dual2=z;
  
}
template <class T>
Dual<T>::Dual(){
}

template <class T>
Dual<T>::~Dual(){
}

//funcion que asigna parte real
template <class T>
void Dual<T>::set_real(T x){
  real = x; 
} 
//funcion que asigna parte dual1 
template <class T>
void Dual<T>::set_dual1(T x){
  dual1 = x; 
}


//funcion que asigna parte dual2 
template <class T>
void Dual<T>::set_dual2(T x){
  dual2 = x; 
  }

//funcion retorma parte real 
template <class T>
T Dual<T>::get_real(){
  return real;  
  }

//funcion retorna parte dual 
template <class T>
T Dual<T>::get_dual1(){
  return dual1; 
  }

//funcion retorna parte dual 
template <class T>
T Dual<T>::get_dual2(){
  return dual2; 
  }


//Construcctor de copia
template <class T>
Dual<T>::Dual(const Dual<T> & z){
  real = z.real; 
  dual1 = z.dual1;
  dual2 = z.dual2;
  
  }


//Operador suma
template <class T>
Dual<T> operator + (Dual<T> z1 , Dual<T> z2 ){
  return Dual<T>(z1.get_real()+z2.get_real(),z1.get_dual1()+z2.get_dual1(),z1.get_dual2()+z2.get_dual2() );
}

//Operador resta
template <class T>
Dual<T> operator - (Dual<T> z1, Dual<T> z2){
  return Dual<T>(z1.get_real()-z2.get_real(),z1.get_dual1()-z2.get_dual1(),z1.get_dual2()-z2.get_dual2());
}

//Operador producto & de dos duales 
template <class T>
Dual<T> operator * (Dual<T> z1, Dual<T> z2){
  return Dual<T>(z1.get_real()*z2.get_real(),z1.get_real()*z2.get_dual1()+z2.get_real()*z1.get_dual1(), z2.get_real()*z1.get_dual2()+z2.get_dual1()*z1.get_dual1());
}

//Operador producto por escalar
template <class T>
Dual<T> operator * (int c, Dual<T> z1){
  return Dual<T>(c*z1.get_real(),c*z1.get_dual1(), c*z1.get_dual2());
}

//operador cout
template <class T>
ostream & operator << (ostream & os, Dual<T> c){
  os << c.get_real() << "," << c.get_dual1()<< "e"<< "," << c.get_dual2()<< "e^2"; 
};


//sobrecarga de funciones
template <class T>
Dual<T> cos(Dual<T> c){
  T real= cos(c.get_real());
  T dual1= -1*sin(c.get_real())*c.get_dual1();
  T dual2= (-1*cos(c.get_real())*(c.get_dual1()*c.get_dual1()))-(c.get_dual2()*sin(c.get_real()));
  return Dual<T>(real, dual1, dual2);

}

template <class T>
Dual<T> sin( Dual<T> c){
  T real= sin(c.get_real());
  T dual1= c.get_dual1()*cos(c.get_real());
  T dual2= (-1*sin(c.get_real())*(c.get_dual1()*c.get_dual1()))+(c.get_dual2()*cos(c.get_real()));
  return Dual<T>( real,  dual1,  dual2);

}

template <class T>
Dual<T> exp(Dual<T> &c){
  T real= exp(c.get_real());
  T dual1= c.get_dual1()*exp(c.get_real());
  T dual2= (exp(c.get_real())*(c.get_dual1()*c.get_dual1()))+(c.get_dual2()*exp(c.get_real()));
  return Dual<T>(real, dual1, dual2);

}

template <class T>
Dual<T> log( Dual<T> & c){
  T real= log(c.get_real());
  T dual1= c.get_dual1()/c.get_real();
  T dual2= (-1*(c.get_dual1()*c.get_dual1())/(c.get_real()*c.get_real()))+(c.get_dual2()/c.get_real());
  return Dual<T>(real, dual1, dual2);
}


template <class T>
Dual<T> cosec( Dual<T> & c){
  T real=1.0/sin(c.get_real());
  T dual1= -1*c.get_dual1()*cos(c.get_real())*pow(sin(c.get_real()),-2);
  T dual2= -pow(sin(c.get_real()),-1)+2*pow(sin(c.get_real()),-3)*pow(c.get_dual1(),2) +  -1*c.get_dual2()*cos(c.get_real())*pow(sin(c.get_real()),-2);
  return Dual<T>(real, dual1, dual2);
}


template <class T>
Dual<T> tan( Dual<T> & c){
  T real=tan(c.get_real());
  T dual1=c.get_dual1()/(cos(c.get_real())*cos(c.get_real()));
  T dual2=pow(c.get_dual1(),2)*sin(c.get_real())*pow(cos(c.get_real()),-3)+ c.get_dual2()/(cos(c.get_real())*cos(c.get_real()));
  return Dual<T>(real, dual1, dual2);
}








