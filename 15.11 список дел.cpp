
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
	std::cout << "������� ���������� ���: ";
	std::cin >> how_much_del;
	std::vector<Spisok>spisok_vec;
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
		case 2 ://        �������
			int del_deal;
			std::cout << "����� ���� �� ������ ��� �������? \n";
			std::cin >> del_deal;
			std::cout << "���� � " << del_deal << " �������\n";
			del_deal = del_deal - 1; 
			spisok_vec.erase(spisok_vec.begin() + del_deal);
			break;
		case 3://        �������������
			int red,red_choice;
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

					break;
				case 2://�������������� ����������

					break;
				case 3://�������������� �������

					break;
				case 4://�������������� ����

					break;
				case 5://�������������� �������

					break;
				case 6://�������������� ����� �����

					break;
				case 7://�������

					break;
			}

			break;
		case 4://        �����


			break;
		case 5://        ����������� ����


			break;
		case 6://        ���������� ��� ����


			break;
		}
	}
}