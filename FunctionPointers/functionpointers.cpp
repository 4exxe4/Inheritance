#include <iostream>
using namespace std;

const char* Hello()
{
	return "Hello";
}

int Add(int a, int b)
{
	return a + b;
}

int Substract(int a, int b)
{
	return a - b;
}
template<typename T>
int Calculate(int a, int b, T (*operation)(int, int))
{
	return (*operation)(a, b);
}

double Div(int a, int b)
{
	return (double)a / b;
}

void main()
{
	setlocale(LC_ALL, "");
	cout << Hello() << endl;
	const char* (*pHello)() = Hello;
	cout << (*pHello)() << endl;
	////////////////////////////
	/*
	int(*pAdd)(int, int) = Add;
	int(*pSubstract)(int, int) = Substract;

	cout << (*pAdd)(2, 3) << endl;
	cout << (*pSubstract)(8, 3) << endl;
	*/
	
	cout << Calculate(8, 3, Add) << endl;
	cout << Calculate(8, 3, Substract) << endl;
	cout << Calculate(8, 3, Div) << endl;
}

/*
Указатели на функцию:
Имя функции является указателем на функцию, поскольку содержит адрес функции в памяти.

Указатель функции можно сохранить в обычную переменную и вызывать функцию через эту переменную.

Для того, чтобы в указателе на функицю сохранить адресс функции - у функции и у указателя должны быть одинаковые прототипы (списки принимаемых параметров). В противном случае возникает ошибка на этапе компиляции.

//////////////////////////////////////////////////////

Синтаксис объявления указателя на функцию:

type function (parameters)
{
   ....;
   group of statements;
   ....;
}

type (*name)(parameters) = function;

type - тип возвращаемого значения;
function - имя функции;
name - имя указателя на функцию;
parameters - список принимаемых параметров;

Тип возвращаемого значения и список принимаемых параметров у самой функции и указателя на нее должны быть идентичными
*/