#pragma once
#include "MyVector.h"
#include "Shape.h"
#include <iostream>

class Rect : public Shape
{
	Vector ptLT;
	Vector ptRB;
public:
	Rect(); //конструктор по умолчанию
	Rect(const Vector& v1, const Vector& v2); //конструктор с параметрами
	Rect(double c1, double c2, double c3, double c4); //конструктор с параметрами
	Rect(const Rect& copy); //конструктор копировани§
	Rect& operator= (const Rect& v); //Њрисвоение
	virtual void Out();
	void Inflate(double delta = 1); //Ч одним параметром (по умолчанию = 1), который задает приращение всех 4-х границ.
	void Inflate(double inflateleft, double inflateright, double inflatetop, double inflatebottom); //Ч 4-м§ параметрами (приращени§, различные дл§ всенх 4-х границ).
	void Inflate(double value_x, double value_y); //Ч 2-м§ параметрами (приращение вширь и приращение ввер-вниз).
	virtual void Move(Vector& v);
	virtual double Area();
	double Getx_lt();
	double Gety_lt();
	double Getx_rb();
	double Gety_rb();
	friend std::ostream& operator<<(std::ostream& out, Rect& rect);
	friend std::ostream& operator<<(std::ostream& os, Rect* rect);

};
