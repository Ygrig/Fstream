#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void file_insert(string path, int pos, string str);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	string path = "file.txt"; //создаем путь

	//Класс fstream
	/*fstream file; //создаем объект
	file.open(path, ios::in | ios::app); //объединяем с пом-ю битового ИЛИ (| ) 2 режима - Ин и Аут, чтобы не возникало ошибки при открытии файла. Потом аут поменяли на апп, чтобы проверить запись новых записей без стирания предыдущих
	if (file.is_open()) { //проевряем, удалось ли открыть файл
		cout << "Файл открыт.\n";
		//Запись в файл
		file << "Bye world!\n";
		cout << "Данные записаны.\n";

		file.seekg(0, ios::beg); //перемещение курсора для считывания в начало файла 

		//Считывание из файла
		cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			cout << sym;


	}
	else
		cout << "Ошибка открытия файла.\n";

	file.close();
	*/
	
	//Задание "Запись в файл"
	/*cout << "Введите строку: ";
	string str;
	getline(cin, str);
	cout << "Введите позицию: ";
	cin >> n;
	file_insert(path, n, str);
	*/

	//Задача 1. Дата из файла
	ifstream in;
	in.open("Date.txt");
	if (in.is_open()) {
		int day, month, year;

		string tmp;
		getline(in, tmp);

		day = stoi(tmp.substr(0, tmp.find('.')));
		cout << "День: " << day << '\n';

		month = stoi(tmp.substr(tmp.find('.') + 1));
		cout << "Месяц: " << month << '\n';

		year = stoi(tmp.substr(tmp.rfind('.')+1));
		cout << "Год: " << year << '\n';
	}
	else
		cout << "Ошибка открытия файла.\n\n";

	in.close();

	return 0;
}

void file_insert(string path, int pos, string str) {
	
	// Шаг 1. Копируем содержимое файла в строку tmp
	ifstream in;
	in.open(path); //просто path, не указ-м иос, тк для ифстрим по умолччанию миетод ИН
	string tmp;
	
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			tmp += sym;
	}

	in.close();

	//cout << tmp; //промежуточный вывод
	
	// Шаг 2. Вставляем содержимое str в строку tmp
	tmp.insert(pos, str);

	//Шаг 3. Заменяем содержимое файла на строку tmp
	ofstream out;
	out.open(path); //метод по умолчанию аут
	if (out.is_open()) {
		out << tmp;
		out.close();
	} 

}