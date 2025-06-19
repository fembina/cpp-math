#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // для rand()
#include <ctime> // для time()

using namespace std;

int main() {
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";
    const int count = 20;
    const int minVal = -10;
    const int maxVal = 10;

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned>(time(nullptr)));

    // 1. Формируем входной файл с 20 случайными числами от -10 до 10
    ofstream fout(inputFile);
    if (!fout) {
        cerr << "Ошибка при создании входного файла." << endl;
        return 1;
    }

    for (int i = 0; i < count; i++) {
        int num = minVal + rand() % (maxVal - minVal + 1);
        fout << num << endl;
    }
    fout.close();

    // 2. Читаем числа из входного файла в вектор
    ifstream fin(inputFile);
    if (!fin) {
        cerr << "Ошибка при открытии входного файла." << endl;
        return 1;
    }

    vector<int> numbers;
    int val;
    while (fin >> val) {
        numbers.push_back(val);
    }
    fin.close();

    if (numbers.empty()) {
        cerr << "Входной файл пуст." << endl;
        return 1;
    }

    // Получаем последнее число из файла
    int lastNumber = numbers.back();

    // 3. Формируем выходной файл, прибавляя к каждому числу последнее число файла
    ofstream foutOut(outputFile);
    if (!foutOut) {
        cerr << "Ошибка при создании выходного файла." << endl;
        return 1;
    }

    for (int num : numbers) {
        foutOut << (num + lastNumber) << endl;
    }
    foutOut.close();

    cout << "Файлы успешно созданы. Проверьте '" << inputFile << "' и '" << outputFile << "'." << endl;

    return 0;
}