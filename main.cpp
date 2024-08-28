//11. ����������� ���� ��������������� ��������������� �������
//13. ������������ �������� (��������) - ���������� ������� (�����), ����� - ���������� ������ (�����, ����� ������)

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

	Transport_company company{ "���_��_���������" };

	do
	{
		cout << "��������, ��� ������� � ������������ ���������:" << endl;
		cout << "1)���� ��� ��������" << endl;
		cout << "2)�������� �����" << endl;
		cout << "3)������� �����" << endl;
		cout << "4)������� ��������� ���� ��������" << endl;
		cout << "5)��������� �� �������" << endl;
		cout << "6)��������� �� �������������" << endl;
		cout << "7)������������� ������� �����" << endl;
		cout << "8)��������� � ����" << endl;
		cout << "9)������� �� �����" << endl;
		cout << "10)�������� ��������" << endl;
		cout << "11)�����" << endl;

		do
		{
			cout << "������� ����� ����: ";
			getline(cin, menu);
		} while (!intcheck(menu));

		switch (stoi(menu))
		{
		case 1:
		{
			cout << endl;
			cout << "������� ��� ��������: ";
			getline(cin, name_company);
			if (!namecheck(name_company))
			{
				cout << "������! ��� �� ������ ��������� ��������"<<endl;
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
				cout << "������� ����� ������: ";
				getline(cin, number_garage);
				if (!intcheck(number_garage))
				{
					cout << "������! ����� ������ ������ ���� ����� ������������� ������" << endl;
				}
				else
				{
					company.push(stoi(number_garage));
					cout << "����� �������� � ������ �������� �������" << endl;
				}
			}
			else
			{
				cout << "����� �� ��������, �������� ���������" << endl;
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
				cout << "������� ����� ������� ������" << endl;
			}
			else
			{
				cout << "�������� �����" << endl;
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
				cout << "�������� �����" << endl;
			}
			else
			{
				cout << "�������� �� �����" << endl;
			}
			cout << endl;
			break;
		}
		case 6:
		{
			cout << endl;
			if (company.full())
			{
				cout << "�������� ���������" << endl;
			}
			else
			{
				cout << "�������� �� ���������" << endl;
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
					cout << "��������, ��� ������� � �������:" << endl;
					cout << "1)�������� ���� ����� ���������" << endl;
					cout << "2)�������� ���� �� ���������" << endl;
					cout << "3)������� ��������� ������" << endl;
					cout << "4)������� ����" << endl;
					cout << "5)��������� ����� �� �������" << endl;
					cout << "6)������� ��� �����" << endl;
					cout << "7)���������" << endl;
					cout << endl;

					do
					{
						cout << "������� ����� ����: ";
						getline(cin, sub_menu);
					} while (!intcheck(sub_menu));

					switch (stoi(sub_menu))
					{
					case 1:
					{
						cout << endl;
						if (company.garage_empty())
						{
							cout << "����� ����� ������ � ������������ �����: " << endl;
							getline(cin, car_number);
							if (!namecheck(car_number))
							{
								cout << "������! ����� ������ �� ������ ��������� �������" << endl;
							}
							else
							{
								cout << "����� �������� ����� ������ � ������������ �����: " << endl;
								getline(cin, car_brand);
								if (!namecheck(car_brand))
								{
									cout << "������! ����� ����� ������ �� ������ ��������� �������" << endl;
								}
								else
								{
									company.garage_push_empty(car_number, car_brand);
								}
							}
						}
						else
						{
							cout << "����� ����� ������, ����� ������� �������� �������:" << endl;
							getline(cin, ab_car_number);
							cout << "����� ����� ������, ����� ������� �������� �������:" << endl;
							getline(cin, ab_car_brand);
							if (!company.garage_check(ab_car_number, ab_car_brand))
							{
								cout << "������� �������� ��� � ������" << endl;
							}
							else
							{
								cout << "����� ����� ������ � ������������ �����: " << endl;
								getline(cin, car_number);
								if (!namecheck(car_number))
								{
									cout << "������! ����� ������ �� ������ ��������� �������" << endl;
								}
								else
								{
									cout << "����� �������� ����� ������ � ������������ �����: " << endl;
									getline(cin, car_brand);
									if (!namecheck(car_brand))
									{
										cout << "������! ����� ����� ������ �� ������ ��������� �������" << endl;
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
							cout << "����� ����� ������ � ������������ �����: " << endl;
							getline(cin, car_number);
							if (!namecheck(car_number))
							{
								cout << "������! ����� ������ �� ������ ��������� �������" << endl;
							}
							else
							{
								cout << "����� �������� ����� ������ � ������������ �����: " << endl;
								getline(cin, car_brand);
								if (!namecheck(car_brand))
								{
									cout << "������! ����� ����� ������ �� ������ ��������� �������" << endl;
								}
								else
								{
									company.garage_push_empty(car_number, car_brand);
								}
							}
						}
						else
						{
							cout << "����� ����� ������ �����, �� ������� �������� �������:" << endl;
							getline(cin, ab_car_number);
							cout << "����� ����� ������ �����, �� ������� �������� �������:" << endl;
							getline(cin, ab_car_brand);
							if (!company.garage_check(ab_car_number, ab_car_brand))
							{
								cout << "������� ����� ��� � ������" << endl;
							}
							else
							{
								cout << "����� ����� ������ � ������������ �����: " << endl;
								getline(cin, car_number);
								if (!namecheck(car_number))
								{
									cout << "������! ����� ������ �� ������ ��������� �������" << endl;
								}
								else
								{
									cout << "����� �������� ����� ������ � ������������ �����: " << endl;
									getline(cin, car_brand);
									if (!namecheck(car_brand))
									{
										cout << "������! ����� ����� ������ �� ������ ��������� �������" << endl;
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
							cout << "����� ����" << endl;
						}
						else
						{
							do
							{
								cout << "� ����� ������� ������� ������?" << endl;
								cout << "1)� ������" << endl;
								cout << "2)� ��������" << endl;
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
							cout << "������ ������� �������, ����� ����" << endl;
						}
						else
						{
							cout << "����� ����� ������ �����, ������� ���� �������:" << endl;
							getline(cin, car_number);
							cout << "����� ����� ������ �����, ������� ���� �������:" << endl;
							getline(cin, car_brand);
							if (!company.garage_check(car_number, car_brand))
							{
								cout << "������� ����� ��� � ������" << endl;
							}
							else
							{
								company.garage_pop(car_number, car_brand);
								cout << "���� ������" << endl;
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
							cout << "����� ����" << endl;
						}
						else
						{
							cout << "����� �� ����" << endl;
						}
						cout << "" << endl;
						break;
					}
					case 6:
					{
						cout << "" << endl;
						if (company.garage_empty())
						{
							cout << "������ ����" << endl;
						}
						else
						{
							company.garage_pop_all();
							cout << "��� ����� �������" << endl;
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
						cout << "����� ������ ��� � ����" << endl;
						cout << endl;
						break;
					}
					}

				} while (sub_menu != "back");
			}
			else
			{
				cout << "�������� �����" << endl;
			}
			cout << endl;
			break;
		}
		case 8:
		{
			cout << endl;
			cout << "������� ��� ����� ��� ����������(��� �������): ";
			getline(cin, file_name);
			company.save_in_file(file_name);
			cout << endl;
			break;
		}
		case 9:
		{
			cout << endl;
			cout << "������� ��� ����� ��� ���������(��� �������): ";
			getline(cin, file_name);
			company.input_from_file(file_name);
			cout << endl;
			break;
		}
		case 10:
		{
			cout << endl;
			company.pop_all();
			company.set_name("���_��_���������");
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
			cout << "����� ������ ��� � ����" << endl;
			cout << endl;
			break;
		}
		}

	}while (exit);
}