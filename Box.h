#include <string>
#include <iostream>

using namespace std;

class Box
{
private:
	string car_number;
	string car_brand;
	Box* next;
	Box* prev;

public:
	//конструктор
	Box() {
		car_number = "";
		car_brand = "";
		next = nullptr;
		prev = nullptr;
	}
	//геттеры и сеттеры
	string get_car_number()	{ return car_number; }

	void set_car_number(string _car_number) { car_number = _car_number; }

	string get_car_brand() { return car_brand; }

	void set_car_brand(string _car_brand) {	car_brand = _car_brand;}

	Box* get_next() { return next; }

	void set_next(Box* _next) { next = _next; }

	Box* get_prev() { return prev; }

	void set_prev(Box* _prev) { prev = _prev; }
};