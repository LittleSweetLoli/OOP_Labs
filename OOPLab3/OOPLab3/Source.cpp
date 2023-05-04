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
	int razmer; //������ ����������
public:
	Container() { //����������� ��� ���������
		razmer = 0;
		values = new T[razmer];
	}
	Container(int razmer) { //����������� � ���������� 
		this->razmer = razmer;
		values = new T[razmer]; // �������� ������������� ������� ���� ��������� �������
		cout << "Write " << razmer << " values:" << endl;
		for (int i = 0; i < razmer; i++) {
			T temp;
			cin >> temp;
			values[i] = temp;
		}
	}
	Container(const Container& a) { //����������� �����������
		razmer = a.razmer();
		values = new T[razmer];
		for (int i = 0; i < razmer; i++) {
			values[i] = a.values[i];
		}
	}
	~Container() { //����������
		delete[] values;
	}



	void resize(int N) { //����� ���������� ������ ������� �� �������� 
		T* temp = values;
		values = new T[N];
		for (int i = 0; i < N && i < razmer; i++) {
			values[i] = temp[i];
		}
		razmer = N;
		delete[] temp;
	}

	void addstart(const T& el) { //����� ���������� �������� � ������ �������
		T* temp = values;	   
		razmer += 1;		   //������ ������������� �� 1
		values = new T[razmer];
		values[0] = el;        //�������� ������� �������� �� 0-� �������
		for (int i = 1; i < razmer; i++) { //����� ������ ����������� 
			values[i] = temp[i - 1]; //
		}
		delete[] temp;		   //������ ���������� ��� ��������������� ������ ���������

	}
	void addend(const T& el) { //����� ���������� �������� � ����� �������
		resize(razmer + 1);		//������������� ������ �� 1
		values[razmer - 1] = el;//������� ����������� �� ��������� ����� � ����� �������
	}
	void addinindex(int index, const T& el) { //����� ���������� �������� �� �������. ������ ��������, ��� �������
		if (index > razmer) addend(el); //���� ������ ����������� �� ����� ������� ������ ������� ������� �� ������������ ����� addend
		else if (index < 0) addstart(el);//���� ������ �� ������������ ����� addstart
		else {
			T* temp = values;
			razmer += 1;
			values = new T[razmer];
			for (int i = 0; i < index; i++) { //� ������� ���� ������ �������� ��������� ���-������ � �������� ������� �� ������� ������ 
				values[i] = temp[i];		  //����������� �� ��������� �������
			}								  
			values[index] = el;

			for (int i = index + 1; i < razmer; i++) {//����� ����������� ���������� ����� �������
				values[i] = temp[i - 1];
			}
			delete[] temp; //��������� ������ ���������� ��� ��������������� ������
		}

	}

	T& showel(int index) { //����� ��������� �������� �� ���������� ������� 
		return values[index];
	}

	int getsize() { //����� ��������� ������� ������� 
		return razmer;
	}
	
	void vyvod () {
		cout << "Container: ";
		for (int i = 0; i < razmer; i++) {
			cout << values[i] << " ";
		}
		cout << endl;
	}

	void removeinindex(int index) { //����� �������� �������� �� ������� 
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

void tester(int N) { //������� ������������ �������� ���������� � ���������� ���� �������

	srand(time(NULL));
	Container <int> chisla; //��������� ������ ������ Container

	int counter = 0; 

	double time_spent = 0.0;
	clock_t begin = clock(); //������ ������� �������

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
	clock_t end = clock(); //����� ������� �������
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
