/***************************************************************/
/*             HW#8 : friend�� ������ �ߺ�                     */
/*  �ۼ��� : ������                    ��¥ : 2023�� 5�� 24��  */
/*                                                             */
/* ���� ���� :  ������ �Լ��� Book Ŭ���� ��� �Լ��� ����     */
/*               == ������ �Լ��� ����                         */
/***************************************************************/
#include<iostream>
#include <string>
using namespace std;

class Book {
    string title; // ���� ���ڿ� ���� ����
    int price; // ������ ���� ����
    int pages; // ������ ���� ����
public:
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title; this->price = price; this->pages = pages;
        // ����ü ������ �⺻ ������ �����ϰ� this �����ͷ� �Է� ���� ���� ����
    }
    void show() { // å�� ����, ����, ������ ���
        cout << title << ' ' << price << "��" << pages << " ������" << endl;
    }
    string getTitle() { // å�� ���� ��ȯ�ϴ� �Լ�
        return title; 
    }
    bool operator==(int price); // ���� �� �ϴ� �Լ�
    bool operator==(string title); // ���� ���ϴ� �Լ�
    bool operator==(Book op); // ����ü ������ ���ϴ� �Լ�
};
bool Book::operator==(int price) {
    if (this->price == price)  // �Է� ���� price�� price�� ������
        return true; // true ��ȯ
    else 
        return false; // false ��ȯ
}
bool Book::operator==(string title) { 
    if (this->title == title)  // �Է� ���� title�� title�� ������
        return true; // true ��ȯ
    else 
        return false; // false ��ȯ
}
bool Book::operator==(Book op) {
    if (this->price == op.price && this->title == op.title && this->pages == op.pages) 
        // �Է¹��� price, title, pages ���� price, title, pages�� ������
        return true; // ture ��ȯ
    else 
        return false; // false ��ȯ
}
int main() {
    Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500); //  Book Ŭ���� a,b ����
    if (a == 30000) cout << "���� 30000��" << endl; // price �� // a�� 30000�̸� ���
    if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl; // å title ��
    if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl; // title, price, pages ��� ��, ���ٸ� ���
}