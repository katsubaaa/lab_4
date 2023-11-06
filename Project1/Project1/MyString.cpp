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
		// ����������� �������� ��������� ���������� ������.
		int len = strlen(s) + 1;
		m_pStr = new char[len];
		// + 1, ��� ��� ������� ���� ���� ����� �����������
		// ���� ������ ��������, �������� ������-�������� � ������-���� ������
		if (m_pStr)
			strcpy_s(m_pStr, len, s);
	}
}

// ����������� ������������.
MyString::MyString(const char* s)
{
	//m_pStr = 0;
	delete m_pStr; //���������� ���������� ���� ������
	Copy(s);
}

// ����������� �� ���������
MyString::MyString()
{
	m_pStr = new char;
	*m_pStr = 0;
}

// ����������� �����������.
MyString::~MyString()
{
	// ������������ ������, ������� � ������������ ��� ������-����� ������
	delete[] m_pStr;
}

// ����� ������
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}




//���������� ���������� ��������� ������������
MyString& MyString::operator= (const MyString& str)
{
	if (this != &str) //� ������ ���������� ������ ������ ������ �� ����� (� ��� ����� ����������� ���� ������)
	{
		delete m_pStr; //���������� ���������� ���� ������
		Copy(str.m_pStr);
	}
	return *this; //��� ����, ����� ���������� �������� ������������ ���������� �� ������ ����� ������� �������
}

//����������� ������������ �����������
MyString::MyString(const MyString& copy) {
	Copy(copy.m_pStr);
}

std::ostream& operator<<(std::ostream& out, const MyString& str) {
	out << str.m_pStr;
	return out;
}