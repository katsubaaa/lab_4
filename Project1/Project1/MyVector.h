#pragma once
#include "Shape.h"
class Vector :public Shape
{
private:
	double x, y;	//  оординаты вектора на плоскости
	//static int Count;
public:
	//========== “ри конструктора
	Vector(double c1, double c2);
	Vector(); // Default
	Vector(const Vector& copy);
	//====== ѕереопределение операций =====//
	Vector& operator= (const Vector& v);	// ѕрисвоение
	Vector operator+(const Vector&); //вектор+вектор
	Vector operator+(const double val); //вектор+число
	friend Vector operator+(const double, Vector&); //число+вектор
	friend double operator!(const Vector& v); //длина вектора
	bool operator>(const Vector& v);
	bool operator==(const Vector& v) const;
	double operator*(const Vector&); //вектор*вектор
	Vector operator*(const double val); //вектор*число
	friend Vector operator*(const double, Vector&); //число*вектор
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
