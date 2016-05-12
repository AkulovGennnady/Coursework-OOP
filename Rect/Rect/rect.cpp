
//������ ���������
#include "rect.h"
#include <iostream>
#include <cmath>
using namespace std;

//-----------------------------------------------------------------------+++
/*�����������, ������� ������ �������������, �������������� ����������,
������� ������ �� �������.*/

Rectangle::Rectangle(float A, float B, float a, float d, float x3, float y3) {
 itsA=A;
  itsB=B;
   its_a=a;
    its_d=d;
     itsOldLowerRight.SetX(x3);//�������� x3                             
      itsOldLowerRight.SetY(y3);//�������� x3
}
//-----------------------------------------------------------------------+++
//��������� ������� �������������� � ���������� ��� ��������.
float Rectangle::GetArea() const {
 return (its_a*its_d);
 }

//-----------------------------------------------------------------------+++
//��������� �������� �������������� � ���������� ��� ��������. 
float Rectangle::GetPerim() const {
	return ( (its_a+its_d)*2 );
 } 

//-----------------------------------------------------------------------+++
//���������� �������� ����� ������� a.
 float Rectangle::Getits_a() const {
	return its_a;
  }

//-----------------------------------------------------------------------+++
//���������� �������� ����� ������� d.
 float Rectangle::Getits_d()const{
	 return its_d;
 }

//-----------------------------------------------------------------------+++
//���������� �������� ����. ������ �.
  float Rectangle::GetitsC()const{
	 return itsC;
 }

//-----------------------------------------------------------------------+++
//������ ����. ������ C. ��������� � ����� ��������� ������ �3 � y3, ������� �� �� ����. C
  void Rectangle::Find_C(){
  float x3, y3, A, B;
   x3=itsOldLowerRight.GetX();
	y3=itsOldLowerRight.GetY();
	 A=itsA;
	  B=itsB;
       //��������� C, ��������� ���������� ����� 3 � ��������� ������. 
	    itsC=-A*x3-B*y3;      
		
 }


//-----------------------------------------------------------------------+++
/*�������������� ������ ������ ����� (x3,y3): �.�. ����� �������� ���� �����, ����� �������,
����� ���� ������� ������ ���� ������, ������������ ����.*/
void Rectangle::Cord_Calc_New_LowerRight(){
  float x3,y3,x,y;//x3,y3,����� �,y
    x3 =itsOldLowerRight.GetX();//������� �������� �������� x3
	 y3 =itsOldLowerRight.GetY();//������� �������� �������� y3
      x = x3*cos(atan(-itsA/itsB))+y3*sin(atan(-itsA/itsB));
       y= -x3*sin(atan(-itsA/itsB))+y3*cos(atan(-itsA/itsB));
	    itsRight=x;//������ ����� x3
		 itsBottom=y;//������ ����� y3
          itsLowerRight.SetX(x);//����� x3
           itsLowerRight.SetY(y);//����� y3

 }

//-----------------------------------------------------------------------+++
/*�������������� ������� ������ �����(x1,y1): �.�. ����� �������� ���� �����, 
����� ���� ������� ������ ���� ������ ������������ ����.*/
void Rectangle::Cord_Calc_New_UpperRight(float low_rect){
 //x1=x3, y1=y3+d
   itsUpperRight.SetX(itsRight);//x1
    itsTop=itsBottom+its_d ;//y1
	
	itsTop -= low_rect*2*(itsTop-itsBottom);
	/*���� ����� ������ �������������,
	����� � ������� ��������� low_rect=1, ��
	���������� ����: ���� -(����-���)*2. 
	���� low_rect=0, �� itsTop �� ���������.
	*/
	itsUpperRight.SetY(itsTop);//y1
	 
 }

//-----------------------------------------------------------------------+++
/*�������������� ������� ����� �����(x2,y2): �.�. ����� �������� ���� �����, 
����� ���� ������� ������ ���� ������ ������������ ����.*/
void Rectangle::Cord_Calc_New_UpperLeft(){
   //x2=x3-a, y2=y1;
	itsLeft=itsRight-its_a;
     itsUpperLeft.SetX(itsLeft);//x2	
	   itsUpperLeft.SetY(itsTop);//����� y2 	 
	   
}

//-----------------------------------------------------------------------+++
/*�������������� ������ ����� �����(x4,y4): �.�. ����� �������� ���� �����, 
����� ���� ������� ������ ���� ������ ������������ ����.*/
void Rectangle::Cord_Calc_New_LowerLeft(){
   //x4=x2, y4=y3;
     itsLowerLeft.SetX(itsTop);//x4			 
      itsLowerLeft.SetY(itsBottom);//����� y4 	       
}

//-----------------------------------------------------------------------+++
/*����������� �������� ���� ����� � �������� ������� ���������, �.�. � ����� ������� �������� ������ (Fi=atan(-itsA/itsB))*/
 void Rectangle::Ret_Back(){ //��������� �������� ��������� �� ��������
 float x,y;
  float sinP = sin(atan(-itsA/itsB));
   float cosPr = cos(atan(-itsA/itsB)); 
	x=itsRight*cosPr-itsTop*sinP;//x1
	 y=itsRight*sinP+itsTop*cosPr;//y1      
	  itsUpperRight.SetX(x);//������������� ������� x1
       itsUpperRight.SetY(y);//������������� ������� y1    
        x=itsLeft*cosPr-itsTop*sinP;//x2
	     y=itsLeft*sinP+itsTop*cosPr;//y2
	      itsUpperLeft.SetX(x);//������������� ������� x2
           itsUpperLeft.SetY(y);//������������� ������� y2 
            x=itsRight*cosPr-itsBottom*sinP;//x3
	         y=itsRight*sinP+itsBottom*cosPr;//y3
	          itsLowerRight.SetX(x);//������������� ������� x3
               itsLowerRight.SetY(y);//������������� ������� y3
	            x=itsLeft*cosPr-itsBottom*sinP;//x4
	             y=itsLeft*sinP+itsBottom*cosPr;//y4
	              itsLowerLeft.SetX(x);//������������� ������� x4
                   itsLowerLeft.SetY(y);//������������� ������� y4 
 }     

 void main(){ 
   float low_rect=0; 
   //low_rect=1; //���� ����� ������ �������������
  
   //Rectangle(A,  B, a, d, x3, y3);
  //Rectangle MyRectang( 6, -11, 5, 3.5, 10.9, 7.9); 
  float A,  B, a, d, x3, y3;
     cout<<" A = : ";
	  cin>>A;
	  cout<<" B = : ";
	   cin>>B;
	   cout<<" a = : ";
	    cin>>a;
		cout<<" d = : ";
	     cin>>d;
		 cout<<" x3 = : ";
	      cin>>x3;
		  cout<<" y3 = : ";
	       cin>>y3;

  Rectangle MyRectang(A,  B, a, d, x3, y3); 
   MyRectang.Find_C(); //��������� ����. ������ �
     MyRectang.Cord_Calc_New_LowerRight();//���������� � ����� ���� ����� 3
      MyRectang.Cord_Calc_New_UpperRight(low_rect);//������������� ����� 1
	  MyRectang.Cord_Calc_New_UpperLeft();//������������� ����� 2
       MyRectang.Cord_Calc_New_LowerLeft();//������������� ����� 4
        MyRectang.Ret_Back();//������������� �������� ���� ����� �� ��������
	 
   
	 a = MyRectang.Getits_a();
	   d = MyRectang.Getits_d();
	   float C = MyRectang.GetitsC();	    
	     float Area = MyRectang.GetArea();
	      float Per = MyRectang.GetPerim();
		   cout<<" Results : \n\n";
		    
		  cout<<" Known : \n\n";
		   cout <<" a: " << a << '\n';
	        cout <<" d: " << d << "\n\n";

	        cout<<" Calculated : \n\n";

			 cout <<" C: " << C << '\n';		   
	          cout <<" Area: " << Area << '\n';
	           cout << " Perimeter: " << Per << "\n\n";

	 cout << " Upper Rigth X Coordinate (x1): ";
	  cout << MyRectang.GetUpperRight().GetX()<<'\n';  
	   cout << " Upper Right Y Coordinate (y1): ";
	    cout << MyRectang.GetUpperRight().GetY()<<"\n";
	 
	 cout << " Upper Left X Coordinate (x2) : ";
	  cout << MyRectang.GetUpperLeft().GetX()<<'\n';  
	   cout << " Upper Left Y Coordinate (y2) : ";
	    cout << MyRectang.GetUpperLeft().GetY()<<'\n';
     
	 cout << " Lower Rigth X Coordinate (x3): ";
	  cout << MyRectang.GetLowerRight().GetX()<<'\n';  
	   cout << " Lower Right Y Coordinate (y3): ";
	    cout << MyRectang.GetLowerRight().GetY()<<'\n';
	 
	 cout << " Lower Rigth X Coordinate (x4): ";
	  cout << MyRectang.GetLowerLeft().GetX()<<'\n';  
	   cout << " Lower Left Y Coordinate (y4) : ";
	    cout << MyRectang.GetLowerLeft().GetY()<<'\n';
	 
	 system ("pause"); 
 } 
//����� ��������� �����
