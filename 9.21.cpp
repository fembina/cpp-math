#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string swapParts(const string& word) {
    size_t dashPos = word.find('-');
    
    if (dashPos == string::npos) {
        // Дефис не найден, возвращаем слово без изменений
        return word;
    }

    // Части до и после дефиса
    string firstPart = word.substr(0, dashPos);
    string secondPart = word.substr(dashPos + 1);

    // Меняем местами части
    return secondPart + "-" + firstPart;
}

int main() {
    string line;

    cout << "Введите строку: ";
    getline(cin, line);

    stringstream ss(line);
    string word;
    string result;

    while (ss >> word) {
        result += swapParts(word) + " ";
    }

    // Убираем лишний пробел в конце
    if (!result.empty()) {
        result.pop_back();
    }

    cout << "Результат: " << result << endl;

    return 0;
}