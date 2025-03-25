#include <windows.h>
#include <cstdlib>
#include <thread>
#include "temp.hpp"

using namespace std;

void printTask(int lab_N, int task_N, const string& task, const string& code, function<void()> solve) {
    cout << "=== ЛАБОРАТОРНАЯ № " << lab_N << ". ЗАДАЧА № " << task_N << " ===\n";
    cout << task << endl;

    cout << "\n=== РЕШЕНИЕ: ===";
    cout << code << endl;

    cout << "\n=== ВЫВОД: ===" << endl;
    solve();

    cout << "\n<< УСПЕШНО ЗАВЕРШЕНО. >>" << endl;
    cout << "\nНажмите Enter, чтобы вернуться в меню задач...\n";

    cin.ignore();
    cin.get();
}