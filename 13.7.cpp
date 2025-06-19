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

    // 3. Находим первое и последнее отрицательные числа
    int firstNeg = 0, lastNeg = 0;
    bool foundFirstNeg = false;
    for (int num : numbers) {
        if (num < 0) {
            firstNeg = num;
            foundFirstNeg = true;
            break;
        }
    }
    if (!foundFirstNeg) {
        cerr << "Отрицательных чисел в файле нет." << endl;
        return 1;
    }
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        if (*it < 0) {
            lastNeg = *it;
            break;
        }
    }

    int factor = 2 * (firstNeg + lastNeg);

    // 4. Формируем выходной файл, умножая каждое третье число (индексы 2,5,8...) на factor
    ofstream foutOut(outputFile);
    if (!foutOut) {
        cerr << "Ошибка при создании выходного файла." << endl;
        return 1;
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        int outVal = numbers[i];
        if ((i + 1) % 3 == 0) { // каждое третье число, индексация с 1
            outVal *= factor;
        }
        foutOut << outVal << endl;
    }
    foutOut.close();

    cout << "Файлы успешно созданы. Проверьте '" << inputFile << "' и '" << outputFile << "'." << endl;

    return 0;
}