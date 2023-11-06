#pragma once
#include <iostream>
using namespace std;
class Point
{
	int x, y;
public:
	Point();
	Point(int, int);
	Point(const Point&);
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	friend ostream& operator<<(ostream& out, const Point& point);
	friend ostream& operator<<(ostream& os, const Point* point);
	bool operator<(const Point& A) const;
	bool operator==(const Point& A) const;
	bool operator!=(const Point& A);
};
