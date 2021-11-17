
/*������� ���������� ������ ���
���������� ����� :
�������� ����. � ���� ���� ��������, ��������, ���� � ����� ����������.
�������� ���
�������������� ���
����� ��� �� ��������, ����������, ��������, ���� � ������� ����������.
����������� ������ ��� �� ����, �� �����, �� ���.
��� ����������� ������ ���� ����������� ���������� �� ����������, �� ���� � �������
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
		std::cout << "\nName: " << name << " \n";
		std::cout << "Priority: " << prioritu << " \n";
		std::cout << "Detali: " << detali << " \n";
		std::cout << "Day:" << day << " \n";
		std::cout << "Month: " << month << " \n";
		std::cout << "Year: " << year << " \n";
		std::cout << "Time: " << hour << " \n";
		std::cout << " \n";
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
		std::cout << i + 1 << ' ';
		spisok_vec.at(i).print();
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int main_choice = 100, how_much_del;
	std::cout << "������� ���������� ���: ";
	std::cin >> how_much_del;
	int count;
	std::string search_name;
	std::string search_del;
	std::vector<Spisok>spisok_vec, spisok_vec1, spisok_vec2, spisok_vec3;
	Spisok buff_spisok;      //������� ������ ������
	for (int i = 0; i < how_much_del; i++)  //���������� ���� � ������
	{
		buff_spisok.redact();
		spisok_vec.push_back(buff_spisok);  //  ������ ���� � ������
	}
	while (main_choice != 0)
	{
		std::cout << "1. �������� \n";
		std::cout << "2. ������� \n";
		std::cout << "3. ������������� \n";
		std::cout << "4. ����� \n";
		std::cout << "5. ����������� ���� \n";
		std::cout << "6. ���������� ��� ���� \n";
		std::cout << "0. ����� \n";
		std::cin >> main_choice;

		switch (main_choice)
		{
		case 1://         ��������
			int add_deal;
			std::cout << "������� ��� ��������?\n";
			std::cin >> add_deal;
			for (int i = 0; i < add_deal; i++)  //���������� ���� � ������
			{
				buff_spisok.redact();
				spisok_vec.push_back(buff_spisok);  //  ������ ���� � ������
			}

			break;
		case 2://        �������
			int del_deal;
			std::cout << "����� ���� �� ������ ��� �������? \n";
			std::cin >> del_deal;
			std::cout << "���� � " << del_deal << " �������\n";
			del_deal = del_deal - 1;
			spisok_vec.erase(spisok_vec.begin() + del_deal);
			break;
		case 3://        �������������
			int red, red_choice;
			std::cout << "����� �� ��� ����� �������������? \n";
			std::cin >> red;
			red = red - 1;

			std::cout << "��� ������ �����������: \n";
			std::cout << "1. ��� \n";
			std::cout << "2. ��������� \n";
			std::cout << "3. ������ \n";
			std::cout << "4. ���� \n";
			std::cout << "5. ����� \n";
			std::cout << "6. ��� ����� \n";
			std::cout << "7. ��������� � ���������� ���� \n";
			std::cin >> red_choice;
			switch (red_choice)
			{
			case 1://�������������� �����
				std::cout << "Enter new name:\n";
				std::cin.ignore(32767, '\n');
				getline(std::cin, spisok_vec.at(red).name);
				break;
			case 2://�������������� ����������
				std::cout << "Enter new priority:\n";
				std::cin >> spisok_vec.at(red).prioritu;
				break;
			case 3://�������������� �������
				std::cout << "Enter new detals:\n";
				std::cin.ignore(32767, '\n');
				getline(std::cin, spisok_vec.at(red).detali);
				break;
			case 4://�������������� ����
				std::cout << "Enter new day:\n";
				std::cin >> spisok_vec.at(red).day;
				std::cout << "Enter new month:\n";
				std::cin >> spisok_vec.at(red).month;
				std::cout << "Enter new year:\n";
				std::cin >> spisok_vec.at(red).year;
				break;
			case 5://�������������� �������
				std::cout << "Enter new time:\n";
				std::cin >> spisok_vec.at(red).hour;
				break;
			case 6://�������������� ����� �����
				std::cout << "Enter new info:\n";
				spisok_vec.at(red).redact();
				break;
			default:
				std::cout << "error!!\n";
				break;
			case 7://�������
				break;
			}

			break;
		case 4://        �����
			int search;
			std::cout << "\nSearch for:\n";
			std::cout << "1.Name\n";
			std::cout << "2.Priority\n";
			std::cout << "3.Detals\n";
			std::cout << "4.Date\n";
			std::cout << "5.Time\n";
			std::cout << "6.Back\n";
			std::cin >> search;
			switch (search)
			{
			case 1:   //����� �� �����
				std::cout << "Enter name: ";
				std::cin >> search_name;
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (search_name == spisok_vec.at(i).name)
					{
						spisok_vec.at(i).print();
						count++;
					}
				}
				if (count == 0)
					std::cout << "net sovpadenii\n";
				break;

			case 2:  //����� �� ����������
				int search_prior;
				std::cout << "Enter piority: ";
				std::cin >> search_prior;
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (search_prior == spisok_vec.at(i).prioritu)
					{
						spisok_vec.at(i).print();
						count++;
					}
				}
				if (count == 0)
					std::cout << "net sovpadenii\n";
				break;

			case 3:     //����� �� ��������
				count = 0;
				std::cout << "Enter detals: ";
				std::cin >> search_del;
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (search_del == spisok_vec.at(i).detali)
					{
						spisok_vec.at(i).print();
						count++;
					}
				}
				if (count == 0)
					std::cout << "net sovpadenii\n";
				break;

			case 4:    // ����� �� ����
				count = 0;
				int search_day, search_month, search_year;
				std::cout << "Enter day: ";
				std::cin >> search_day;
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (search_day == spisok_vec.at(i).day)
					{
						spisok_vec1.push_back(spisok_vec.at(i));
						count++;
					}
				}
				std::cout << "Deal in day: \n";
				for (int i = 0; i < spisok_vec1.size(); i++)
				{
					std::cout << i + 1 << ". ";
					spisok_vec1.at(i).print();
				}
				if (count == 0)
					std::cout << "net sovpadenii\n";
				spisok_vec1.clear();


				std::cout << "\nEnter month: ";
				std::cin >> search_month;
				count = 0;
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (search_month == spisok_vec.at(i).month)
					{
						spisok_vec2.push_back(spisok_vec.at(i));
						count++;
					}
				}
				std::cout << "Deal in month: \n";
				for (int i = 0; i < spisok_vec2.size(); i++)
				{
					std::cout << i + 1 << ". ";
					spisok_vec2.at(i).print();
				}
				if (count == 0)
					std::cout << "net sovpadenii\n";
				spisok_vec2.clear();

				std::cout << "\nEnter year: ";
				std::cin >> search_year;
				count = 0;
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (search_year == spisok_vec.at(i).year)
					{
						spisok_vec3.push_back(spisok_vec.at(i));
						count++;
					}
				}
				std::cout << "Deal in year: \n";
				for (int i = 0; i < spisok_vec3.size(); i++)
				{
					std::cout << i + 1 << ". ";
					spisok_vec3.at(i).print();
				}
				if (count == 0)
					std::cout << "net sovpadenii\n";
				spisok_vec3.clear();
				break;

			case 5:      //����� �� �������
				int search_time;
				std::cout << "Enter time: ";
				std::cin >> search_time;
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (search_time == spisok_vec.at(i).hour)
					{
						spisok_vec.at(i).print();
						count++;
					}
				}
				if (count == 0)
					std::cout << "net sovpadenii\n";
				break;

			case 6:

				break;
			default:
				std::cout << "error!!";
				break;

			}
			break;
		case 5://        ���������� ����
			int look_day;
			std::cout << "\n���������� ���� ��:\n";
			std::cout << "1. ���� � ������:\n";
			std::cout << "2. ������� � ����:\n";
			std::cout << "3. �����:\n";
			std::cout << "0. �����:\n";
			std::cin >> look_day;
			switch (look_day)
			{
			case 1: //��������� ���� �� ����
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (spisok_vec.at(i).day > 0 || spisok_vec.at(i).day < 32)
					{
						spisok_vec.at(i).print();
					}
					else
						std::cout << " in month not must be more 31 day\n";
				}
				break;

			case 2:  //���������� ���� �� �������
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (spisok_vec.at(i).month > 0 || spisok_vec.at(i).month < 13)
					{
						spisok_vec.at(i).print();
					}
					else
						std::cout << " in year not must be more 13 month\n";
				}
				break;

			case 3: //���������� ���� � �� �����
				for (int i = 0; i < spisok_vec.size(); i++)
				{
					if (spisok_vec.at(i).year > 0)
					{
						spisok_vec.at(i).print();
					}
				}
				break;
			case 0:
				break;
			default:
				std::cout << "\nerror!!\n";
				break;
			}

			break;
		case 6://        ���������� ��� ����
			std::cout << "\n������ ����� ���� ���:\n";
			for (int i = 0; i < spisok_vec.size(); i++)
			{
				std::cout << i + 1 << ". ";
				spisok_vec.at(i).print();
			}
			break;
		}
	}
}