#pragma once
class MyString
{
private:
	char* m_pStr;		// ������� ������ ������ (����� ������)
public:
	MyString(); //���������� ������������ �� ���������
	MyString(const char* s);	// ���������� ������������ � ����������
	MyString(const MyString& copy); // ���������� ������������ �����������
	~MyString();		// ���������� �����������
	MyString& operator= (const MyString& str);
	void Copy(const char* s);
	char* GetString();	// ���������� ������ (accessor)
	int GetLength();	// ���������� ������ (����� ������)
	friend std::ostream& operator<<(std::ostream& out, const MyString& str);
};
