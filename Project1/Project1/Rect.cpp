#include "Rect.h"
#include "stdafx.h"


//конструктор по умолчанию
Rect::Rect() : ptLT(0, 0), ptRB(0, 0) {
}

//конструктор с параметрами
Rect::Rect(const Vector& v1, const Vector& v2) : ptLT(v1), ptRB(v2) {
}

Rect::Rect(double l, double r, double t, double b) : ptLT(l, t), ptRB(r, b) {
}

// ѕрисвоение
Rect& Rect::operator= (const Rect& rect) {
	if (this == &rect)
		return *this;
	this->ptLT = rect.ptLT;
	this->ptRB = rect.ptRB;
	return *this;
}

//конструктор копировани€
Rect::Rect(const Rect& copy) {
	*this = copy;
}

void Rect::Out() {
	cout << "\nRect (" << ptLT.GetX() << "," << ptLT.GetY() << "," << ptRB.GetX() << "," << ptRB.GetY() << ")";
}

double Rect::Getx_lt() {
	return ptLT.GetX();
}

double Rect::Gety_lt() {
	return ptLT.GetY();
}

double Rect::Getx_rb() {
	return ptRB.GetX();
}

double Rect::Gety_rb() {
	return ptRB.GetY();
}

//увеличивает размеры пр€моугольника на заданные приращени€
void Rect::Inflate(double inflateleft, double inflateright, double inflatetop, double inflatebottom)
{
	ptLT.SetX(ptLT.GetX() - inflateleft);
	ptLT.SetY(ptLT.GetY() + inflatetop);
	ptRB.SetX(ptRB.GetX() + inflateright);
	ptRB.SetY(ptRB.GetY() - inflatebottom);
}

void Rect::Inflate(double value_x, double value_y) {
	this->Inflate(value_x, value_x, value_y, value_y); //чтобы избежать повторени€ кода, вызовем уже существующую ф-ю
}


void Rect::Inflate(double delta) {
	this->Inflate(delta, delta, delta, delta);
}

double Rect::Area() {
	double Square = fabs((ptLT.GetX() - ptRB.GetX()) * (ptLT.GetY() - ptRB.GetY()));
	return Square;
}

void Rect::Move(Vector& v) {
	this->Inflate(v.GetX(), v.GetX(), v.GetY(), v.GetY()); //чтобы избежать повторени€ кода, вызовем уже существующую ф-ю
}

ostream& operator<<(ostream& out, Rect& rect)
{
	out << "x_lt: " << rect.Getx_lt() << " y_lt: " << rect.Gety_lt() << "\tx_rb: " << rect.Getx_rb() << " y_rb: " << rect.Gety_rb();
	return out;
}

ostream& operator<<(ostream& out, Rect* rect) {
	out << "x_lt: " << rect->Getx_lt() << " y_lt: " << rect->Gety_lt() << "\tx_rb: " << rect->Getx_rb() << " y_rb: " << rect->Gety_rb();
	return out;
}