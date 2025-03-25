#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Labs.hpp"
#include "../Temp/temp.hpp"

using namespace std;

string commonTask = R"(
>> Общая постановка задачи:
Разработать функцию, возвращающее значение с одним параметром.
Вызывать функцию четыре раза :
    1) первый раз - параметр должен передаваться константой;
    2) второй раз – выражением;
    3) третий – случайным значением;
    4) четвертый - входной параметр должен вводится пользователем.

>> Задача:
)";

namespace Lab1 {

    double calc(int x) {
        double rad = x * M_PI / 180.0;
        double result = tan(2 * rad) + sin(2 * rad);
        return result; 
    }


    void Task1(int lab_N, int task_N) {
        const string task = commonTask + "Реализовать функцию, которая возвращает результат вычисления выражения tg2x + sin2x";

        const string code = R"(
    double calc(int x) {
        double rad = x * M_PI / 180.0;
        double result = tan(2 * rad) + sin(2 * rad);
        return result; 
    }

    int main() {
    int x1 = 6;
    cout << "1. Константа: " << x1 << endl;
    cout << "Результат при константе: " << calc(x1) << endl;

    int x2 = 6 + 5 * 2;
    cout << "\n2. Параметр выражением 6 + 5 * 2: " << x2 << endl;
    cout << "Результат при выражении: " << calc(x2) << endl;

    srand(time(0));
    int x3 = rand() % 10 + 1;
    cout << "\n3. Случайное значение: " << x3 << endl;
    cout << "Результат при случайном значении: " << calc(x3) << endl; 

    int x4;
    cout << "\n4. Введите x: ";
    while (!(cin >> x4)) {
        cout << "Ошибка! Введите корректное число: ";
        cin.clear(); // Сбрасываем флаг ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Результат при введённом значении: " << calc(x4) << endl;
    }
        )";

        auto solve = function<void()>([]() {
            int x1 = 6;
            cout << "1. Константа: " << x1 << endl;
            cout << "Результат при константе: " << calc(x1) << endl;

            int x2 = 6 + 5 * 2;
            cout << "\n2. Параметр выражением 6 + 5 * 2: " << x2 << endl;
            cout << "Результат при выражении: " << calc(x2) << endl;

            srand(time(0));
            int x3 = rand() % 10 + 1;
            cout << "\n3. Случайное значение: " << x3 << endl;
            cout << "Результат при случайном значении: " << calc(x3) << endl; 

            int x4;
            cout << "\n4. Введите x: ";
            while (!(cin >> x4)) {
                cout << "Ошибка! Введите корректное число: ";
                cin.clear(); // Сбрасываем флаг ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Результат при введённом значении: " << calc(x4) << endl; 
        });

        printTask(lab_N, task_N, task, code, solve);

    }

    void Task2(int lab_N, int task_N) {
        const string task = "Составить программу и трассировку программы вычисления суммы элементов последовательности. (Трассировка – проверка  алгоритма с помощью пошагового вычисления. В отчете рассчитать 3 итерации цикла). Использовать цикл do..while. Выполнить письменно пошаговую компиляцию (трассировку) программы, путем составления таблицы для первых четырех итераций алгоритма решения задачи. 1, 4, 8, 16, 32, ... 256.";
        const string code = R"(
            
        )";

        auto solve = function<void()>([]() {
            
            });

        printTask(lab_N, task_N, task, code, solve);
    }

    void Task3(int lab_N, int task_N) {
        const string task = "Вычислить Y=√(sin(x)+√(sin(2x)+...+√(sin(98x)+√(sin(99x))))). Выполнить письменно пошаговую компиляцию (трассировку) программы, путем составления таблицы для первых четырех итераций алгоритма решения задачи.";
        const string code = R"(
        
        )";

        auto solve = function<void()>([]() {
            
            });

        printTask(lab_N, task_N, task, code, solve);
    }
}