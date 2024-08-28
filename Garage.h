#include "Box.h"

class Garage
{
private:
	Box* head;//заголовочный элемент списка
	int number;
public:
	//конструктор
	Garage()
	{
		number = -1;
		Box* new_elem = new Box();
		head = new_elem;
		new_elem->set_next(head);//так как список кольцевой
		new_elem->set_prev(head);
	}
	//гетерры и сеттеры
	Box* get_head() { return head; }

	void set_number(int _number) { number = _number; }

	int get_number() { return number; }
	//функция проверки пустоты списка
	bool empty()
	{
		return ((head->get_next() == head) && head->get_prev() == head);
	}
	//функция проверки наличия элемента в списке(для проверки при удалении в основном меню)
	bool check(string _car_number, string _car_brand)
	{
		Box* current = head->get_next();
		while (current != head)
		{
			if (current->get_car_number() == _car_number && current->get_car_brand() == _car_brand)
			{
				return true;
			}

			current = current->get_next();
		}
		return false;
	}

	//функция добавления в пустой список
	void push_empty(string _car_number, string _car_brand)
	{
		Box* new_elem = new Box();
		new_elem->set_next(head);
		new_elem->set_prev(head);
		new_elem->set_car_number(_car_number);
		new_elem->set_car_brand(_car_brand);
		head->set_next(new_elem);
		head->set_prev(new_elem);
	}


	//функции поиска с начала списка и с конца списка
	Box* search_begin(string _car_number, string _car_brand)
	{
		Box* current = head->get_next();
		while (current != head)
		{
			if (current->get_car_number() == _car_number && current->get_car_brand() == _car_brand)
			{
				return current;
			}
			current = current->get_next();
		}
	}

	Box* search_end(string _car_number, string _car_brand)
	{
		Box* current = head->get_prev();
		while (current != head)
		{
			if (current->get_car_number() == _car_number && current->get_car_brand() == _car_brand)
			{
				return current;
			}
			current = current->get_prev();
		}
	}
	//функции добавления до элемента и после
	void push_after(string _car_number, string _car_brand, string after_number, string after_brand)
	{
		if (!empty())
		{
			Box* tmp = search_begin(after_number, after_brand);
			Box* new_elem = new Box();

			new_elem->set_next(tmp->get_next());
			new_elem->set_prev(tmp);
			new_elem->set_car_number(_car_number);
			new_elem->set_car_brand(_car_brand);

			(tmp->get_next())->set_prev(new_elem);
			tmp->set_next(new_elem);
		}
	}

	void push_before(string _car_number, string _car_brand, string before_number, string before_brand)
	{
		if (!empty())
		{
			Box* tmp = search_end(before_number, before_brand);
			Box* new_elem = new Box();

			new_elem->set_prev(tmp->get_prev());
			new_elem->set_next(tmp);
			new_elem->set_car_number(_car_number);
			new_elem->set_car_brand(_car_brand);

			(tmp->get_prev())->set_next(new_elem);
			tmp->set_prev(new_elem);
		}
	}
	//функции удаления элемента
	void pop(string _car_number, string _car_brand)
	{
		if (!empty())
		{
			Box* tmp = search_begin(_car_number, _car_brand);

			(tmp->get_next())->set_prev(tmp->get_prev());
			(tmp->get_prev())->set_next(tmp->get_next());

			delete tmp;
		}
	}
	//функции вывода списка в прямом и обратном порядке
	void status_next()
	{
		Box* current = head->get_next();
		while (current != head)
		{
			cout << "Номер машины: " << current->get_car_number() << "\t" << " Марка машины : " << current->get_car_brand() << endl;
			current = current->get_next();
		}
	}

	void status_prev()
	{
		Box* current = head->get_prev();
		while (current != head)
		{
			cout <<"Номер машины: " << current->get_car_number()<< "\t" << " Марка машины : " << current->get_car_brand() << endl;
			current = current->get_prev();
		}
	}
	//функция очистки списка
	void pop_all()
	{
		if (!empty())
		{
			Box* tmp;
			Box* current = head->get_next();
			while (current!=head)
			{
				tmp = current;
				current = current->get_next();
				delete tmp;
			}
			head->set_next(head);
			head->set_prev(head);
		}
	}
	//деструктор
	~Garage()
	{
		if (!empty()) {
			pop_all();
		}
		delete head;
	}
};