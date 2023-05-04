#include <iostream>
#include <assert.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <chrono>
using namespace std;

template <typename T>
class Container {
private:
	T* values;
	int razmer; //размер контейнера
public:
	Container() { //конструктор без параметра
		razmer = 0;
		values = new T[razmer];
	}
	Container(int razmer) { //конструктор с параметром 
		this->razmer = razmer;
		values = new T[razmer]; // создание динамического массива типа шаблонной функции
		cout << "Write " << razmer << " values:" << endl;
		for (int i = 0; i < razmer; i++) {
			T temp;
			cin >> temp;
			values[i] = temp;
		}
	}
	Container(const Container& a) { //конструктор копирования
		razmer = a.razmer();
		values = new T[razmer];
		for (int i = 0; i < razmer; i++) {
			values[i] = a.values[i];
		}
	}
	~Container() { //деструктор
		delete[] values;
	}



	void resize(int N) { //метод изменяющий размер массива на заданный 
		T* temp = values;
		values = new T[N];
		for (int i = 0; i < N && i < razmer; i++) {
			values[i] = temp[i];
		}
		razmer = N;
		delete[] temp;
	}

	void addstart(const T& el) { //метод добавления элемента в начало массива
		T* temp = values;	   
		razmer += 1;		   //размер увеличивается на 1
		values = new T[razmer];
		values[0] = el;        //заданный элемент ставится на 0-ю позицию
		for (int i = 1; i < razmer; i++) { //затем массив заполняется 
			values[i] = temp[i - 1]; //
		}
		delete[] temp;		   //память выделенная под вспомогательный массив очищается

	}
	void addend(const T& el) { //метод добавления элемента в конец массива
		resize(razmer + 1);		//увеличивается размер на 1
		values[razmer - 1] = el;//элемент добавляется на созданное место в конец массива
	}
	void addinindex(int index, const T& el) { //метод добавления элемента по индексу. индекс элемента, сам элемент
		if (index > razmer) addend(el); //если индекс добавляется на место которое больше размера массива то используется метод addend
		else if (index < 0) addstart(el);//если меньше то используется метод addstart
		else {
			T* temp = values;
			razmer += 1;
			values = new T[razmer];
			for (int i = 0; i < index; i++) { //в случаях если индекс элемента находится где-нибудь в середине массива то сначала массив 
				values[i] = temp[i];		  //заполняется до заданного индекса
			}								  
			values[index] = el;

			for (int i = index + 1; i < razmer; i++) {//затем заполняется оставшаяся часть массива
				values[i] = temp[i - 1];
			}
			delete[] temp; //очищается память выделенная под вспомогательный массив
		}

	}

	T& showel(int index) { //метод получения значения по указанному индексу 
		return values[index];
	}

	int getsize() { //метод получения размера массива 
		return razmer;
	}
	
	void vyvod () {
		cout << "Container: ";
		for (int i = 0; i < razmer; i++) {
			cout << values[i] << " ";
		}
		cout << endl;
	}

	void removeinindex(int index) { //метод удаления элемента по индексу 
		if (razmer == 0) {
			razmer = 0;
		}
		else if (index <= 0 && razmer == 0) {
			index = 0;
		}
		else if (index < 0) {
			removeinindex(0);
		}
		else if (index >= razmer) {
			removeinindex(razmer - 1);
		}

		else {
			T* temp = values;
			razmer -= 1;
			values = new T[razmer];
			for (int i = 0; i < index; i++) {
				values[i] = temp[i];
			}
			for (int i = index; i < razmer; i++) {
				values[i] = temp[i + 1];
			}
			delete[] temp;
		}
	}
};

void tester(int N) { //функция тестирования скорости вычислений и выполнения всех функций

	srand(time(NULL));
	Container <int> chisla; //создается объект класса Container

	int counter = 0; 

	double time_spent = 0.0;
	clock_t begin = clock(); //начало отсчета времени

	while (counter != N) {
		int temp = rand() % 4; 
		if (temp == 0) {
			chisla.addend(rand());
		}
		else if (temp == 1) {
			chisla.addstart(rand());
		}
		else if (temp == 2) {
			chisla.addinindex(rand() % (chisla.getsize() + 1), rand());
		}
		else if (temp == 3) {
			chisla.removeinindex(rand() % (chisla.getsize() + 1));
		}
		counter++;
	}
	//int sz = chisla.getsize();
	clock_t end = clock(); //конец отсчета времени
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	


	printf("The time was spent is %f seconds in %d iterations\n", time_spent, N);
	
	printf("the size of a massive %d\n", chisla.getsize());

	printf("\n");
}

int main() {
	tester(100);
	
	tester(1000);
	tester(10000);

}
