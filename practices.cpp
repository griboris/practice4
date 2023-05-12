/*Практическая 4(Файлы)
*Первый этап.
В рамках выполнения практической работы необходимо создать два файла с именами:
<фамилия>.txtи <фамилия>.bin– соответственно, записанные в текстовом и бинарном формате.
*Текстовый формат
1.      Записать 3 записи (три строки (records) из таблицы практики 0) в файл в текстовом формате.
2.      Считать 3 записи из файла в текстовом формате и отобразить.
3.      Просмотреть содержимое файла в текстовом редакторе и проанализировать результат.

*Бинарный формат
1.      Записать 3 записи (три строки (records) из таблицы практики 0) в файл в текстовом формате.
2.      Считать 3 записи из файла в текстовом формате и отобразить.
3.      Просмотреть содержимое файла в текстовом редакторе и проанализировать результат.
*Сравнить содержимое созданных файлов.
*Второй этап
Добавить новую запись (четвертую) в указанный существующий файл, вводя данные с клавиатуры.
Выполнить задание, согласно варианта в указанном файле, изменения сохраняются в файле.
*/
/*Поменять местами значения поля даты в 2 и 4 записях файла.
*Данные считываются из файла.
*Бинарный
*/

#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

struct Date {
	unsigned short int day;
	unsigned short int month;
	unsigned short int year;
};

struct Record {
	char name[20];
	char type;
	float cost;
	int min;
	struct Date data;
};

//ifstream in("grib.bin", ios_base::in);
//ofstream out("grib.bin", ios_base::binary);

void fout(Record *records, const char* filename) {
	ofstream file(filename, ios_base::binary); 
	for (int i = 0; i < 3; i++) {
		file << records[i].name << ", "
			<< records[i].type << ", "
			<< records[i].cost << ", "
			<< records[i].min << ", {"
			<< records[i].data.day << "."
			<< records[i].data.month << "."
			<< records[i].data.year << "}"
			<< endl;
	}
	file.close();
}

void fin(const char* filename) {
	ifstream ile(filename, ios_base::in);
	char str[100];
		while (ile.getline(str, 100)) 
			cout << str << endl;
		ile.close();
}

void swap(const char* filename) {
	ifstream in(filename, ios_base::in);
	ofstream out(filename, ios_base::in | ios_base::binary);
	char s1[100], s2[100], s3[100], s4[100];
	in.getline(s1, 100);
	in.getline(s2, 100);
	in.getline(s3, 100);
	in.getline(s4, 100);
	in.close();

	out << s1 << endl << s4 << endl << s3 << endl << s2;
	out.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[3], record;
	records[0] = { "Папка", 'К', 4.75000, 4, {03,07,2022} };
	records[1] = { "Бумага", 'К', 13.9, 10000, {03,04,2021} };
	records[2] = { "Калькулятор", 'О', 411.000, 1, {04,03,2022} };

	fout(records, "grib.bin");
	fin("grib.bin");

	ofstream out("grib.bin", ios_base::app);
	cin >> record.name
		>> record.type
		>> record.cost
		>> record.min
		>> record.data.day
		>> record.data.month
		>> record.data.year;
	out << record.name << ", "
		<< record.type << ", "
		<< record.cost << ", "
		<< record.min << ", {"
		<< record.data.day << "."
		<< record.data.month << "."
		<< record.data.year << "}"
		<< endl;
	out.close();
	fin("grib.bin");

	swap("grib.bin");
}