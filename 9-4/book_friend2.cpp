/***************************************************************/
/*             HW#8 : friend와 연산자 중복                     */
/*  작성자 : 김태형                    날짜 : 2023년 5월 24일  */
/*                                                             */
/* 문제 정의 :  연산자 함수를 Book 클래스 멤버 함수로 구현     */
/*               == 연산자 함수를 friend 함수로 작성           */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // 제목 문자열 변수 선언
    int price; // 가격 정수 변수 선언
    int pages; // 페이지 정수 변수 선언
public:
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title; this->price = price; this->pages = pages;
        // 구조체 변수를 기본 값으로 설정하고 this 포인터로 입력받은 값을 대입
    }
    void show() { // 제목, 가격, 페이지를 출력하는 함수
        cout << title << ' ' << price << "원" << pages << " 페이지" << endl;
    }
    string getTitle() { // 책 제목을 반환하는 함수
        return title;
    }
    friend bool operator==(Book op1, int price); // 가격 비교하는 함수
    friend bool operator==(Book op1, string title); // 제목 비교하는 함수
    friend bool operator==(Book op1, Book op2); // 구조체 변수를 비교하는 함수
};
bool operator==(Book op1, int price) {
    if (op1.price == price) // 구조체 변수 price가 price랑 같으면
        return true; // true 리턴
    else
        return false; // false 리턴
}
bool operator==(Book op1, string title) {
    if (op1.title == title) // 구조체 변수 title이 title과 같으면
        return true; // true 리턴
    else
        return false; // false 리턴
}
bool operator==(Book op1, Book op2) {
    if (op1.price == op2.price && op1.title == op2.title && op1.pages == op2.pages)
        // 구조체 변수를 비교해서 전부 같으면
        return true; // true 리턴
    else
        return false; // false 리턴
}
int main() {
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500); // Book 클래스 객체 a,b 생성
    if (a == 30000) cout << "정가 30000원" << endl; // price 비교
    if (a == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교
    if (a == b)cout << "두 책이 같은 책입니다." << endl; // title, price, pages 모두 비교
}