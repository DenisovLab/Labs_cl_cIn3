#include <iostream>
#include <cmath>
#include <cctype>
#include "Labs.hpp"
#include "../Temp/temp.hpp"

using namespace std;

namespace Lab3 {
    void Task1(int lab_N, int task_N) {
        const string task = "Вычислить  сумму целых чисел кратных 4 в интервале от 0 до 80. Решить 3-мя способами: оператор цикла for; оператор цикла do..while; оператор цикла while. Выполнить письменно пошаговую компиляцию (трассировку) программы, путем составления таблицы для первых четырех итераций алгоритма решения задачи.";
        const string code = R"(
        int sum_for = 0, sum_while = 0, sum_do_while = 0;

        cout << "- Цикл for:\n";
        for (int i = 0, iter = 1; i <= 80; i += 4, iter++){
            if (iter <= 4){
                cout << "Итерация " << iter << ": i = " << i << ", sum = " << sum_for << " + " << i;
            }
            sum_for += i;
            if (iter <= 4){
                cout << " -> sum = " << sum_for << endl;
            }
        }
        cout << "Сумма цикла for (последняя итерация): " << sum_for << endl;

        cout << "- Цикл while:\n";
        int i = 0, iter = 1;
        while (i <= 80){
            if (iter <= 4){
                cout << "Итерация " << iter << ": i = " << i << ", sum = " << sum_while << " + " << i;
            }
            sum_while += i;
            if (iter <= 4){
                cout << " -> sum = " << sum_while << endl;
            }
            i +=4;
            iter++;
        }
        cout << "Сумма цикла while (последняя итерация): " << sum_while << endl;

        cout << "- Цикл do_while:\n";
        i = 0, iter = 1;
        do {
            if (iter <= 4){
                cout << "Итерация " << iter << ": i = " << i << ", sum = " << sum_do_while << " + " << i;
            }
            sum_do_while += i;
            if (iter <= 4){
                cout << " -> sum = " << sum_do_while << endl;
            }
            i +=4;
            iter++;
        } while (i <= 80);
        cout << "Сумма цикла do_while (последняя итерация): " << sum_do_while << endl;
        )";

        auto solve = function<void()>([]() {
            int sum_for = 0, sum_while = 0, sum_do_while = 0;

            cout << "- Цикл for:\n";
            for (int i = 0, iter = 1; i <= 80; i += 4, iter++) {
                if (iter <= 4) {
                    cout << "Итерация " << iter << ": i = " << i << ", sum = " << sum_for << " + " << i;
                }
                sum_for += i;
                if (iter <= 4) {
                    cout << " -> sum = " << sum_for << endl;
                }
            }
            cout << "Сумма цикла for (последняя итерация): " << sum_for << endl;

            cout << "- Цикл while:\n";
            int i = 0, iter = 1;
            while (i <= 80) {
                if (iter <= 4) {
                    cout << "Итерация " << iter << ": i = " << i << ", sum = " << sum_while << " + " << i;
                }
                sum_while += i;
                if (iter <= 4) {
                    cout << " -> sum = " << sum_while << endl;
                }
                i += 4;
                iter++;
            }
            cout << "Сумма цикла while (последняя итерация): " << sum_while << endl;

            cout << "- Цикл do_while:\n";
            i = 0, iter = 1;
            do {
                if (iter <= 4) {
                    cout << "Итерация " << iter << ": i = " << i << ", sum = " << sum_do_while << " + " << i;
                }
                sum_do_while += i;
                if (iter <= 4) {
                    cout << " -> sum = " << sum_do_while << endl;
                }
                i += 4;
                iter++;
            } while (i <= 80);
            cout << "Сумма цикла do_while (последняя итерация): " << sum_do_while << endl;
            });

        printTask(lab_N, task_N, task, code, solve);
    }

    void Task2(int lab_N, int task_N) {
        const string task = "Составить программу и трассировку программы вычисления суммы элементов последовательности. (Трассировка – проверка  алгоритма с помощью пошагового вычисления. В отчете рассчитать 3 итерации цикла). Использовать цикл do..while. Выполнить письменно пошаговую компиляцию (трассировку) программы, путем составления таблицы для первых четырех итераций алгоритма решения задачи. 1, 4, 8, 16, 32, ... 256.";
        const string code = R"(
            int sum = 0, a = 2, iter = 1;

            cout << "Трассировка (первые 3 итерации):\n";

            do{
                if (iter <= 3){
                    cout << "Итерация " << iter << ": Текущее число = " << a << ", Сумма до = " << sum << ", Сумма после = " << sum + a; endl;
                }
                sum += a;
                a *= 2;
                iter++;
            } while (a <= 256)

            cout << "\nОбщая сумма: " << sum << endl;
        )";

        auto solve = function<void()>([]() {
            int sum = 0, a = 2, iter = 1;

            cout << "Трассировка (первые 3 итерации):\n";

            do {
                if (iter <= 3) {
                    cout << "Итерация " << iter << ": Текущее число = " << a << ", Сумма до = " << sum << ", Сумма после = " << sum + a << endl;
                }
                sum += a;
                a *= 2;
                iter++;
            } while (a <= 256);

            cout << "\nОбщая сумма: " << sum << endl;
            });

        printTask(lab_N, task_N, task, code, solve);
    }

    void Task3(int lab_N, int task_N) {
        const string task = "Вычислить Y=√(sin(x)+√(sin(2x)+...+√(sin(98x)+√(sin(99x))))). Выполнить письменно пошаговую компиляцию (трассировку) программы, путем составления таблицы для первых четырех итераций алгоритма решения задачи.";
        const string code = R"(
        double x;

        while (true) {
            cout << "Введите x: ";
            cin >> x;

            double result = 0;
            bool error = false;

            for (int i = 99; i >= 1; i--) {
                double sinValue = sin(i * x);
                double prevResult = result;

                if (sinValue + result < 0) {
                    cout << "Ошибка: попытка извлечь корень из отрицательного числа на i = " << i << ". Введите другое x.\n";
                    error = true;
                    break;
                }

                result = sqrt(sinValue + result);

                if (i >= 96) {
                    cout << "Итерация: " << 100 - i << " i = " << i
                        << " Значение синуса = " << sinValue
                        << " Предыдущий результат = " << prevResult
                        << " Текущее значение Y = " << result << endl;
                }
            }

            if (!error) {
                cout << "\nКонечный результат (последняя итерация): Y = " << result << endl;
                break;
            }
        }
        )";

        auto solve = function<void()>([]() {
            double x;

            while (true) {
                cout << "Введите x: ";
                cin >> x;

                double result = 0;
                bool error = false;

                for (int i = 99; i >= 1; i--) {
                    double sinValue = sin(i * x);
                    double prevResult = result;

                    if (sinValue + result < 0) {
                        cout << "Ошибка: попытка извлечь корень из отрицательного числа на i = " << i << ". Введите другое x.\n";
                        error = true;
                        break;
                    }

                    result = sqrt(sinValue + result);

                    if (i >= 96) {
                        cout << "Итерация " << 100 - i << ": i = " << i
                            << " Значение синуса = " << sinValue
                            << " Предыдущий результат = " << prevResult
                            << " Текущее значение Y = " << result << endl;
                    }
                }

                if (!error) {
                    cout << "\nКонечный результат (последняя итерация): Y = " << result << endl;
                    break;
                }
            }

            });

        printTask(lab_N, task_N, task, code, solve);
    }
}