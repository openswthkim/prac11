/***************************************************************/
/*             HW#8 : friend와 연산자 중복                     */
/*  작성자 : 김태형                    날짜 : 2023년 5월 24일  */
/*                                                             */
/* 문제 정의 :  연산자 함수를 Book 클래스 멤버 함수로 구현     */
/*                - - - - - - -                                */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() {
		return title;
	}
	friend Book operator+=(Book& fb, int price);
	friend Book operator-=(Book& fb, int price);
};
Book operator+=(Book& fb, int price) {
	fb.price += price;
	return fb;
}
Book operator-=(Book &fb, int price) {
	fb.price -= price;
	return fb;
}
int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();
}