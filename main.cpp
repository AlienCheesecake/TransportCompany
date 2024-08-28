//11. Статический стек двунаправленных неупорядоченных списков
//13. Транспортная компания (название) - композиция гаражей (номер), гараж - композиция боксов (номер, марка машины)

#include "Transport_company.h"
#include <string>
#include <iostream>
#include<windows.h>

using namespace std;

bool namecheck(string a)
{
	if (a == "")
	{
		return false;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			return false;
		}
	}
	return true;
}

bool intcheck(string a)
{
	if (a == "")
	{
		return false;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if (!isdigit(a[i]))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);


	bool exit = true;

	string menu, name_company, number_garage, file_name, sub_menu, car_number, car_brand, ab_car_number, ab_car_brand, b;

	Transport_company company{ "Имя_по_умолчанию" };

	do
	{
		cout << "Выберите, что сделать с транспортной компанией:" << endl;
		cout << "1)Дать имя компании" << endl;
		cout << "2)Добавить гараж" << endl;
		cout << "3)Удалить гараж" << endl;
		cout << "4)Вывести состояние всей компании" << endl;
		cout << "5)Проверить на пустоту" << endl;
		cout << "6)Проверить на заполненность" << endl;
		cout << "7)Редактировать текущий гараж" << endl;
		cout << "8)Сохранить в файл" << endl;
		cout << "9)Считать из файла" << endl;
		cout << "10)Очистить компанию" << endl;
		cout << "11)Выйти" << endl;

		do
		{
			cout << "Введите пункт меню: ";
			getline(cin, menu);
		} while (!intcheck(menu));

		switch (stoi(menu))
		{
		case 1:
		{
			cout << endl;
			cout << "Введите имя компании: ";
			getline(cin, name_company);
			if (!namecheck(name_company))
			{
				cout << "Ошибка! Имя не должно содержать пробелов"<<endl;
			}
			else
			{
				company.set_name(name_company);
			}
			cout << endl;
			break;
		}
		case 2:
		{
			cout << endl;
			if(!company.full())
			{
				cout << "Введите номер гаража: ";
				getline(cin, number_garage);
				if (!intcheck(number_garage))
				{
					cout << "Ошибка! Номер гаража должен быть целым положительным числом" << endl;
				}
				else
				{
					company.push(stoi(number_garage));
					cout << "Гараж добавлен и теперь является текущим" << endl;
				}
			}
			else
			{
				cout << "Гараж не добавлен, компания заполнена" << endl;
			}
			cout << endl;
			break;
		}
		case 3:
		{
			cout << endl;
			if(!company.empty())
			{
				company.pop();
				cout << "Текущий гараж успешно удален" << endl;
			}
			else
			{
				cout << "Компания пуста" << endl;
			}
			cout << endl;
			break;
		}
		case 4:
		{
			cout << endl;
			company.status();
			cout << endl;
			break;
		}
		case 5:
		{
			cout << endl;
			if (company.empty())
			{
				cout << "Компания пуста" << endl;
			}
			else
			{
				cout << "Компания не пуста" << endl;
			}
			cout << endl;
			break;
		}
		case 6:
		{
			cout << endl;
			if (company.full())
			{
				cout << "Компания заполнена" << endl;
			}
			else
			{
				cout << "Компания не заполнена" << endl;
			}
			cout << endl;
			break;
		}
		case 7:
		{
			cout << endl;
			if(!company.empty())
			{
				do
				{
					cout << "Выберите, что сделать с гаражом:" << endl;
					cout << "1)Добавить бокс после заданного" << endl;
					cout << "2)Добавить бокс до заданного" << endl;
					cout << "3)Вывести состояние гаража" << endl;
					cout << "4)Удалить бокс" << endl;
					cout << "5)Проверить гараж на пустоту" << endl;
					cout << "6)Удалить все боксы" << endl;
					cout << "7)Вернуться" << endl;
					cout << endl;

					do
					{
						cout << "Введите пункт меню: ";
						getline(cin, sub_menu);
					} while (!intcheck(sub_menu));

					switch (stoi(sub_menu))
					{
					case 1:
					{
						cout << endl;
						if (company.garage_empty())
						{
							cout << "Какой номер машины у добавляемого бокса: " << endl;
							getline(cin, car_number);
							if (!namecheck(car_number))
							{
								cout << "Ошибка! Номер машины не должен содержать пробелы" << endl;
							}
							else
							{
								cout << "Какое название марки машины у добавляемого бокса: " << endl;
								getline(cin, car_brand);
								if (!namecheck(car_brand))
								{
									cout << "Ошибка! Номер марка машины не должна содержать пробелы" << endl;
								}
								else
								{
									company.garage_push_empty(car_number, car_brand);
								}
							}
						}
						else
						{
							cout << "Какой номер машины, после которой добавить элемент:" << endl;
							getline(cin, ab_car_number);
							cout << "Какая марка машины, после которой добавить элемент:" << endl;
							getline(cin, ab_car_brand);
							if (!company.garage_check(ab_car_number, ab_car_brand))
							{
								cout << "Данного элемента нет в списке" << endl;
							}
							else
							{
								cout << "Какой номер машины у добавляемого бокса: " << endl;
								getline(cin, car_number);
								if (!namecheck(car_number))
								{
									cout << "Ошибка! Номер машины не должен содержать пробелы" << endl;
								}
								else
								{
									cout << "Какое название марки машины у добавляемого бокса: " << endl;
									getline(cin, car_brand);
									if (!namecheck(car_brand))
									{
										cout << "Ошибка! Номер марка машины не должна содержать пробелы" << endl;
									}
									else
									{
										company.garage_push_after(car_number, car_brand, ab_car_number, ab_car_brand);
									}
								}
							}
						}
						cout << endl;
						break;
					}
					case 2:
					{
						cout << endl;

						if (company.garage_empty())
						{
							cout << "Какой номер машины у добавляемого бокса: " << endl;
							getline(cin, car_number);
							if (!namecheck(car_number))
							{
								cout << "Ошибка! Номер машины не должен содержать пробелы" << endl;
							}
							else
							{
								cout << "Какое название марки машины у добавляемого бокса: " << endl;
								getline(cin, car_brand);
								if (!namecheck(car_brand))
								{
									cout << "Ошибка! Номер марка машины не должна содержать пробелы" << endl;
								}
								else
								{
									company.garage_push_empty(car_number, car_brand);
								}
							}
						}
						else
						{
							cout << "Какой номер машины бокса, до которой добавить элемент:" << endl;
							getline(cin, ab_car_number);
							cout << "Какая марка машины бокса, до которой добавить элемент:" << endl;
							getline(cin, ab_car_brand);
							if (!company.garage_check(ab_car_number, ab_car_brand))
							{
								cout << "Данного бокса нет в гараже" << endl;
							}
							else
							{
								cout << "Какой номер машины у добавляемого бокса: " << endl;
								getline(cin, car_number);
								if (!namecheck(car_number))
								{
									cout << "Ошибка! Номер машины не должен содержать пробелы" << endl;
								}
								else
								{
									cout << "Какое название марки машины у добавляемого бокса: " << endl;
									getline(cin, car_brand);
									if (!namecheck(car_brand))
									{
										cout << "Ошибка! Номер марка машины не должна содержать пробелы" << endl;
									}
									else
									{
										company.garage_push_before(car_number, car_brand, ab_car_number, ab_car_brand);
									}
								}
							}
						}
						cout << endl;
						break;
					}
					case 3:
					{
						cout << endl;

						if (company.garage_empty())
						{
							cout << "Гараж пуст" << endl;
						}
						else
						{
							do
							{
								cout << "В каком порядке вывести список?" << endl;
								cout << "1)В прямом" << endl;
								cout << "2)В обратном" << endl;
								getline(cin, b);
							} while (!intcheck(b));

							cout << endl;

							if (b == "1")
							{
								company.garage_status_next();
							}
							else if (b == "2")
							{
								company.garage_status_prev();
							}
						}
						cout << endl;
						break;
					}
					case 4:
					{
						cout << "" << endl;

						if (company.garage_empty())
						{
							cout << "Нельзя удалить элемент, гараж пуст" << endl;
						}
						else
						{
							cout << "Какой номер машины бокса, который надо удалить:" << endl;
							getline(cin, car_number);
							cout << "Какая марка машины бокса, который надо удалить:" << endl;
							getline(cin, car_brand);
							if (!company.garage_check(car_number, car_brand))
							{
								cout << "Данного бокса нет в гареже" << endl;
							}
							else
							{
								company.garage_pop(car_number, car_brand);
								cout << "Бокс удален" << endl;
							}
						}

						cout << endl;
						break;
					}
					case 5:
					{
						cout << "" << endl;
						if (company.garage_empty())
						{
							cout << "Гараж пуст" << endl;
						}
						else
						{
							cout << "Гараж не пуст" << endl;
						}
						cout << "" << endl;
						break;
					}
					case 6:
					{
						cout << "" << endl;
						if (company.garage_empty())
						{
							cout << "Список пуст" << endl;
						}
						else
						{
							company.garage_pop_all();
							cout << "Все боксы удалены" << endl;
						}
						cout << "" << endl;
						break;
					}
					case 7:
					{
						sub_menu = "back";
						cout << "" << endl;
						break;
					}
					default:
					{
						cout << endl;
						cout << "Этого пункта нет в меню" << endl;
						cout << endl;
						break;
					}
					}

				} while (sub_menu != "back");
			}
			else
			{
				cout << "Компания пуста" << endl;
			}
			cout << endl;
			break;
		}
		case 8:
		{
			cout << endl;
			cout << "Введите имя файла для сохранения(без формата): ";
			getline(cin, file_name);
			company.save_in_file(file_name);
			cout << endl;
			break;
		}
		case 9:
		{
			cout << endl;
			cout << "Введите имя файла для считывния(без формата): ";
			getline(cin, file_name);
			company.input_from_file(file_name);
			cout << endl;
			break;
		}
		case 10:
		{
			cout << endl;
			company.pop_all();
			company.set_name("Имя_по_умолчанию");
			cout << endl;
			break;
		}
		case 11:
		{
			company.pop_all();
			exit = false;
			break;
		}
		default:
		{
			cout << endl;
			cout << "Этого пункта нет в меню" << endl;
			cout << endl;
			break;
		}
		}

	}while (exit);
}