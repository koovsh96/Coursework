#include <iostream> // ���������� ������������ ���� � ��������, ��������� � ����������� ��� ����������� �����-������
#include <fstream> // ����� �������, ������� � �������, ������� ������������� ��������� ��� ������/������ ������ ��/� ����
#include <string> // ��� ����������� ������ �� ��������
using namespace std; // ������������ ����
void read()// ������� ������ �� �����
{
	char buff[50]; // ����� �������������� �������� ������������ �� ����� ������
	ifstream fin("C:\\��������\\test1.txt"); // ������� ���� ��� ������
	fin.getline(buff, 50); // ������� ������ �� �����
	fin.close(); // ��������� ����
	cout << buff << endl; // ���������� ��� ������ 
}
void write() // ������� ������ � ����
{
	char a[255];//
	cin.ignore();
	cout << "������� ������:" << endl; //����� �� ����� �������
	cin.getline(a, sizeof(a));//���������� "�" ��������� ������
	ofstream out("C:\\��������\\test1.txt"); //������� ���� ��� ������
	out << a << "\n"; //���� ������
	out.close(); //��������� ����
	memset(a, NULL, 255); //�������� ����������
}
bool passwordadmin_is_valid(string password) //������� �������� ������ ��� ������������ 1
 {
	 string valid_pass = "admin"; //���������� ������
	 if (valid_pass == password) //��������� � ���������� �������
		 return true;
	 else
		 return false;
 }
void adminpass() // ������� ����� ������ 1 � ��� ��������
{
	string user_pass; // ���������� ����������
	cout << "������� ������: ";
	cin >> user_pass; // ���������� ���������� ��������� ��������
	system("cls"); // ������� ������
	if (passwordadmin_is_valid(user_pass)) // �������� ������
	{
		cout << "������ ��������." << endl;
	}
	else
	{
		cout << "�������� ������!" << endl;
		adminpass();
	}
}
int main() //������� �������
{
	setlocale(LC_ALL, "Rus"); // ����������� �������� �����
	system("color 2");
	int s = 1; //���������� ����������
	char input_log[21]; // �������� ������
	string admin = "admin"; // ����� ��������������
	char str_array[20][6]; // ������,��� ����� ��������� ������ �������������
	int otv = 1, n = -1, v = 0;
    u:
	cout << "������� �����: ";
	cin >> input_log; // ���������� ���������� ��������� ��������
	if (input_log == admin)
	{
		adminpass(); //����� �������
		while (s != 0)
		{
		p:
			cout << "1-�������� ������ ������������." << endl << "2-���������� ����." << endl << "3-������." << endl << "4-������." << endl << "5-�����." << endl;
			scanf("%d", &s);
			switch (s)
			{
			case 1:
			{
				n++;
				cout << "������� ��� ������ ������������: ";
				cin >> (str_array[n]); // ���� � n-�� ������ �������
				while (otv != 0)
				{
					cout << "������� ��� ������ ������������?" << endl << "1.��." << endl << "2.���, ������� ������ �������������." << endl << "3.��������� �����." << endl;
					scanf("%d", &otv);
					system("cls");
					switch (otv)
					{
					case 1:
						n++;
						cout << "������� ��� ������ ������������: ";
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
						cout << "�������� ������������: " << endl;
						for (int i = 0; i <= n; i++)
						{
							cout << i + 1 << "- " << str_array[i] << endl;
						}
							cin >>v;
							v--;	
							cout << "a)��������� ������;" << endl << "b)��������� ������;" << endl << "c)��������� ������ � ������;"<<endl;
							cin >> str_array[v][21]; // ���� ����� � ������ v �� ����� 21 �������� ������
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
							cout << "1-������." << endl;
							cin >> j;
							if (j == 1)
							{
								write();
							}
						}
						if (str_array[x][21] == 'b')
						{
							system("cls");
							cout << "1-������." << endl;
							cin >> j;
							if (j == 1)
							{
								read();
							}
						}
						if (str_array[x][21] == 'c')
						{
							system("cls");
							cout << "1-������." << endl << "2-������." << endl;
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