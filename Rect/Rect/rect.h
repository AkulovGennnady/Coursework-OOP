//начало заголовочного файла
#include <iostream>
using namespace std;

class Point {//коодинаты x,y 
 public:
	 void SetX(float x) { itsX = x; }
	 void SetY(float y) { itsY = y; }
	 float GetX()const { return itsX;}
	 float GetY()const { return itsY;}
 private:
	 float itsX;
	 float itsY;
 }; 
//конец объ€влени€ класса Point 

 class Rectangle{
  public:
	  //Rectangle(A,  B, a, d, x3, y3);
	 Rectangle::Rectangle(float, float, float ,float, float, float);//конструктор
	 ~Rectangle () {}   //деструктор

	 float GetTop() const { return itsTop; }
	 float GetLeft() const { return itsLeft; }
	 float GetBottom() const { return itsBottom; }
	 float GetRight() const { return itsRight; }		
	 
	 Point GetUpperLeft() const { return itsUpperLeft; }
	 Point GetLowerLeft() const { return itsLowerLeft; }
	 Point GetUpperRight() const { return itsUpperRight; }
	 Point GetLowerRight() const { return itsLowerRight; }

	 
	 void SetTop(float top); 
	 void SetLeft (float left); 
	 void SetBottom (float bottom);
	 void SetRight (float right);
	
	 void Find_C();
	 //новые коорд.точек x3, x4 из-за поворота 
	 void Rectangle::Cord_Calc_New_LowerRight();//x3,y3
	 void Cord_Calc_New_UpperRight(float low_rect);//x1,y1
	 void Cord_Calc_New_UpperLeft();//x2,y2
	 void Cord_Calc_New_LowerLeft();//x4,y4	 
	

	 void Ret_Back();//посчитать значени€ до поворота

		 
     float GetitsC() const;	
	 float Getits_a()const;
	 float Getits_d()const;
	 float GetArea() const;
	 float GetPerim()const; 

 private:

     Point itsOldLowerRight;//старые коорд.заданной точки 3
     Point itsUpperLeft;	
	 Point itsUpperRight;	
	 Point itsLowerLeft;
	 Point itsLowerRight;

	 float itsTop;
	 float itsLeft;
	 float itsBottom;
	 float itsRight;
	
	 //стороны пр€моугольника а и d
	 float its_a;
	 float its_d;
	 //коэффициенты заданной пр€мой
	 float itsA;
	 float itsB;
	 float itsC;	
 };
//конец заголовочного файла

