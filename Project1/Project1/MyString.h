#pragma once
class MyString
{
private:
	char* m_pStr;		// Ёлемент данных класса (адрес строки)
public:
	MyString(); //ќбъ€вление конструктора по умолчанию
	MyString(const char* s);	// ќбъ€вление конструктора с параметром
	MyString(const MyString& copy); // ќбъ€вление конструктора копировани€
	~MyString();		// ќбъ€вление деструктора
	MyString& operator= (const MyString& str);
	void Copy(const char* s);
	char* GetString();	// ќбъ€вление метода (accessor)
	int GetLength();	// ќбъ€вление метода (длина строки)
	friend std::ostream& operator<<(std::ostream& out, const MyString& str);
};
