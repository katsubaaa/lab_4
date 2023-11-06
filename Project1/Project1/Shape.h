#pragma once
class Vector;
class Shape {
	int x;
	static int Count;
public:
	static Shape* shapes[1000];
	Shape();
	~Shape();
	virtual void Move(Vector& v) = 0;
	virtual void Out() = 0;
	virtual double Area() = 0;
	static void PrintCount();
	static int GetCount();
};