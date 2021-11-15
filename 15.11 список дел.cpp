
/*создать приложение список дел
приложение может :
добавить дело. у дела есть название, описание, дата и время исполнения.
удаление дел
редактирование дел
поиск дел по названию, приоритету, описанию, дате и времени исполнения.
отображение списка дел на день, на месяц, на год.
при отображение должна быть возможность сортировки по приоритету, по дате и времени
*/

#include<iostream>
#include<string>
#include<vector>


struct Spisok
{
	std::string name;
	int prioritu;
	std::string detali;
	int day;
	int month;
	int year;
	double hour;

	Spisok()
	{
		name = "Name";
		prioritu = 0;
		detali = "no detali";
		day = 0;
		month = 0;
		year = 0;
		hour = 0.0;
	}

	void redact()
	{
		setlocale(LC_ALL, "ru");
		std::cout << "Name: ";
		std::cin.ignore(100, '\n');
		getline(std::cin, name);
		std::cout << "Priority from 1 to 5 ( 1 - unimportantly, 5 - important ) ";
		std::cin >> prioritu;
		std::cout << "Detals: ";
		std::cin.ignore(100, '\n');
		getline(std::cin, detali);
		std::cout << "day: ";
		std::cin >> day;
		std::cout << "month: ";
		std::cin >> month;
		std::cout << "year: ";
		std::cin >> year;
		std::cout << "time: ";
		std::cin >> hour;
	}
	void print()
	{
		std::cout << name << " ";
		std::cout << prioritu << " ";
		std::cout << detali << " ";
		std::cout << day;
		std::cout << month;
		std::cout << year;
		std::cout << hour;
	}
	~Spisok()
	{

	}
};
void see_vect(std::vector<Spisok>spisok_vec) 
{
	std::cout << "\nSpisok del: \n";
	for (int i = 0; i < spisok_vec.size(); i++)
	{
		std::cout << i + 1<<' ';
		spisok_vec.at(i).print();
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int main_choice = 100, how_much_del;
	std::cout << "введите количество дел: ";
	std::cin >> how_much_del;
	std::vector<Spisok>spisok_vec;
	Spisok buff_spisok;      //создали пустой список
	for (int i = 0; i < how_much_del; i++)  //записываем дела в вектор
	{
		buff_spisok.redact();
		spisok_vec.push_back(buff_spisok);  //  кладем дела в вектор
	}
	while (main_choice != 0)
	{
		std::cout << "1. Добавить \n";
		std::cout << "2. Удалить \n";
		std::cout << "3. Редактировать \n";
		std::cout << "4. Поиск \n";
		std::cout << "5. Отображение дела \n";
		std::cout << "6. Отобразить все дела \n";
		std::cout << "0. Выход \n";
		std::cin >> main_choice;

		switch (main_choice)
		{
		case 1://         ДОБАВИТЬ
			int add_deal;
			std::cout << "Сколько дел добавить?\n";
			std::cin >> add_deal;
			for (int i = 0; i < add_deal; i++)  //записываем дела в вектор
			{
				buff_spisok.redact();
				spisok_vec.push_back(buff_spisok);  //  кладем дела в вектор
			}

			break;
		case 2 ://        УДАЛИТЬ
			int del_deal;
			std::cout << "Какое дело из списка дел удалить? \n";
			std::cin >> del_deal;
			std::cout << "Дело № " << del_deal << " удалено\n";
			del_deal = del_deal - 1; 
			spisok_vec.erase(spisok_vec.begin() + del_deal);
			break;
		case 3://        РЕДАКТИРОВАТЬ
			int red,red_choice;
			std::cout << "Какое из дел будем редактировать? \n";
			std::cin >> red;
			red = red - 1;

			std::cout << "Что именно редактируем: \n";
			std::cout << "1. Имя \n";
			std::cout << "2. Приоритет \n";
			std::cout << "3. Детали \n";
			std::cout << "4. Дата \n";
			std::cout << "5. Время \n";
			std::cout << "6. Все сразу \n";
			std::cout << "7. Вернуться в предудущее меню \n";
			std::cin >> red_choice;
			switch (red_choice)
			{
				case 1://редактирование имени

					break;
				case 2://редактирование приоритета

					break;
				case 3://редактирование деталей

					break;
				case 4://редактирование даты

					break;
				case 5://редактирование времени

					break;
				case 6://редактирование всего сразу

					break;
				case 7://возврат

					break;
			}

			break;
		case 4://        ПОИСК


			break;
		case 5://        ОТОБРАЖЕНИЕ ДЕЛА


			break;
		case 6://        ОТОБРАЗИТЬ ВСЕ ДЕЛА


			break;
		}
	}
}