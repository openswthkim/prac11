/***************************************************************/
/*             HW#8 : friend와 연산자 중복                     */
/*  작성자 : 김태형                    날짜 : 2023년 5월 24일  */
/*                                                             */
/* 문제 정의 :  연산자 함수를 Book 클래스 멤버 함수로 구현     */
/*               == 연산자 함수를 가짐                         */
/***************************************************************/
#include<iostream>
#include <string>
using namespace std;

class Book {
    string title; // 제목 문자열 변수 선언
    int price; // 정수형 변수 선언
    int pages; // 정수형 변수 선언
public:
    Book(string title = "", int price = 0, int pages = 0) {
        this->title = title; this->price = price; this->pages = pages;
        // 구조체 변수를 기본 값으로 설정하고 this 포인터로 입력 받은 값을 대입
    }
    void show() { // 책의 제목, 가격, 페이지 출력
        cout << title << ' ' << price << "원" << pages << " 페이지" << endl;
    }
    string getTitle() { // 책의 제목 반환하는 함수
        return title; 
    }
    bool operator==(int price); // 가격 비교 하는 함수
    bool operator==(string title); // 제목 비교하는 함수
    bool operator==(Book op); // 구조체 변수를 비교하는 함수
};
bool Book::operator==(int price) {
    if (this->price == price)  // 입력 받은 price가 price와 같으면
        return true; // true 반환
    else 
        return false; // false 반환
}
bool Book::operator==(string title) { 
    if (this->title == title)  // 입력 받은 title이 title과 같으면
        return true; // true 반환
    else 
        return false; // false 반환
}
bool Book::operator==(Book op) {
    if (this->price == op.price && this->title == op.title && this->pages == op.pages) 
        // 입력받은 price, title, pages 값이 price, title, pages와 같으면
        return true; // ture 반환
    else 
        return false; // false 반환
}
int main() {
    Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500); //  Book 클래스 a,b 생성
    if (a == 30000) cout << "정가 30000원" << endl; // price 비교 // a가 30000이면 출력
    if (a == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교
    if (a == b) cout << "두 책이 같은 책입니다." << endl; // title, price, pages 모두 비교, 같다면 출력
}