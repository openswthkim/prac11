/***************************************************************/
/*             HW#8 : friend�� ������ �ߺ�                     */
/*  �ۼ��� : ������                    ��¥ : 2023�� 5�� 24��  */
/*                                                             */
/* ���� ���� :  ������ �Լ��� Book Ŭ���� ��� �Լ��� ����     */
/*               == ������ �Լ��� friend �Լ��� �ۼ�           */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // ���� ���ڿ� ���� ����
    int price; // ���� ���� ���� ����
    int pages; // ������ ���� ���� ����
public:
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title; this->price = price; this->pages = pages;
        // ����ü ������ �⺻ ������ �����ϰ� this �����ͷ� �Է¹��� ���� ����
    }
    void show() { // ����, ����, �������� ����ϴ� �Լ�
        cout << title << ' ' << price << "��" << pages << " ������" << endl;
    }
    string getTitle() { // å ������ ��ȯ�ϴ� �Լ�
        return title;
    }
    friend bool operator==(Book op1, int price); // ���� ���ϴ� �Լ�
    friend bool operator==(Book op1, string title); // ���� ���ϴ� �Լ�
    friend bool operator==(Book op1, Book op2); // ����ü ������ ���ϴ� �Լ�
};
bool operator==(Book op1, int price) {
    if (op1.price == price) // ����ü ���� price�� price�� ������
        return true; // true ����
    else
        return false; // false ����
}
bool operator==(Book op1, string title) {
    if (op1.title == title) // ����ü ���� title�� title�� ������
        return true; // true ����
    else
        return false; // false ����
}
bool operator==(Book op1, Book op2) {
    if (op1.price == op2.price && op1.title == op2.title && op1.pages == op2.pages)
        // ����ü ������ ���ؼ� ���� ������
        return true; // true ����
    else
        return false; // false ����
}
int main() {
    Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500); // Book Ŭ���� ��ü a,b ����
    if (a == 30000) cout << "���� 30000��" << endl; // price ��
    if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl; // å title ��
    if (a == b)cout << "�� å�� ���� å�Դϴ�." << endl; // title, price, pages ��� ��
}