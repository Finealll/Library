#include <iostream>
#include "Library.h"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	Library lib;
	cout << "������!";
	int choose;

	try {
		while (true) {
			cout << "\n��� �� �� ������ �������?\n1)�������� �����\n2)������� �����\n3)������� ��� ����� �� �������\n4)������� �� ������� ��� ����� ��������� ������\n5)������� �� ������� ��� ����� ��������� ������������\n6)������� �� ������� ��� �����, ���������� ����� ������������� ����\n7)����� ����� �� �����\n8)������� ����� � ������ � ��������� ����\n����� ������ ����� ������� ���������\n��� �����:\t";
			cin >> choose;
			switch (choose)
			{
			case 1:
				lib.AddBook();
				break;
			case 2:
				lib.DeleteBook();
				break;
			case 3:
				lib.Print();
				break;
			case 4:
				lib.SearchBooksByAuthor();
				break;
			case 5:
				lib.SearchBooksByPublishingHouse();
				break;
			case 6:
				lib.SearchBooksByYear();
				break;
			case 7:
				lib.SearchBookByName();
				break;
			case 8:
				lib.CreateReport();
				break;
			default:
				return 0;
			}
		}
	}
	catch (string mes) {
		cout << mes;
	}
	catch (...) {
		cout << "��� ����� �� ������!";
	}
	


	return 0;
}