#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";
    const int count = 20;
    const int minVal = -10;
    const int maxVal = 10;

    srand(static_cast<unsigned>(time(nullptr)));

    // 1. Формируем входной файл с 20 случайными числами от -10 до 10
    ofstream fout(inputFile);
    if (!fout) {
        cerr << "Ошибка при создании входного файла." << endl;
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        int num = minVal + rand() % (maxVal - minVal + 1);
        fout << num << endl;
    }
    fout.close();

    // 2. Считываем числа из входного файла
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

    // 3. Находим сумму и количество положительных чисел
    int positiveSum = 0;
    int positiveCount = 0;
    for (int num : numbers) {
        if (num > 0) {
            positiveSum += num;
            positiveCount++;
        }
    }

    if (positiveCount == 0) {
        cerr << "Положительных чисел в файле нет." << endl;
        return 1;
    }

    double positiveAverage = static_cast<double>(positiveSum) / positiveCount;

    // 4. Формируем выходной файл, заменяя каждое положительное число на среднее арифметическое
    ofstream foutOut(outputFile);
    if (!foutOut) {
        cerr << "Ошибка при создании выходного файла." << endl;
        return 1;
    }

    for (int num : numbers) {
        if (num > 0) {
            foutOut << positiveAverage << endl;
        } else {
            foutOut << num << endl;
        }
    }
    foutOut.close();

    cout << "Файлы успешно созданы. Проверьте '" << inputFile << "' и '" << outputFile << "'." << endl;

    return 0;
}
