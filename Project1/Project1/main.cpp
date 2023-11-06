// ���������� STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//���������. ����������� ���������. ���������.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include<stack>
#include<queue>
#include "Point.h"
#include "MyString.h"
#include "stdafx.h"
#include "Shape.h"
#include "MyVector.h"
#include "Rect.h"
using namespace std;

int Shape::Count = 0;
Shape* Shape::shapes[1000] = { 0 };
//============= ������ ������� ��� ������ � ������� ���������
template <class T> void pr(T& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";

	// �������� ������ ����������
	typename T::iterator p;
	int i;

	for (p = v.begin(), i = 0; p != v.end(); p++, i++)
		cout << endl << i + 1 << ". " << *p; //��������� ��������, �� ������� ��������� ��������
	cout << '\n';
}



template <class T> void print(T& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";
	int i = 0;
	while (!v.empty()) {
		cout << i + 1 << ". " << v.top() << endl; //toptop
		v.pop();
		i++;
	}
	cout << '\n';
}


template <class T> void print(queue<T>& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";
	int i = 0;
	while (!v.empty()) {
		cout << i + 1 << ". " << v.front() << endl;
		v.pop();
		i++;
	}
	cout << '\n';
}


bool compare(const int& a, const int& b) {
	return a > b;
};



class compareStr {
public:
	bool operator() (const char* item1, const char* item2)
	{
		if (strcmp(item1, item2) > 0)
			return true;
		return false;
	}
};

template <class T> void print_el(const T& v)
{
	cout << v << "\n";
}

template <typename T>
class change_el
{
	int x;
	int y;
public:
	change_el(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void operator()(T& obj) {
		obj.SetX(x);
		obj.SetY(y);
	}
};

bool Pred1_1(const Point& obj) {
	int n = -10;
	int m = 5;
	if (obj.GetX() >= n && obj.GetX() <= m && obj.GetY() >= n && obj.GetY() <= m) {
		return true;
	}
	else {
		return false;
	}
}

bool compare_len(Rect& r1, Rect& r2) {
	double len_a_r1 = (r1.Getx_lt() - r1.Getx_rb()) / 2;
	double len_b_r1 = (r1.Gety_lt() - r1.Gety_rb()) / 2;
	double len_a_r2 = (r2.Getx_lt() - r2.Getx_rb()) / 2;
	double len_b_r2 = (r2.Gety_lt() - r2.Gety_rb()) / 2;
	double res1 = sqrt(len_a_r1 * len_a_r1 + len_b_r1 * len_b_r1);
	double res2 = sqrt(len_a_r2 * len_a_r2 + len_b_r2 * len_b_r2);
	return res1 < res2;
}

string transformation(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	//������� � ����� ������� - ��������� deque
	//Deque ������������ ������������� �������.

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������

	deque<Point> deq1;
	vector<Point> vect1(10, Point(1, 2));
	deq1.assign(vect1.begin(), vect1.end());
	pr(deq1, "deque_1");

	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'
	deque<MyString> deq2;
	MyString str1("hello");
	MyString str2("Adhnsiofojwej");
	MyString str3("world");
	MyString str4("gjivv");
	MyString str5("asdskidfsfhi");
	deq2.push_back(str1);

	deq2.push_front(str2);
	deq2.push_front(str3);
	deq2.insert(deq2.end(), str4);
	deq2.push_back(str5);

	pr(deq2, "deque_2");

	auto it = remove_if(deq2.begin(), deq2.end(), [](MyString str) {
		return (str.GetString()[0] == 'A' || str.GetString()[0] == 'a');
		});
	deq2.erase(it, deq2.end());

	pr(deq2, "deque_2 after erase");
	////////////////////////////////////////////////////////////////////////////////////

	/*����� std::queue<T> ������������ ������� - ���������,
	������� �������� �� �������� FIFO(first - in first - out ��� "������ ����� � ������ �����")
	� ������ ������ ����������� ������ ����������� �������.

	����� std::stack<T> ������������ ���� - ���������,
	������� �������� �� �������� LIFO (last-in first-out ��� "��������� ����� � ������ �����")
	� ������ ������ ����������� ��������� ����������� �������.

	����� std::priority_queue<T> ������������ ������� ����������� - ���������,
	�������, ��� � ����������� �������, �������� �� �������� FIFO.
	*/

	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//���������, ��� "��������" ������ "� ��������"?
	//��� ���������� � ������������ ����� ������ ��������? // ���������, ���� �������� �� ������ � �������
	stack<int> stack1; //�� �������� top ����� ����� ������������� ��������� ����������� ������� 
	for (int i = 0; i < 10; i++) {
		stack1.push(i);
	}

	queue<int> queue1; //�� ����� �������� ������ ����� ������ ������� ������� - ��� ����� ����������� ������� front() � � ����� ��������� � ������� ������� back()
	for (int i = 0; i < 10; i++) {
		queue1.push(i);
	}

	priority_queue<int> priority_queue1; //��� ������ ������������ ���������(1��) ��������� ����������
	for (int i = 0; i < 10; i++) {
		priority_queue1.push(i);
	}

	print(stack1, "stack_1");
	print(queue1, "queue_1");
	print(priority_queue1, "priority_queue_1");

	////////////////////////////////////////////////////////////////////////////////////
	//stack
	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 
	stack<int> stack_2;
	vector<int> vector_1;
	for (int i = 0; i < 10; i++) {
		vector_1.push_back(i);
	}

	for (int i = 0; i < vector_1.size(); i++) {
		stack_2.push(vector_1[i]);
	}

	sort(begin(vector_1), end(vector_1), compare);
	pr(vector_1, "vector_1");
	print(stack_2, "stack_2");


	//��������� � ����������� ������
	//�) �������� ���� � ����� �������� ������� �������� ���������
	//�) �������� ����� ���� ����� �������, ����� �� ���� ������ �������
	//�) �������� ����� �� ���������
	//�) ������������� ����� �� ������ ����� ������� (push, pop, top)
	//�) ���������, ����� �� ������ ������ (���������, ����� ����� ������������ � ����� ���������)
	{
		stack<int> stack_3;
		for (int i = 0; i < 10; i++) {
			stack_3.push(i);
		}
		stack<int> stack_4 = { stack_3 };

		//print(stack_3, "stack_3");
		//print(stack_4, "stack_4");

		if (stack_3 == stack_4) {
			cout << "stacks are equal\n";
		}
		else {
			cout << "stacks are unequal\n";
		}

		stack_4.pop();
		stack_4.push(-1);
		stack_4.top() = -123;

		//��������� ����� ��������� ������ ������������ �� �������� ��������� ��������� ���� �������. ��������� ��������� ������ ���� �������� ���������.
		if (stack_3 > stack_4) {
			cout << "stack_3 is bigger than stack_4\n";
		}
		else {
			cout << "stack_4 is bigger than stack_3\n";
		}
		stop
	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?  
	{
		Point* p_1 = new Point(1, 1);
		Point* p_2 = new Point(2, 2);
		Point* p_3 = new Point(3, 3);
		Point* p_4 = new Point(4, 4);
		Point* p_5 = new Point(5, 5);
		queue<Point*, deque<Point*>>queue_2;
		queue_2.push(p_1);
		queue_2.push(p_2);
		queue_2.push(p_3); //push_back

		queue_2.front() = p_4;
		queue_2.back() = p_5;

		print(queue_2, "queue_2");

		for (int i = 0; i < queue_2.size(); i++) {
			delete queue_2.front();
			queue_2.pop();
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?  -----������������ ������� � ������� ��� ������� compareStr, ���������� �� ��������
	{
		const char* mas[5] = { "hello","sir","manera","krutit","mir" };
		priority_queue<const char*, vector<const char*>, compareStr> priority_queue2;
		for (int i = 0; i < 5; i++) {
			priority_queue2.push(mas[i]);
		}

		print(priority_queue2, "priority_queue_2");
		stop
	}


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������) ------------------- ���������� ���������� �������� bool operator<(const Point& A) const;
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������... ----------- ������, ��� ������ ������
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������   
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?) //��������� ������ ������ �������� ������ ���� ���

	/*���������(set) ������������ ����� ���������,
	������� ����� ������� ������ ���������� ��������.
	��� �������, ��������� ����������� ��� �������� ���������, ������� �� ������ ����� ����������.*/
	set<Point> set_1;
	for (int i = 0; i < 10; i++) {
		set_1.insert(Point(i, i));
	}
	pr(set_1, "set_1");

	//������ ������, ������� ����� ���������, ��� ��������� ������������� ��������.�� ��������� �������� ������������� �� �����������.
	set<int> set_2;
	for (int i = 0; i < 10; i++) {
		set_2.insert(i);
	}

	set<int> set_3;
	for (int i = 9; i >= 0; i--) {
		set_3.insert(i);
	}

	int mas_int[10] = { 10,10,20,20,30,40,40,40,40,40 };
	for (int i = 0; i < 10; i++) {
		set_2.insert(mas_int[i]);
	}
	pr(set_2, "set_2");
	pr(set_3, "set_3");



	////////////////////////////////////////////////////////////////////////////////////
	//multiset - ���������������, ��������� �������
	multiset<int> multiset_1;
	for (int i = 0; i < 10; i++) {
		multiset_1.insert(mas_int[i]);
	}
	pr(multiset_1, "multiset_1");



	////////////////////////////////////////////////////////////////////////////////////
	//map	
	// ����� ��� std::map ������������ ���������, ��� ������ �������� ������������� � ������������ ������.
	// � �� ����� ����� ����� �������� �������. ������ ����� ����� ����� ������ ���������� ��������. 
	// �������� ������ ���������� ����� ������� �������, ��� ������� ����� �������������� ��� ������� ��� ����������. 
	// ������� ����� ��������� ��� �������� ���������.

	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������
	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
	cout << endl;

	map<const char*, int> map_1;
	map_1["��������"] = 34000;
	map_1.insert(pair<const char*, int>("�������", 10000));
	map_1["���������"] = 200000;
	map_1.insert(pair<const char*, int>("���������", 30000));

	cout << "\nmap_1" << endl;
	for (const auto& element : map_1) {
		cout << element.first << "\t" << element.second << endl;
	}

	int tmp = map_1["�������"];
	map_1["�������"] = tmp;
	map_1.erase("�������");

	cout << "\nmap_1 after changes" << endl;
	for (const auto& element : map_1) {
		cout << element.first << "\t" << element.second << endl;
	}
	stop

		////////////////////////////////////////////////////////////////////////////////////
		//multimap
		//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
		//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
		//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
		//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
		//�) �������� ��� ���������� ������� �� �����
		//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
		//		���������� ����� ������������ ������ lower_bound() � upper_bound()

		multimap<string, string> multimap_1;
	vector<pair<string, string>> pairs = {
		make_pair("strange", "��������"),
		make_pair("strange", "�����"),
		make_pair("way", "����"),
		make_pair("way", "������"),
		make_pair("fly", "������"),
		make_pair("fly", "����")
	};

	for (int i = 0; i < pairs.size(); i++) {
		multimap_1.insert(pairs[i]);
	}
	//����� ����� �������
	cout << "\nmultimap_1" << endl;
	for (auto itr = multimap_1.begin(); itr != multimap_1.end(); itr++) {
		cout << itr->first << "\t" << itr->second << endl;
	}

	//lower_bound function returns an iterator pointing to the first element in a sorted range that is not less than a given value.
	cout << "\ntranslations for \"strange\"" << endl;
	multimap<string, string>::iterator iter = multimap_1.lower_bound("strange");
	//p = multimap_1.equal_range("strange"); //Returns a range containing all elements with the given key in the container.
	while (iter != multimap_1.upper_bound("strange"))
	{
		std::cout << iter->second << "  ";
		iter++;
	}


	///////////////////////////////////////////////////////////////////

		//���������

		//����������� ���������. ����������� set<Point>. ���������, ���
		//����� ����������� � ������ Point. �������� ������, �������� �������� 
		//�������� ������� ��������� set, �� ����������� �� ��������
	set<Point> set_4;
	for (int i = 0; i < 10; i++) {
		set_4.insert(Point(i, i));
	}
	vector<Point> vector_2;
	for (set<Point>::reverse_iterator iter = set_4.rbegin(); iter != set_4.rend(); iter++) {
		vector_2.push_back(*iter);
	}
	pr(set_4, "set_4");
	pr(vector_2, "vector_2");


	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
	ostream_iterator<Point> out_iter(cout, "\n");
	cout << "\nset_4" << endl;
	for (auto el : set_4) {
		*out_iter++ = el;
	}
	cout << "\nvector_2" << endl;
	for (auto el : vector_2) {
		*out_iter++ = el;
	}
	//��������� �������. � ������� ������������ ���������:
	//back_inserter()
	//front_inserter()
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.

	//� ����������� ���������� C++ �������� ������ ��������� �� ���� �� ���� ����������� �������������������, ������� ������� - ���� push: deque Class, list Class ��� vector Class.
	back_inserter(vector_2) = Point(-2, -4);
	//One of the pitfalls of std::front_inserter is that it can be used with only those containers that have push_front as one of its methods like in case of list and deque,
	// and it cannot be used with vectors.
	//front_inserter(vector_2) = Point(100, 100); -- ������

	inserter(set_4, set_4.begin()) = Point(-100, -100);
	inserter(vector_2, vector_2.begin()) = Point(-10, -20);
	pr(set_4, "set_4");
	pr(vector_2, "vector_2");
	///////////////////////////////////////////////////////////////////

		//���������� ��������� (������������ ���� <algorithm>). ���������.

		// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
		//(������, vector, list...)
		//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
		//������������ �������� ���������
		//��������� : ������� ���������� ������� ���������� ��� ������
	cout << endl;
	for_each(vector_2.begin(), vector_2.end(), print_el<Point>);



	stop

		//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
		//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
		//��� ������) � �������� ��������� � ������� ����������� ���������
		cout << endl;
	for_each(vector_2.begin(), vector_2.end(), change_el<Point>(1, 1));
	for_each(vector_2.begin(), vector_2.end(), print_el<Point>);

	vector_2.push_back(Point(4, 4));
	vector_2.push_back(Point(-1, -1));
	cout << endl;
	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.
	vector<Point>::iterator itt = vector_2.begin();
	int count = 0;
	while (itt != vector_2.end()) {
		if (itt == find(itt, vector_2.end(), Point(0, 0))) {
			cout << *itt << endl;
			count++;
		}
		itt++;
	}
	cout << "count: " << count << endl;



	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	sort(vector_2.begin(), vector_2.end());
	pr(vector_2, "vector_2 after sort");
	list<Point> list_n;
	for (int i = 10; i >= 0; i--) {
		list_n.push_back(Point(i, i));
	}
	pr(list_n, "list_n");
	list_n.sort();
	pr(list_n, "list_n after sort");


	//�������� ���������� ������� ����: bool Pred1_1(const Point& ), ������� ����� ����������
	//���������� find_if(), ��������� � �������� ��������� ��������� ������� ������������������.
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].

	vector<Point>::iterator iter_i = vector_2.begin();
	vector<Point>::iterator iter_point = vector_2.begin();
	while (iter_i != vector_2.end()) {
		iter_point = find_if(vector_2.begin(), vector_2.end(), Pred1_1);
		iter_i++;
	}
	pr(vector_2, "vector_2");

	cout << "\nanswer: " << *iter_point << endl;


	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.

	Rect r1(2, 10, 20, 11);
	Rect r2(3, 5, 10, 7);
	Rect r3(8, 12, 11, 3);
	vector<Rect> rect_vect{ r1,r2,r3 };

	/*for (int i = 0; i < 10; i++) {
		rect_vect.push_back(Rect(Vector(i+1,i+2), Vector(i,i)));
	}*/
	pr(rect_vect, "rect_vect");

	sort(rect_vect.begin(), rect_vect.end(), compare_len);
	pr(rect_vect, "rect_vect after sort");



	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()


		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
		list<string> list_str{ string("Barbie"),string("KEn"),string("CAR") };
		set<string> set_str;
		insert_iterator<set<string>> tr_iter(set_str, set_str.begin()); //�������� �������
		transform(list_str.begin(), list_str.end(), tr_iter, transformation);

		pr(list_str, "before transformation");
		pr(set_str, "after transformation");
		stop
	}
	{// map

		//����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������

		//��� std::map ���������� �������, ������� ��������������� ��� ���� �������� - �� ��������� � ������� ����������� ������. 
		vector<string> vect{ string("Barbie"),string("KEn"),string("CAR"),string("Barbie"),string("KEn"),string("Asd") };
		map<string, int> mapp;
		for (int i = 0; i < vect.size(); i++) {
			mapp[vect[i]]++;
		}

		cout << "\nmapp:" << endl;
		for (const auto& element : mapp) {
			cout << element.first << "\t" << element.second << endl;
		}
	}
	return 0;
}
