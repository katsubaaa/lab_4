#include "Shape.h"
#include "stdafx.h"

Shape::Shape() {
	shapes[Count] = this;
	Count++;
}

Shape::~Shape() {
	Count--;
	//переписываем массив адресов, сдвигаем все объекты после удаленного на 1
	bool flag = false;
	for (int i = 0; i < Count; i++) {
		if (shapes[i] == this) {
			flag = true;
		}
		if (flag) {
			shapes[i] = shapes[i + 1];
		}
	}
}

void Shape::PrintCount() {
	//x++;
	cout << "\n Now there are " << Count << " vectors";
}

int Shape::GetCount() {
	return Count;
}