#include <iostream> // подключаем заголовочный файл с классами, функциями и переменными для организации ввода-вывода
#include <fstream> // набор классов, методов и функций, которые предоставляют интерфейс для чтения/записи данных из/в файл
#include <string> // для организации работы со строками
using namespace std; // пространство имен
void read()// функция чтения из файла
{
	char buff[50]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("C:\\Курсовая\\test1.txt"); // открыли файл для чтения
	fin.getline(buff, 50); // считали строку из файла
	fin.close(); // закрываем файл
	cout << buff << endl; // напечатали эту строку 
}
void write() // функция записи в файл
{
	char a[255];//
	cin.ignore();
	cout << "Введите строку:" << endl; //вывод на экран надписи
	cin.getline(a, sizeof(a));//присвоение "а" введенной строки
	ofstream out("C:\\Курсовая\\test1.txt"); //открыли файл для записи
	out << a << "\n"; //ввод строки
	out.close(); //закрываем файл
	memset(a, NULL, 255); //обнуляем переменную
}
bool passwordadmin_is_valid(string password) //функция проверки пароля для пользователя 1
 {
	 string valid_pass = "admin"; //правильный пароль
	 if (valid_pass == password) //сравнение с правильным паролем
		 return true;
	 else
		 return false;
 }
void adminpass() // функция ввода пароля 1 и его проверки
{
	string user_pass; // объявление переменной
	cout << "Введите пароль: ";
	cin >> user_pass; // присвоение переменной вводимого значения
	system("cls"); // очистка экрана
	if (passwordadmin_is_valid(user_pass)) // проверка пароля
	{
		cout << "Доступ разрешен." << endl;
	}
	else
	{
		cout << "Неверный пароль!" << endl;
		adminpass();
	}
}
int main() //главная функция
{
	setlocale(LC_ALL, "Rus"); // локализация русского языка
	system("color 2");
	int s = 1; //объявление переменных
	char input_log[21]; // вводимый пароль
	string admin = "admin"; // логин администратора
	char str_array[20][6]; // массив,где будут храниться логины пользователей
	int otv = 1, n = -1, v = 0;
    u:
	cout << "Введите логин: ";
	cin >> input_log; // присвоение переменной вводимого значения
	if (input_log == admin)
	{
		adminpass(); //вызов функции
		while (s != 0)
		{
		p:
			cout << "1-Создание нового пользователя." << endl << "2-Добавление прав." << endl << "3-Запись." << endl << "4-Чтение." << endl << "5-Выход." << endl;
			scanf("%d", &s);
			switch (s)
			{
			case 1:
			{
				n++;
				cout << "Введите имя нового пользователя: ";
				cin >> (str_array[n]); // ввод в n-ую строку массива
				while (otv != 0)
				{
					cout << "Создать еще одного пользователя?" << endl << "1.Да." << endl << "2.Нет, вывести список пользователей." << endl << "3.Вернуться назад." << endl;
					scanf("%d", &otv);
					system("cls");
					switch (otv)
					{
					case 1:
						n++;
						cout << "Введите имя нового пользователя: ";
						cin >> (str_array[n]);
						system("cls");
						break;
					case 2:
						for (int i = 0; i <= n; i++)
						{
							cout << str_array[i] << endl;
						}
						break;
					case 3:
						goto p;
						break;
					}
				}
				break;
			}
					case 2:
					{
						cout << "Выберите пользователя: " << endl;
						for (int i = 0; i <= n; i++)
						{
							cout << i + 1 << "- " << str_array[i] << endl;
						}
							cin >>v;
							v--;	
							cout << "a)разрешить запись;" << endl << "b)разрешить чтение;" << endl << "c)разрешить запись и чтение;"<<endl;
							cin >> str_array[v][21]; // ввод буквы в строку v на место 21 элемента строки
						break;
					}
					case 3:
					{
						write();
						system("cls");
						break;
					}
					case 4:
					{
						system("cls");
						read();
						break;
					}
					case 5:
					{
						system("cls");
						goto u;
						break;
					}
			   }
			}
	}
	else
	{
				int x=0,j;
				while (x<21)
				{
					if (strcmp(str_array[x], input_log) == 0)
					{
						if (str_array[x][21] == 'a' ) 
						{
							system("cls");
							cout << "1-Запись." << endl;
							cin >> j;
							if (j == 1)
							{
								write();
							}
						}
						if (str_array[x][21] == 'b')
						{
							system("cls");
							cout << "1-Чтение." << endl;
							cin >> j;
							if (j == 1)
							{
								read();
							}
						}
						if (str_array[x][21] == 'c')
						{
							system("cls");
							cout << "1-Запись." << endl << "2-Чтение." << endl;
							cin >> j;
							if (j == 1)
							{
								write();
							}
							if (j == 2)
							{
								read();
								
							}
						}
						x++;
					}
					else
					{
						x++;
					}
				}
				goto u;
	}
			system("pause");
			return 0;	
}