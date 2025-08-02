#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE

	//1) Создание потока:
	std::ofstream fout;
	//2) Открытие потока:
	//fout.open("File.txt");                    //Поток открытый таким образом всегда будет перезаписывать файл.
	fout.open("File.txt", std::ios_base::app);  //Append - добавить в конец
	//3)Запись в поток:
	fout << "Hello Files" << endl;
	//4)Потоки обязательно нужно закрывать:
	fout.close();

	system("notepad File.txt");

#endif // WRITE_TO_FILE

	//1) Создаем и открываем поток:
	std::ifstream fin("File.txt");

	//2) Проверяем, открылся ли поток:
	if (fin.is_open())
	{
		//3) Чтение из файла:
		while (!fin.eof()) //EndOfFile
		{
			std::string buffer;
			//fin >> buffer;
			std::getline(fin, buffer);
			cout << buffer << endl;
		}
		
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}

	//?) Закрываем поток:
	fin.close();
}
/*
Работа с файлами

Для работы с файлами так же, как и для вывода на экран и ввода с клавиатуры, используются потоки.

Для вывода на экран используется поток "cout", а для вывода или записи в файл используется поток "fout"
Точно так же, как для ввода с клавиатуры используется поток "cin", для ввода или чтения из файла используется поток "fin"

"cout" является объектом класса "std::ostream", а "fout" - "std::ofstream"
"cin" является объектом класса "std::istream", а "fin" - "std::ifstream"

Классы "std::ostream" и "std:istream" объявлены в заголовочном файле "iostream"
Классы "std::ofstream" и "std:iftream" объявлены в заголовочном файле "fstream", который обязательно нужно подключать для работы с файлами

Единственным отличием между потоками "cin", "cout" и файловыми потоками "fin", "fout", является то, что первые - это уже раннее созданные существующие объекты, а вторые - программист должен создать самостоятельно.
Это связано с тем, что консоль и клавиатура - одна, а файлов может быть сколько угодно и расположены они могут быть где угодно.
*/