#include <conio.h>
#include <stdio.h>


class Line {
public:
	int lenght;
public:
	Line(){ //Конструктор без параметра
		printf("Line()\n");	
		lenght = 0;
	}
	Line(int lenght) { //конструктор с параметром
		printf("Line(int lenght)\n");
		this->lenght = lenght;
	}
	Line(const Line &l) { //Конструктор копирования
		printf("Line(const Line &l)\n");
		lenght = l.lenght;
	}
	~Line() { //Деструктор
		printf("%d\n", lenght); 
		printf("~Line()\n");
	}
	void increase(int dlenght) { 
		printf("lenght = %d + %d\n",lenght, dlenght);
		lenght = lenght + dlenght; //Реализация метода сразу в определении
		
	}
	void decrease();
};

void Line::decrease() { //Реализация метода после его определения
	lenght = lenght - 5;
}

//----------------------------------------------------------------

class ColorLine: public Line{
protected:
	int color;
public:
	ColorLine(): Line() { //Конструктор без параметра
		printf("ColorLine()\n");
		color = 0;
	}
	ColorLine(int color, int lenght): Line(lenght) { //конструктор с параметром
		printf("ColorLine(int lenght)\n");
		this->color = color;
	}
	ColorLine(const ColorLine& l)  { //Конструктор копирования
		printf("ColorLine(const ColorLine &l)\n");
		lenght = l.lenght; 
		color = l.color;
	}
	~ColorLine() { //Деструктор
		printf("color= %d, lenght= %d\n", color, lenght);
		printf("~ColorLine()\n");
	}
	void ChangePos(int dcolor) {
		color = color + dcolor; //Реализация метода сразу в определении
	}
};

//---------------------------------------------------------------------

class Square {
protected:
	Line* l1;
	Line* l2;
	Line* l3;
	Line* l4;
public:
	Square() { //Конструктор без параметра
		printf("Square()\n");
		l1 = new Line;
		l2 = new Line;
		l3 = new Line;
		l4 = new Line;
	}
	Square(int lenght) { //конструктор с параметром
		printf("Square(int lenght)\n");
		this->l1 = l1;
		this->l2 = l2;
		this->l3 = l3;
		this->l4 = l4;
	}
	Square(const Square& s) { //Конструктор копирования
		printf("Square(const Square &l)\n");
		l1 = new Line(*(s.l1));
		l2 = new Line(*(s.l2));
		l3 = new Line(*(s.l3));
		l4 = new Line(*(s.l4));
	}
	~Square() { //Деструктор
		//printf("%d\n", lenght);
		delete l1;
		delete l2;
		delete l3;
		delete l4;
		printf("~Square()\n");
	}
};



int main() {
	
	//композиция классов
	//Square* s1 = new Square; //Создание класса Квадрат из объектов класса Линия
	//Square* s2 = new Square(*s1); //Создание класса Квадрат из объектов класса Линия  
	//							  //при помощи конструктора копирования класса Квадрат
	//delete s1;
	//delete s2;

	//----------------------------------------------------------------------------------------
	
	//Line* l = new ColorLine(3, 10); //помещение объекта потомка в указатель на базовый класс
	//ColorLine *l2 = new ColorLine(3, 10); //Помещение объекта класса ColorLine в переменную класса предка
	//
	//delete l;
	//delete l2;

	//----------------------------------------------------------------------------------------

	//Создание объекта класса наследника и проверка работы с ним конструкторов и деструкторов 
	ColorLine* l = new ColorLine();//Динамическое создание класса наследника
	ColorLine* l2 = new ColorLine(3, 10);
	ColorLine* l3 = new ColorLine(*l2);

	l->increase(5);
	l2->increase(10);
	l3->increase(2);


	delete l;
	delete l2;
	delete l3;
	
//-------------------------------------------------------------------------------------------
	
	//Использование метода для увеличения параметра динамически созданных объектов
	//printf("Dynamic create\n");
	//Line* l = new Line();
	//Line* l2 = new Line(10);
	//Line* l3 = new Line(*l2);

	//l->increase(10);//Метод increase увеличивающий параметр lenght объектов
	//l2->increase(5);
	//l3->increase(2);

	////l->decrease();//Метод decrease уменьшающий параметр lenght объектов
	////l2->decrease();
	////l3->decrease();
	
	//printf("Dynamic delete\n");
	//delete l;
	//delete l2;
	//delete l3;

//-------------------------------------------------------------------------------------------
	
	////Статическое создание объектов класса
	//Line l; //без параметров
	//Line l2(10); //с параметром
	//Line l3(l2); //с параметром другого объекта класса
	//
	//l.increase(5);
	//l2.increase(2);
	//l3.increase(3);

//-----------------------------------------------------------------------
	
	////Динамическое создание объектов класса
	//Line* l = new Line(); //без параметра 
	//Line* l2 = new Line(10); //с параметром
	//Line* l3 = new Line(*l2); //с параметром другого объекта класса 

	////Удаление динамически созданных объектов
	//delete l; 
	//delete l2;
	//delete l3;

//-------------------------------------------------------------------------------------------
	return 0;
}