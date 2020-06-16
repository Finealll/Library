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
		std::string _author, _name, _publishingHouse;			//�����, �������� �����, ������������
		int _year, _numberOfPages;	//��� �������, ���������� �������


	public:
		Book(std::string name, std::string author, std::string publishingHouse, int year, int numberOfPages)		//ctor � �����������
		{
			_name = name, _author = author, _publishingHouse = publishingHouse, _year = year, _numberOfPages = numberOfPages;
		}
					
		Book()			//ctor ��� ����������
		{
		start:
			printf("��� �� �� ������ �������� �����? ������� ��� �� �����(1/2)?\n");
			int choose;
			cin >> choose;
			switch (choose)
			{
			case 1:
				printf("������� �������� �����, ������, ������������, ��� ������� � ���������� �������:\n");
				cout << "������� ��������:\t"; ws(cin); getline(cin, _name);
				cout << "������� ������:\t"; ws(cin); getline(cin, _author);
				cout << "������� ������������:\t"; ws(cin); getline(cin, _publishingHouse);
				cout << "������� ��� �������:\t"; ws(cin); cin >> _year;
				cout << "������� ���������� �������:\t"; cin >> _numberOfPages;
				break;
			case 2:
				try {
					ifstream input("input.txt", ios::in);
					if (input.is_open())
						throw new exception("���� �� ������!");
					getline(input, _name);
					getline(input, _author);
					getline(input, _publishingHouse);
					input >> _year >> _numberOfPages;
					input.close();
				}
				catch (...) {
					cout << "���������� ������ ������ �� �����! ���������� �������!\n";
					goto start;
				}
				break;
			default:
				goto start;
				break;
			}
		}	
		//�������
		string GetAuthor() { return _author; }
		string GetPublisHouse() { return _publishingHouse; }
		int GetYear() { return _year; }

		void Print() {		//����� ���� � ����� �� �������
			cout << _name << "\t" << _author << "\t" << _publishingHouse << "\t" << _year << "�.\t" << _numberOfPages << "���.\n";
		}

		friend ofstream& operator<<(ofstream& stream, Book& book) { //���������� ��������� << ������ ofstream
			stream << book._name << "\t" << book._author << "\t" << book._publishingHouse << "\t" << book._year << "�.\t" << book._numberOfPages << "���.\n";
			return stream;
		}
	};

	vector<Book> base;		//���� ����

public:
	Library() = default;

	void SearchBooksByAuthor() {		//����� ���� �� ������
		if (base.size() == 0)
			throw (string)"���������� �����!";
		string author;
		cout << "������� ������: ";
		ws(cin); getline(cin, author);
		printf("����� ������ %s\n", author.c_str());
		for (Book book : base) {
			if (_strcmpi(author.c_str(), book.GetAuthor().c_str()) == 0) 
			{
				book.Print();
			}
		}
	}

	void SearchBooksByPublishingHouse() {		//����� ���� �� ������������
		if (base.size() == 0)
			throw (string)"���������� �����!";
		string publishingHouse;
		cout << "������� ������������: ";
		ws(cin); getline(cin, publishingHouse);
		printf("����� ������������ %s\n", publishingHouse.c_str());
		for (Book book : base) {
			if (_strcmpi(publishingHouse.c_str(), book.GetPublisHouse().c_str()) == 0)
			{
				book.Print();
			}
		}
	}


	void SearchBooksByYear() {		//����� ���� �� ����
		if (base.size() == 0)
			throw (string)"���������� �����!";
		int year;
		cout << "������� ���: ";
		cin >> year;
		printf("����� ���� ����� %d\n", year);
		for (Book book : base) {
			if (book.GetYear() > year)
			{
				book.Print();
			}
		}
	}

	int SearchBookByName() {	//����� ���� �� ��������
		if (base.size() == 0)
			throw (string)"���������� �����!";
		string name;
		cout << "������� ���: ";
		ws(cin); getline(cin, name);
		for (int i = 0; i < base.size(); ++i) {
			if (_strcmpi(name.c_str(), base[i].GetPublisHouse().c_str()) == 0)
			{
				base[i].Print();
				return i;
			}
			cout << "����� �� �������!";
			return -1;
		}
	}

	void AddBook() {		//���������� ����� � ����
		base.push_back(*(new Book()));
	}

	void AddBook(std::string name, std::string author, std::string publishingHouse, int year, int numberOfPages) {
		base.push_back(*new Book(name, author, publishingHouse, year, numberOfPages));
	}

	void DeleteBook() {		//�������� ����� � ����
		int index = SearchBookByName();
		if (index != -1) {
			base.erase(base.begin() + index);
			cout << "�������!";
		}
		else {
			cout << "������� �� ������!";
		}
	}

	void CreateReport() {		//�������� ������ �� ������
		if (base.size() == 0)
			throw (string)"���������� �����!";
		ofstream output("output.txt", ios::out | ios::trunc);
		for (Book book : base)
			output << book;
		output.close();
	}
	void Print() {		//����� ���� ���� �� �������
		if (base.size() == 0)
			throw (string)"���������� �����!";
		for (Book book : base) {
			book.Print();
		}
	}
};

