/***************************************************************/
/*             HW#8 : friend�� ������ �ߺ�                     */
/*  �ۼ��� : ������                    ��¥ : 2023�� 5�� 24��  */
/*                                                             */
/* ���� ���� :  ������ �Լ��� Book Ŭ���� ��� �Լ��� ����     */
/*                - - - - - - -                                */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Book { 
	string title; // ���ڿ� ���� ����
	int price; // ������ ����
	int pages; // ������ ����

public:
	Book(string title = "", int price = 0, int pages = 0) { // Book Ŭ���� ���� �ʱ�ȭ
		this->title = title; this->price = price; this->pages = pages; // this �����ͷ� ����, ����, �������� ����Ŵ
	}

	void show() { // å�� ����, ����, ������ ���
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}

	string getTitle() { // å�� ���� ��ȯ�ϴ� �Լ�
		return title;
	}
	Book& operator+=(int price); // ������ ������ ����
	Book& operator-=(int price); // ������ ������ ��
};
Book& Book::operator+=(int price) {
	this->price += price; // ������ price�� price�� ����
	return *this; // ���� ��ü
}
Book& Book::operator-=(int price) {
	this->price -= price; // ������ price�� price�� ��
	return *this; // ���� ��ü
}
int main() {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500; // å a�� ���� 500�� ����
	b -= 500; // å b�� ���� 500�� ����
	a.show(); // å a�� ���� ���
	b.show(); // å b�� ���� ���
}