#include "Point.h"

//конструктор по умолчанию
Point::Point()
{
	x = 0;
	y = 0;
}

//конструктор с параметрами
Point::Point(int x1, int y1)
{
	x = x1;
	y = y1;
}

//конструктор копирования
Point::Point(const Point& other)
{
	x = other.x;
	y = other.y;
}

//геттеры
int Point::GetX() const
{
	return x;
}
int Point::GetY() const
{
	return y;
}

void Point::SetX(int x) {
	this->x = x;
}

void Point::SetY(int y) {
	this->y = y;
}

ostream& operator<<(ostream& out, const Point& point)
{
	out << "x = " << point.x << " y = " << point.y;
	return out;
}

ostream& operator<<(ostream& out, const Point* point) {
	out << "x = " << point->x << " y = " << point->y;
	return out;
}

bool Point::operator<(const Point& A) const
{
	if (this->x < A.x && this->y < A.y)
	{
		return true;
	}
	else { return false; }
}

bool Point::operator==(const Point& A) const
{
	return (x == A.x && y == A.y);
}

bool Point::operator!=(const Point& A)
{
	return !(x == A.x && y == A.y);
}
