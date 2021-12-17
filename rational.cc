#include <iostream>
#include "rational.h"

  //Reduces the rational number to the simplest form
  void Rational::simplify(){
      int absNum;
      int absDen;
      int starting = 0;
      
      //Absolute values the numerator of rational number
      if (num < 0){
          absNum = num * -1;
      } else {
          absNum = num;
      }
      //Absolute values the denominator of rational number
      if (den < 0){
          absDen = den * -1;
      } else {
          absDen = den; 
      }
      //Determines if the absolute numerator or absolute denominator is greater
      if (absNum > absDen){
          starting = absDen;
      } else if(absDen > absNum){
          starting = absNum;
          //Determines if rational can be reduced to 1 while num and den are not 0
      } else if((absNum == absDen) && (num < 0 || den < 0)) {
          num = -1;
          den = 1;
      } else {
          num = 1;
          den = 1;
      }
      //Simplifies the rational number
      for (int i = starting; i > 1; i--){  
          if ((num % i == 0) && (den % i == 0)){
              num /= i;
              den /= i;
              }
            }
        //If the denominator is a negative than the negative sign will be moved to the numberator
        if (den < 0){
            num = num * -1;
            den = den * -1;
        }
        //Condition to determine if numerator is 0 and den is positive in which rational gets reduced to 0/1
        if (num == 0 && den > 0){
            den = 1;   
        } 
        //Condition to determine if numerator is 0 and den is negative in which rational gets reduced to 0/1
        if (num == 0 && den < 0) {
            den = -1;
        }
  }   

  //Constructor
  Rational::Rational(int numer, int denom){
      num = numer;
      den = denom;
      simplify();
      }
  //Overloaded + operator
  Rational Rational::operator+(const Rational &rhs) const{
      int numer = (num * rhs.den) + (den * rhs.num);
      int denom = den * rhs.den;
      return Rational (numer, denom);
  }
  //Overloaded - operator
  Rational Rational::operator-(const Rational &rhs) const{
      int numer = (num * rhs.den) - (den * rhs.num);
      int denom = den * rhs.den;
      return Rational (numer, denom);
  }
  //Overloaded * operator
  Rational Rational::operator*(const Rational &rhs) const{
      int numer = num * rhs.num;
      int denom = den * rhs.den;
      return Rational (numer, denom);
  }
  //Overloaded / operator
  Rational Rational::operator/(const Rational &rhs) const{
      int numer = num * rhs.den;
      int denom = den * rhs.num;
      return Rational (numer, denom);
  }
  //Overloaded += operator
  Rational &Rational::operator+=(const Rational &rhs){
      num = num * rhs.den + den * rhs.num;
      den = den * rhs.den;
      simplify();
      return *this;
  }
  //Overloaded -= operator
  Rational &Rational::operator-=(const Rational &rhs){
      num = (num * rhs.den) - (den * rhs.num);
      den = den * rhs.den;
      simplify();
      return *this;

  }
  //Negates the Rational
  Rational Rational::operator-() const{
      int numer = num * -1;
      return Rational (numer, den);
  }
  //Returns numerator of Rational Number
  int Rational::getNumerator() const{
      return num;
  }
  //Returns denominator of Rational Number
  int Rational::getDenominator() const{
      return den;
  }
//Overloaded Output operator
std::ostream &operator<<(std::ostream &out, const Rational &rat){
    if (rat.den == 1) {
        out << rat.num;
    } else if(rat.num == 0){
        out << rat.num;
    }else {
    out << rat.num << "/" << rat.den; 
    }
    return out;


}
//Overloaded Input operator
std::istream &operator>>(std::istream &in, Rational &rat){
    char discard;
    in >> rat.num;
    in >> discard;
    in >> rat.den;
    rat.simplify();
    return in;
}


