#include <iostream>

using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

struct PC 
{
	string name;
	int ram;
	Date data123;
	double price;
};

int main()
{
	setlocale(LC_ALL, "rus");
	string AMD("AMD");

	const int N = 2;
	PC product[N];
	for (int i = 0; i < N; i++)
	{
		cout << "Производитель ПК" << endl;
		cin >> product[i].name;
		cout << "Цена" << endl;
		cin >> product[i].price;
		cout << "Введите количество желаемого ОЗУ(оперативной памяти)" << endl;
		cin >> product[i].ram;
		do
		{
			cout << endl << "Введите дату изготовления" << endl;
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> product[i].data123.day >> product[i].data123.month >> product[i].data123.year;
		} while (!product[i].data123.isCorrect());
		cout << endl << endl;
		if (!product[i].name.compare(( AMD))) 
		{ 
			cout << "Производитель " << product[i].name << " по цене: " << product[i].price << " c количествои ОЗУ: " << product[i].ram << endl << endl; }
		else { cout << "I'm sorry, go away with your " << product[i].name; }	
	}
	int best = 0;
	int i = 0;
	for (i = 1; i < N; i++)
	{
		if (!product[i].name.compare(AMD))
		{
			if (product[i].price < product[best].price)
			{
				best = i;
			}
		}
		
	}
	cout << endl << endl << "AMD по цене " << product[best].price << "(невероятно) дешевле" << endl; 
}