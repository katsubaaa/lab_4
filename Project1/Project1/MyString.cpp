#include "stdafx.h"
#include "MyString.h"
#pragma warning(disable : 4996)

void MyString::Copy(const char* s)
{
	if (s == 0)
	{
		m_pStr = new char;
		*m_pStr = 0;
	}
	else
	{
		// Динамически выделяем требуемое количество памяти.
		int len = strlen(s) + 1;
		m_pStr = new char[len];
		// + 1, так как нулевой байт тоже нужно скопировать
		// Если память выделена, копируем строку-аргумент в строку-член класса
		if (m_pStr)
			strcpy_s(m_pStr, len, s);
	}
}

// Определение конструктора.
MyString::MyString(const char* s)
{
	//m_pStr = 0;
	delete m_pStr; //освободили предыдущий блок памяти
	Copy(s);
}

// Конструктор по умолчанию
MyString::MyString()
{
	m_pStr = new char;
	*m_pStr = 0;
}

// Определение деструктора.
MyString::~MyString()
{
	// Освобождение памяти, занятой в конструкторе для строки-члена класса
	delete[] m_pStr;
}

// Метод класса
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}




//Реализация перегрузки оператора присваивания
MyString& MyString::operator= (const MyString& str)
{
	if (this != &str) //в случае совпадения адреса ничего делать не нужно (а тем более освобождать блок памяти)
	{
		delete m_pStr; //освободили предыдущий блок памяти
		Copy(str.m_pStr);
	}
	return *this; //для того, чтобы обеспечить цепочное присваивание возвращаем по ссылке адрес данного объекта
}

//Определение конструктора копирования
MyString::MyString(const MyString& copy) {
	Copy(copy.m_pStr);
}

std::ostream& operator<<(std::ostream& out, const MyString& str) {
	out << str.m_pStr;
	return out;
}