
//начало основного
#include "rect.h"
#include <iostream>
#include <cmath>
using namespace std;

//-----------------------------------------------------------------------+++
/*Конструктор, создает объект прямоугольник, инициализирует переменные,
которые заданы по условию.*/

Rectangle::Rectangle(float A, float B, float a, float d, float x3, float y3) {
 itsA=A;
  itsB=B;
   its_a=a;
    its_d=d;
     itsOldLowerRight.SetX(x3);//заданный x3                             
      itsOldLowerRight.SetY(y3);//заданный x3
}
//-----------------------------------------------------------------------+++
//Вычисляет площадь прямоугольника и возвращает это значение.
float Rectangle::GetArea() const {
 return (its_a*its_d);
 }

//-----------------------------------------------------------------------+++
//Вычисляет периметр прямоугольника и возвращает это значение. 
float Rectangle::GetPerim() const {
	return ( (its_a+its_d)*2 );
 } 

//-----------------------------------------------------------------------+++
//Возвращает значение длины стороны a.
 float Rectangle::Getits_a() const {
	return its_a;
  }

//-----------------------------------------------------------------------+++
//Возвращает значение длины стороны d.
 float Rectangle::Getits_d()const{
	 return its_d;
 }

//-----------------------------------------------------------------------+++
//Возвращает значение коэф. прямой С.
  float Rectangle::GetitsC()const{
	 return itsC;
 }

//-----------------------------------------------------------------------+++
//Найдем коэф. прямой C. Подставим в общее уравнение прямой х3 и y3, выразив из неё коэф. C
  void Rectangle::Find_C(){
  float x3, y3, A, B;
   x3=itsOldLowerRight.GetX();
	y3=itsOldLowerRight.GetY();
	 A=itsA;
	  B=itsB;
       //вычисляем C, подставив координаты точки 3 в уравнение прямой. 
	    itsC=-A*x3-B*y3;      
		
 }


//-----------------------------------------------------------------------+++
/*Преобразование нижней правой точки (x3,y3): т.е. задаёт значения этой точки, таким образом,
чтобы угол наклона прямой стал прямым, относительно осей.*/
void Rectangle::Cord_Calc_New_LowerRight(){
  float x3,y3,x,y;//x3,y3,новый х,y
    x3 =itsOldLowerRight.GetX();//достать заданную кодинату x3
	 y3 =itsOldLowerRight.GetY();//достать заданную кодинату y3
      x = x3*cos(atan(-itsA/itsB))+y3*sin(atan(-itsA/itsB));
       y= -x3*sin(atan(-itsA/itsB))+y3*cos(atan(-itsA/itsB));
	    itsRight=x;//правая точка x3
		 itsBottom=y;//нижняя точка y3
          itsLowerRight.SetX(x);//новый x3
           itsLowerRight.SetY(y);//новый y3

 }

//-----------------------------------------------------------------------+++
/*Преобразование верхней правой точки(x1,y1): т.е. задаёт значения этой точки, 
когда угол наклона прямой стал прямым относительно осей.*/
void Rectangle::Cord_Calc_New_UpperRight(float low_rect){
 //x1=x3, y1=y3+d
   itsUpperRight.SetX(itsRight);//x1
    itsTop=itsBottom+its_d ;//y1
	
	itsTop -= low_rect*2*(itsTop-itsBottom);
	/*если нужен нижний прямоугольник,
	когда в главной программе low_rect=1, то
	расстояние вниз: верх -(верх-низ)*2. 
	Если low_rect=0, то itsTop не изменится.
	*/
	itsUpperRight.SetY(itsTop);//y1
	 
 }

//-----------------------------------------------------------------------+++
/*Преобразование верхней левой точки(x2,y2): т.е. задаёт значения этой точки, 
когда угол наклона прямой стал прямым относительно осей.*/
void Rectangle::Cord_Calc_New_UpperLeft(){
   //x2=x3-a, y2=y1;
	itsLeft=itsRight-its_a;
     itsUpperLeft.SetX(itsLeft);//x2	
	   itsUpperLeft.SetY(itsTop);//новый y2 	 
	   
}

//-----------------------------------------------------------------------+++
/*Преобразование нижней левой точки(x4,y4): т.е. задаёт значения этой точки, 
когда угол наклона прямой стал прямым относительно осей.*/
void Rectangle::Cord_Calc_New_LowerLeft(){
   //x4=x2, y4=y3;
     itsLowerLeft.SetX(itsTop);//x4			 
      itsLowerLeft.SetY(itsBottom);//новый y4 	       
}

//-----------------------------------------------------------------------+++
/*Преобразуем значения всех точек в заданную систему координат, т.е. с углом наклона заданной прямой (Fi=atan(-itsA/itsB))*/
 void Rectangle::Ret_Back(){ //посчитать значения координат до поворота
 float x,y;
  float sinP = sin(atan(-itsA/itsB));
   float cosPr = cos(atan(-itsA/itsB)); 
	x=itsRight*cosPr-itsTop*sinP;//x1
	 y=itsRight*sinP+itsTop*cosPr;//y1      
	  itsUpperRight.SetX(x);//преобразовать обратно x1
       itsUpperRight.SetY(y);//преобразовать обратно y1    
        x=itsLeft*cosPr-itsTop*sinP;//x2
	     y=itsLeft*sinP+itsTop*cosPr;//y2
	      itsUpperLeft.SetX(x);//преобразовать обратно x2
           itsUpperLeft.SetY(y);//преобразовать обратно y2 
            x=itsRight*cosPr-itsBottom*sinP;//x3
	         y=itsRight*sinP+itsBottom*cosPr;//y3
	          itsLowerRight.SetX(x);//преобразовать обратно x3
               itsLowerRight.SetY(y);//преобразовать обратно y3
	            x=itsLeft*cosPr-itsBottom*sinP;//x4
	             y=itsLeft*sinP+itsBottom*cosPr;//y4
	              itsLowerLeft.SetX(x);//преобразовать обратно x4
                   itsLowerLeft.SetY(y);//преобразовать обратно y4 
 }     

 void main(){ 
   float low_rect=0; 
   //low_rect=1; //если нужен нижний прямоугольник
  
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
   MyRectang.Find_C(); //посчитать коэф. прямой С
     MyRectang.Cord_Calc_New_LowerRight();//установить в новых осях точку 3
      MyRectang.Cord_Calc_New_UpperRight(low_rect);//преобразовать точку 1
	  MyRectang.Cord_Calc_New_UpperLeft();//преобразовать точку 2
       MyRectang.Cord_Calc_New_LowerLeft();//преобразовать точку 4
        MyRectang.Ret_Back();//преобразовать значения всех точек до поворота
	 
   
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
//конец основного файла
