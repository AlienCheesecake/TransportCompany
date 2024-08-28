#include "Garage.h"
#include <fstream>


const int n = 10;

class Transport_company
{
private:
	string name;
	Garage garage[n];
	int top;

public:
	//конструкторы
	Transport_company()
	{
		name = "";
		top = -1;
	}

	Transport_company(string _name)
	{
		name = _name;
		top = -1;
	}
	//геттеры и сеттеры
	void set_name(string _name) { name = _name;	}

	string get_name() { return name; }

	Garage get_top()
	{
		if(!empty())
		{
			return garage[top];
		}
	}
	//проверка стека на пустоту
	bool empty() { return (top == -1); }
	//проверка стека на заполненность
	bool full() { return (top == n-1); }
	//добавление элемента на вершину стека
	void push(int _number)
	{
		if (!full())
		{
			top++;
			garage[top].set_number(_number);
		}
		else
		{
			cout << "Гараж не добавлен, компания заполнена" << endl;
		}
	}
	//удаление элемента с вершины стека
	void pop()
	{
		if (!empty())
		{
			garage[top].pop_all();
			garage[top].set_number(-1);
			top--;
		}
		else
		{
			cout << "стек пуст!" << endl;
		}
	}
	//очистка стека
	void pop_all()
	{
		if (!empty())
		{
			while (top != -1)
			{
				garage[top].pop_all();
				garage[top].set_number(-1);
				top--;
			}
		}
		else
		{
			cout << "стек пуст!" << endl;
		}
	}
	//вывод стека на экран
	void status()
	{
		cout << "Название компании " << name << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << "Номер гаража " << garage[i].get_number() << endl;
			garage[i].status_next();
		}
		cout << endl;
	}
	//функция сохранения в файл
	void save_in_file(string file_name)
	{
		ofstream fout;
		fout.open(file_name+".txt");

		if (!fout.is_open())
		{
			cout<<"Ошибка открытия файла" << endl;
		}
		else
		{
			fout << "Компания" << endl;
			fout << name << endl;
			if(!empty())
			{
				for (int i = 0; i <= top; i++)
				{
					fout << "Гараж" << endl;
					fout << garage[i].get_number() << endl;
					if(!garage[i].empty())
					{
						fout << "Боксы" << endl;
						Box* current = garage[i].get_head()->get_next();
						while (current != garage[i].get_head())
						{
							fout << current->get_car_number() << " " << current->get_car_brand() << endl;

							current = current->get_next();
						}
					}
				}
			}
		}
		fout.close();
	}
	//функция чтения из файла
	void input_from_file(string file_name)
	{
		string brand, number_after, brand_after;
		string input = "";
		ifstream fin;
		fin.open(file_name + ".txt");

		if (!fin.is_open())
		{
			cout << "Ошибка открытия файла" << endl;
		}
		else
		{
			while(!fin.eof())
			{
				if (input == "Компания")
				{
					fin >> input;
					name = input;
				}
				if (input == "Гараж")
				{
					if (top == n-1)
					{
						return;
					}
					fin >> input;
					push(stoi(input));
				}
				if (input == "Боксы")
				{
					fin >> input;
					fin >> brand;
					garage[top].push_empty(input, brand);
					number_after = input;
					brand_after = brand;
					while (!fin.eof())
					{
						fin >> input;
						if (input == "Гараж")
						{
							break;
						}
						fin >> brand;
						garage[top].push_after(input, brand, number_after, brand_after);
						number_after = input;
						brand_after = brand;
					}
				}
				if(!fin.eof() && input!= "Гараж")
				{
					fin >> input;
				}
			}
			garage[top].pop(input, brand);
		}
	}
	//функции реализующие работу с структурой Garage
	void garage_push_empty(string _car_number, string _car_brand)
	{
		garage[top].push_empty(_car_number, _car_brand);
	}
	void garage_push_after(string _car_number, string _car_brand, string after_number, string after_brand)
	{
		garage[top].push_after(_car_number, _car_brand, after_number, after_brand);
	}
	void garage_push_before(string _car_number, string _car_brand, string before_number, string before_brand)
	{
		garage[top].push_before(_car_number, _car_brand, before_number, before_brand);
	}
	void garage_pop(string _car_number, string _car_brand)
	{
		garage[top].pop(_car_number, _car_brand);
	}
	void garage_status_next()
	{
		garage[top].status_next();
	}
	void garage_status_prev()
	{
		garage[top].status_prev();
	}
	bool garage_empty()
	{
		return garage[top].empty();
	}
	bool garage_check(string _car_number, string _car_brand)
	{
		return garage[top].check(_car_number, _car_brand);
	}
	void garage_pop_all()
	{
		garage[top].pop_all();
	}
	//деструктор
	~Transport_company()
	{
		pop_all();
		name = "";
		top = -1;
	}
};