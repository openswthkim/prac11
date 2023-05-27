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
	string title; // 문자열 변수 선언
	int price; // 정수형 변수
	int pages; // 정수형 변수

public:
	Book(string title = "", int price = 0, int pages = 0) { // Book 클래스 변수 초기화
		this->title = title; this->price = price; this->pages = pages; // this 포인터로 제목, 가격, 페이지를 가리킴
	}

	void show() { // 책의 제목, 가격, 페이지 출력
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}

	string getTitle() { // 책의 제목 반환하는 함수
		return title;
	}
	Book& operator+=(int price); // 지정된 가격을 더함
	Book& operator-=(int price); // 지정된 가격을 뺌
};
Book& Book::operator+=(int price) {
	this->price += price; // 지정된 price를 price에 더함
	return *this; // 현재 객체
}
Book& Book::operator-=(int price) {
	this->price -= price; // 지정된 price를 price에 뺌
	return *this; // 현재 객체
}
int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show(); // 책 a의 정보 출력
	b.show(); // 책 b의 정보 출력
}