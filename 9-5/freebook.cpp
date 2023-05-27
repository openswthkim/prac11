/***************************************************************/
/*             HW#8 : friend�� ������ �ߺ�                     */
/*  �ۼ��� : ������                    ��¥ : 2023�� 5�� 24��  */
/*                                                             */
/* ���� ���� :  ������ �Լ��� Book Ŭ���� ��� �Լ��� ����     */
/*              !�����ڸ� �ۼ��� ��¥ å������ �Ǻ�            */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Book {
    string title; // ���� ���ڿ� ���� ����
    int price, pages; // ����, ������ ���� ����
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
    bool operator!(); // ������ 0���� Ȯ���ϴ� �Լ� ����
};
bool Book::operator!() {
    if (this->price == 0) // ������ 0�̸�
        return true; // true ��ȯ
    else
        return false; // �ƴϸ� false ��ȯ
}
int main() {
    Book book("�������", 0, 50); // ������ 0
    if (!book) cout << "��¥��" << endl; // book ��ü�� ������ 0�̸� ���
}