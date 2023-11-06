#pragma once
#include "MyVector.h"
#include "Shape.h"
#include <iostream>

class Rect : public Shape
{
	Vector ptLT;
	Vector ptRB;
public:
	Rect(); //����������� �� ���������
	Rect(const Vector& v1, const Vector& v2); //����������� � �����������
	Rect(double c1, double c2, double c3, double c4); //����������� � �����������
	Rect(const Rect& copy); //����������� ����������
	Rect& operator= (const Rect& v); //����������
	virtual void Out();
	void Inflate(double delta = 1); //� ����� ���������� (�� ��������� = 1), ������� ������ ���������� ���� 4-� ������.
	void Inflate(double inflateleft, double inflateright, double inflatetop, double inflatebottom); //� 4-� ����������� (���������, ��������� �� ����� 4-� ������).
	void Inflate(double value_x, double value_y); //� 2-� ����������� (���������� ����� � ���������� ����-����).
	virtual void Move(Vector& v);
	virtual double Area();
	double Getx_lt();
	double Gety_lt();
	double Getx_rb();
	double Gety_rb();
	friend std::ostream& operator<<(std::ostream& out, Rect& rect);
	friend std::ostream& operator<<(std::ostream& os, Rect* rect);

};
