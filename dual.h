// ------------- Archivo dual.h-----------
#ifndef DUAL_H
#define DUAL_H
#include <iostream>
#include <cmath>

using namespace std;


//----------- Definicion de la clase------------------

template <class T>
class Dual{
  
 private:
  T real;
  T dual1;
  T dual2; 

 public:
  Dual();
  Dual(T , T=0 , T=0 ); // constructor esta sin el dafault
  ~Dual(); //destructor Dual
  void set_real(T);
  void set_dual1(T);
  void set_dual2(T);
  T get_real() const;
  T get_dual1() const;
  T get_dual2() const;
  Dual(const Dual &); 
  
};

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
T Dual<T>::get_real() const {
  return real;  
  }

//funcion retorna parte dual 
template <class T>
T Dual<T>::get_dual1() const{
  return dual1; 
  }

//funcion retorna parte dual 
template <class T>
T Dual<T>::get_dual2() const {
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
  return os; 
}


#endif
