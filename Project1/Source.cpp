#include <iostream>
#include "Library.h"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	Library lib;
	cout << "Привет!";
	int choose;

	try {
		while (true) {
			cout << "\nЧто бы вы хотели сделать?\n1)Добавить книгу\n2)Удалить книгу\n3)Вывести все книги на консоль\n4)Вывести на консоль все книги заданного автора\n5)Вывести на консоль все книги заданного издательства\n6)Вывести на консоль все книги, выпущенные после определенного года\n7)Найти книгу по имени\n8)Вывести отчет о книгах в отдельный файл\nЛюбое другое число закроет программу\nВаш выбор:\t";
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
		cout << "Тут какая то ошибка!";
	}
	


	return 0;
}