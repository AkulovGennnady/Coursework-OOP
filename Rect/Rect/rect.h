//������ ������������� �����
#include <iostream>
using namespace std;

class Point {//��������� x,y 
 public:
	 void SetX(float x) { itsX = x; }
	 void SetY(float y) { itsY = y; }
	 float GetX()const { return itsX;}
	 float GetY()const { return itsY;}
 private:
	 float itsX;
	 float itsY;
 }; 
//����� ���������� ������ Point 

 class Rectangle{
  public:
	  //Rectangle(A,  B, a, d, x3, y3);
	 Rectangle::Rectangle(float, float, float ,float, float, float);//�����������
	 ~Rectangle () {}   //����������

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
	 //����� �����.����� x3, x4 ��-�� �������� 
	 void Rectangle::Cord_Calc_New_LowerRight();//x3,y3
	 void Cord_Calc_New_UpperRight(float low_rect);//x1,y1
	 void Cord_Calc_New_UpperLeft();//x2,y2
	 void Cord_Calc_New_LowerLeft();//x4,y4	 
	

	 void Ret_Back();//��������� �������� �� ��������

		 
     float GetitsC() const;	
	 float Getits_a()const;
	 float Getits_d()const;
	 float GetArea() const;
	 float GetPerim()const; 

 private:

     Point itsOldLowerRight;//������ �����.�������� ����� 3
     Point itsUpperLeft;	
	 Point itsUpperRight;	
	 Point itsLowerLeft;
	 Point itsLowerRight;

	 float itsTop;
	 float itsLeft;
	 float itsBottom;
	 float itsRight;
	
	 //������� �������������� � � d
	 float its_a;
	 float its_d;
	 //������������ �������� ������
	 float itsA;
	 float itsB;
	 float itsC;	
 };
//����� ������������� �����

