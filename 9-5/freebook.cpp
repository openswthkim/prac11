/***************************************************************/
/*             HW#8 : friend와 연산자 중복                     */
/*  작성자 : 김태형                    날짜 : 2023년 5월 24일  */
/*                                                             */
/* 문제 정의 :  연산자 함수를 Book 클래스 멤버 함수로 구현     */
/*              !연산자를 작성해 공짜 책인지를 판별            */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Book {
    string title; // 제목 문자열 변수 선언
    int price, pages; // 가격, 페이지 변수 선언
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
    bool operator!(); // 가격이 0인지 확인하는 함수 선언
};
bool Book::operator!() {
    if (this->price == 0) // 가격이 0이면
        return true; // true 반환
    else
        return false; // 아니면 false 반환
}
int main() {
    Book book("벼룩시장", 0, 50); // 가격은 0
    if (!book) cout << "공짜다" << endl; // book 객체의 가격이 0이면 출력
}