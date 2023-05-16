#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Получаем текущую дату в формате DD.MM.YYYY
  time_t today = time(nullptr);
  char buffer[13];
  strftime(buffer, sizeof(buffer), "%d.%m.%Y", localtime(&today));

  // Открываем файл для записи
  ofstream outfile("file.txt");
  if (outfile) {
    // Записываем текущую дату в файл
    outfile << buffer << endl;

    // Закрываем файл
    outfile.close();

    // Открываем файл для чтения
    ifstream infile("file.txt");
    if (infile) {
      string line;
      // Читаем строку из файла с помощью getline()
      getline(infile, line);

      // Выводим строку на экран
      cout << "getline(): " << line << endl;

      // Чтение строки из файла с помощью оператора >>
      infile >> line;

      // Выводим строку на экран
      cout << ">>: " << line << endl;

      // Закрываем файл
      infile.close();

    } else {
      cerr << "Error opening file" << endl;
    }
  } else {
    cerr << "Error opening file" << endl;
  }

  return 0;
}