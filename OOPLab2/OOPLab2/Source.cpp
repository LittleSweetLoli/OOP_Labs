#include <conio.h>
#include <stdio.h>


class Line {
public:
	int lenght;
public:
	Line(){ //����������� ��� ���������
		printf("Line()\n");	
		lenght = 0;
	}
	Line(int lenght) { //����������� � ����������
		printf("Line(int lenght)\n");
		this->lenght = lenght;
	}
	Line(const Line &l) { //����������� �����������
		printf("Line(const Line &l)\n");
		lenght = l.lenght;
	}
	~Line() { //����������
		printf("%d\n", lenght); 
		printf("~Line()\n");
	}
	void increase(int dlenght) { 
		printf("lenght = %d + %d\n",lenght, dlenght);
		lenght = lenght + dlenght; //���������� ������ ����� � �����������
		
	}
	void decrease();
};

void Line::decrease() { //���������� ������ ����� ��� �����������
	lenght = lenght - 5;
}

//----------------------------------------------------------------

class ColorLine: public Line{
protected:
	int color;
public:
	ColorLine(): Line() { //����������� ��� ���������
		printf("ColorLine()\n");
		color = 0;
	}
	ColorLine(int color, int lenght): Line(lenght) { //����������� � ����������
		printf("ColorLine(int lenght)\n");
		this->color = color;
	}
	ColorLine(const ColorLine& l)  { //����������� �����������
		printf("ColorLine(const ColorLine &l)\n");
		lenght = l.lenght; 
		color = l.color;
	}
	~ColorLine() { //����������
		printf("color= %d, lenght= %d\n", color, lenght);
		printf("~ColorLine()\n");
	}
	void ChangePos(int dcolor) {
		color = color + dcolor; //���������� ������ ����� � �����������
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
	Square() { //����������� ��� ���������
		printf("Square()\n");
		l1 = new Line;
		l2 = new Line;
		l3 = new Line;
		l4 = new Line;
	}
	Square(int lenght) { //����������� � ����������
		printf("Square(int lenght)\n");
		this->l1 = l1;
		this->l2 = l2;
		this->l3 = l3;
		this->l4 = l4;
	}
	Square(const Square& s) { //����������� �����������
		printf("Square(const Square &l)\n");
		l1 = new Line(*(s.l1));
		l2 = new Line(*(s.l2));
		l3 = new Line(*(s.l3));
		l4 = new Line(*(s.l4));
	}
	~Square() { //����������
		//printf("%d\n", lenght);
		delete l1;
		delete l2;
		delete l3;
		delete l4;
		printf("~Square()\n");
	}
};



int main() {
	
	//���������� �������
	//Square* s1 = new Square; //�������� ������ ������� �� �������� ������ �����
	//Square* s2 = new Square(*s1); //�������� ������ ������� �� �������� ������ �����  
	//							  //��� ������ ������������ ����������� ������ �������
	//delete s1;
	//delete s2;

	//----------------------------------------------------------------------------------------
	
	//Line* l = new ColorLine(3, 10); //��������� ������� ������� � ��������� �� ������� �����
	//ColorLine *l2 = new ColorLine(3, 10); //��������� ������� ������ ColorLine � ���������� ������ ������
	//
	//delete l;
	//delete l2;

	//----------------------------------------------------------------------------------------

	//�������� ������� ������ ���������� � �������� ������ � ��� ������������� � ������������ 
	ColorLine* l = new ColorLine();//������������ �������� ������ ����������
	ColorLine* l2 = new ColorLine(3, 10);
	ColorLine* l3 = new ColorLine(*l2);

	l->increase(5);
	l2->increase(10);
	l3->increase(2);


	delete l;
	delete l2;
	delete l3;
	
//-------------------------------------------------------------------------------------------
	
	//������������� ������ ��� ���������� ��������� ����������� ��������� ��������
	//printf("Dynamic create\n");
	//Line* l = new Line();
	//Line* l2 = new Line(10);
	//Line* l3 = new Line(*l2);

	//l->increase(10);//����� increase ������������� �������� lenght ��������
	//l2->increase(5);
	//l3->increase(2);

	////l->decrease();//����� decrease ����������� �������� lenght ��������
	////l2->decrease();
	////l3->decrease();
	
	//printf("Dynamic delete\n");
	//delete l;
	//delete l2;
	//delete l3;

//-------------------------------------------------------------------------------------------
	
	////����������� �������� �������� ������
	//Line l; //��� ����������
	//Line l2(10); //� ����������
	//Line l3(l2); //� ���������� ������� ������� ������
	//
	//l.increase(5);
	//l2.increase(2);
	//l3.increase(3);

//-----------------------------------------------------------------------
	
	////������������ �������� �������� ������
	//Line* l = new Line(); //��� ��������� 
	//Line* l2 = new Line(10); //� ����������
	//Line* l3 = new Line(*l2); //� ���������� ������� ������� ������ 

	////�������� ����������� ��������� ��������
	//delete l; 
	//delete l2;
	//delete l3;

//-------------------------------------------------------------------------------------------
	return 0;
}