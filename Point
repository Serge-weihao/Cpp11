#include <iostream>
#include <cmath>
using namespace std;

class Point {	//Point类定义
public:
	Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}
	Point(const Point &p);
	int getX() { return x; }
	int getY() { return y; }
private:
	int x, y;
};

Point::Point(const Point &p) {	//拷贝构造函数的实现
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor of Point" << endl;
}

//类的组合
class Line {	//Line类的定义
public:	//外部接口
	Line(Point xp1, Point xp2);
	Line(Line &l);
	double getLen() { return len; }
private:	//私有数据成员
	Point p1, p2;	//Point类的对象p1,p2
	double len;
};

//组合类的构造函数
Line::Line(Point xp1, Point xp2)  {
	cout << "Calling constructor of Line" << endl;
	Point p1(xp1);
	Point p2(xp2);
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);
}

//组合类的拷贝构造函数
Line::Line (Line &l): p1(l.p1), p2(l.p2) {
	cout << "Calling the copy constructor of Line" << endl;
	len = l.len;
}
void Show(Point p)
{
    cout<<p.getX()<<p.getY()<<endl;
}
Point Move(Point xy)
{
    Point a(xy.getX()+1,xy.getY());
    return a;
}
//主函数
int main() {
	Point myp1(1, 1), myp2(4, 5);	//建立Point类的对象
	cout<<endl;
	Line line(myp1, myp2);	//建立Line类的对象
	cout<<endl;
	Line line2(line);	//利用拷贝构造函数建立一个新对象
	cout << "The length of the line is: ";
	cout << line.getLen() << endl;
	cout << "The length of the line2 is: ";
	cout << line2.getLen() << endl;
	Show(myp2);
	Point move = Move(myp2);
	return 0;
}
