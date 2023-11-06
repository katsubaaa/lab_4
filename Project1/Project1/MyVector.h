#pragma once
#include "Shape.h"
class Vector :public Shape
{
private:
	double x, y;	// ���������� ������� �� ���������
	//static int Count;
public:
	//========== ��� ������������
	Vector(double c1, double c2);
	Vector(); // Default
	Vector(const Vector& copy);
	//====== ��������������� �������� =====//
	Vector& operator= (const Vector& v);	// ����������
	Vector operator+(const Vector&); //������+������
	Vector operator+(const double val); //������+�����
	friend Vector operator+(const double, Vector&); //�����+������
	friend double operator!(const Vector& v); //����� �������
	bool operator>(const Vector& v);
	bool operator==(const Vector& v) const;
	double operator*(const Vector&); //������*������
	Vector operator*(const double val); //������*�����
	friend Vector operator*(const double, Vector&); //�����*������
	double GetX();
	double GetY();
	void SetX(double x);
	void SetY(double y);
	//static void PrintCount();
	virtual void Move(Vector& v);
	virtual void Out();
	virtual double Area();
	bool operator< (const Vector& v1);
};
