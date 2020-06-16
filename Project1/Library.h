#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Library
{
private:
	class Book
	{
		std::string _author, _name, _publishingHouse;			//Автор, название книги, издательство
		int _year, _numberOfPages;	//Год выпуска, количество страниц


	public:
		Book(std::string name, std::string author, std::string publishingHouse, int year, int numberOfPages)		//ctor с параметрами
		{
			_name = name, _author = author, _publishingHouse = publishingHouse, _year = year, _numberOfPages = numberOfPages;
		}
					
		Book()			//ctor без параметров
		{
		start:
			printf("Как бы вы хотели добавить книгу? Вручную или из файла(1/2)?\n");
			int choose;
			cin >> choose;
			switch (choose)
			{
			case 1:
				printf("Введите название книги, автора, издательство, год выпуска и количество страниц:\n");
				cout << "Введите название:\t"; ws(cin); getline(cin, _name);
				cout << "Введите автора:\t"; ws(cin); getline(cin, _author);
				cout << "Введите издательство:\t"; ws(cin); getline(cin, _publishingHouse);
				cout << "Введите год издания:\t"; ws(cin); cin >> _year;
				cout << "Введите количество страниц:\t"; cin >> _numberOfPages;
				break;
			case 2:
				try {
					ifstream input("input.txt", ios::in);
					if (input.is_open())
						throw new exception("Файл не открыт!");
					getline(input, _name);
					getline(input, _author);
					getline(input, _publishingHouse);
					input >> _year >> _numberOfPages;
					input.close();
				}
				catch (...) {
					cout << "Невозможно ввести данные из файла! Попробуйте вручную!\n";
					goto start;
				}
				break;
			default:
				goto start;
				break;
			}
		}	
		//Геттеры
		string GetAuthor() { return _author; }
		string GetPublisHouse() { return _publishingHouse; }
		int GetYear() { return _year; }

		void Print() {		//Вывод инфы о книге на консоль
			cout << _name << "\t" << _author << "\t" << _publishingHouse << "\t" << _year << "г.\t" << _numberOfPages << "стр.\n";
		}

		friend ofstream& operator<<(ofstream& stream, Book& book) { //Перегрузка оператора << класса ofstream
			stream << book._name << "\t" << book._author << "\t" << book._publishingHouse << "\t" << book._year << "г.\t" << book._numberOfPages << "стр.\n";
			return stream;
		}
	};

	vector<Book> base;		//База книг

public:
	Library() = default;

	void SearchBooksByAuthor() {		//Поиск книг по автору
		if (base.size() == 0)
			throw (string)"Библиотека пуста!";
		string author;
		cout << "Введите автора: ";
		ws(cin); getline(cin, author);
		printf("Книги автора %s\n", author.c_str());
		for (Book book : base) {
			if (_strcmpi(author.c_str(), book.GetAuthor().c_str()) == 0) 
			{
				book.Print();
			}
		}
	}

	void SearchBooksByPublishingHouse() {		//Поиск книг по издательству
		if (base.size() == 0)
			throw (string)"Библиотека пуста!";
		string publishingHouse;
		cout << "Введите издательство: ";
		ws(cin); getline(cin, publishingHouse);
		printf("Книги издательства %s\n", publishingHouse.c_str());
		for (Book book : base) {
			if (_strcmpi(publishingHouse.c_str(), book.GetPublisHouse().c_str()) == 0)
			{
				book.Print();
			}
		}
	}


	void SearchBooksByYear() {		//Поиск книг по году
		if (base.size() == 0)
			throw (string)"Библиотека пуста!";
		int year;
		cout << "Введите год: ";
		cin >> year;
		printf("Книги года после %d\n", year);
		for (Book book : base) {
			if (book.GetYear() > year)
			{
				book.Print();
			}
		}
	}

	int SearchBookByName() {	//Поиск книг по названию
		if (base.size() == 0)
			throw (string)"Библиотека пуста!";
		string name;
		cout << "Введите имя: ";
		ws(cin); getline(cin, name);
		for (int i = 0; i < base.size(); ++i) {
			if (_strcmpi(name.c_str(), base[i].GetPublisHouse().c_str()) == 0)
			{
				base[i].Print();
				return i;
			}
			cout << "Книга не найдена!";
			return -1;
		}
	}

	void AddBook() {		//Добавление книги в базу
		base.push_back(*(new Book()));
	}

	void AddBook(std::string name, std::string author, std::string publishingHouse, int year, int numberOfPages) {
		base.push_back(*new Book(name, author, publishingHouse, year, numberOfPages));
	}

	void DeleteBook() {		//Удаление книги в базе
		int index = SearchBookByName();
		if (index != -1) {
			base.erase(base.begin() + index);
			cout << "Удалено!";
		}
		else {
			cout << "Элемент не найден!";
		}
	}

	void CreateReport() {		//Создание отчета по книгам
		if (base.size() == 0)
			throw (string)"Библиотека пуста!";
		ofstream output("output.txt", ios::out | ios::trunc);
		for (Book book : base)
			output << book;
		output.close();
	}
	void Print() {		//Вывод всех книг на консоль
		if (base.size() == 0)
			throw (string)"Библиотека пуста!";
		for (Book book : base) {
			book.Print();
		}
	}
};

