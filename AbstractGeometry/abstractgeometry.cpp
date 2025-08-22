#include <iostream>
using namespace std;

enum Color
{
	Red = 0x000000FF,
	Green = 0x0000FF00,
	Blue = 0x00FF0000,
	Yellow = 0x0000FFFF,
	Orange = 0x0000A5FF,
	White = 0x00FFFFFF,
};


class Shape
{
	Color color;
public:
	Shape (Color color):color(color){/*“ело конструктора*/ }
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
	virtual void info()const
	{
		cout << "ѕлощадь фигуры: " << get_area() << endl;
		cout << "ѕериметр фигуры: " << get_perimeter() << endl;
		draw();
	}
};

class Square :public Shape
{
	double side;
public:
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		this->side = side;
	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimeter()const override
	{
		return 4 * side;
	}
	void draw()const override
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void info()const override
	{
		cout << typeid(*this).name() << endl;
		cout << "ƒлина стороны квадрата: " << get_side() << endl;
		Shape::info();
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::Red);

	Square square(5, Color::Red);
	cout << "ƒлина стороны квадрата: " << square.get_side() << endl;
	cout << "ѕлощадь квадрата: " << square.get_area() << endl;
	cout << "ѕериметр квадрата: " << square.get_perimeter() << endl;
	square.draw();
	cout << "\n-----------------------\n" << endl;
	square.info();
}

/*
ѕеречислени€ (enumerations)

ѕеречислени€ в €зыке C++ представл€ют собой набор целочисленных именнованых констант.  онстантам не€вно присваиваютс€ значени€ 0, 1, 2 и тд.
Ќо если €вно задать значение хот€ бы одной константы, то нумераци€ продолжитс€ с указанного значени€. явным образом значение можно задавать и каждой константе в перечислении.

ѕеречислени€, так же как классы и структуры, €вл€ютс€ пользовательскими типами данных, а переменные этих типов, могут принимать только значени€ указанные в перечислении
*/