#include "stdafx.h"
#include "MyVector.h"
#include <cmath>


Vector::Vector(double c1, double c2)
{
	x = c1;   y = c2;
	//Count++;
}

Vector::Vector()
{
	x = y = 0.;
	//Count++;
}


Vector::Vector(const Vector& copy)
{
	*this = copy;
	//Count++;
}

void Vector::Out()
{
	cout << "\nVector:  x = " << x << ",  y = " << y;
}

//====== ѕереопределение операций =====//
Vector& Vector::operator= (const Vector& v)	// ѕрисвоение
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;
	return *this;
}

Vector Vector::operator+(const Vector& new_v) {
	Vector v(this->x + new_v.x, this->y + new_v.y);
	return v;
}

Vector Vector::operator+(const double val)
{
	Vector p(this->x + val, this->y + val);
	return p;
}

Vector operator+(const double val, Vector& other)
{
	Vector p(other.x + val, other.y + val);
	return p;
}

double operator!(const Vector& v) {
	return(sqrt(v.x * v.x + v.y * v.y));
}


bool Vector::operator>(const Vector& v) {
	if (!(*this) > !v) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector::operator==(const Vector& v) const {

	if (!(*this) == !v) {
		return true;
	}
	else {
		return false;
	}

	/*if (fabs(this->x - v.x)< DBL_EPSILON && fabs(this->y - v.y) < DBL_EPSILON) {
		return true;
	}
	else {
		return false;
	}*/

}


//вектор*число
Vector Vector::operator*(const double val) {
	Vector v(this->x * val, this->y * val);
	return v;
}

//число*вектор
Vector operator*(const double val, Vector& vect) {
	Vector v(vect.x * val, vect.y * val);
	return v;
}

//вектор*вектор
double Vector::operator*(const Vector& vect) {
	double res = this->x * vect.x + this->y * vect.x;
	return res;
}

double Vector::GetX() {
	return x;
}

double Vector::GetY() {
	return y;
}

void Vector::SetX(double x) {
	this->x = x;
}

void Vector::SetY(double y) {
	this->y = y;
}

//void Vector::PrintCount() {
//	cout << "\n Now there are " << Count << " vectors";
//}

void Vector::Move(Vector& v) {
	x += v.GetX();
	y += v.GetY();
};

double Vector::Area() {
	return 0;
};

bool Vector::operator<(const Vector& v) {
	if (this->x < v.x && this->y < v.y) {
		return true;
	}
	else {
		return false;
	}
}