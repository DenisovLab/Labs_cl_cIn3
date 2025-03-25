#include <iostream>
#include <conio.h>
#include <windows.h>

#include "Labs/Labs.hpp"
#include "Temp/temp.hpp"

using namespace std;

/* === Устанавливаем UTF-8 для консолей === */
void set_utf8() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

/* === Массивы задач === */
void (*Lab1_Tasks[])(int, int) = { Lab1::Task1, Lab1::Task2, Lab1::Task3 };
void (*Lab2_Tasks[])(int, int) = { Lab2::Task1, Lab2::Task2, Lab2::Task3 };
void (*Lab3_Tasks[])(int, int) = { Lab3::Task1, Lab3::Task2, Lab3::Task3 };
void (*Lab4_Tasks[])(int, int) = { Lab4::Task1, Lab4::Task2, Lab4::Task3 };

/* === Массив лабораторных === */
void (*(*Labs[]))(int, int) = { Lab1_Tasks, Lab2_Tasks, Lab3_Tasks, Lab4_Tasks };

string menuLabs[] = { "Лаб № 1", "Лаб № 2", "Лаб № 3", "Лаб № 4", "Х Выход" };
string menuTasks[] = { "Задача № 1", "Задача № 2", "Задача № 3", "< Назад" };

/* === Отображение меню === */
void menu(string title, string options[], int size, int selected) {
    system("cls");
    cout << "↑ ↓ - Перемещение | Enter - Выбор | Backspace - Назад\n\n";
    cout << title << "\n\n";

    for (int i = 0; i < size; i++) {
        if (i == selected) cout << " > " << options[i] << " <" << endl;
        else cout << "   " << options[i] << endl;
    }
}

/* === Меню выбора лабораторной === */
int select_option(string title, string options[], int size) {
    int selected = 0;
    char key;

    while (true) {
        menu(title, options, size, selected);
        key = _getch();

        switch (key) {
            case 72: // Стрелка вверх
                if (selected > 0) selected--;
                break;
            case 80: // Стрелка вниз
                if (selected < size - 1) selected++;
                break;
            case 13: // Enter
                return selected;
            case 8:  // Backspace
                return -1;
        }
    }
}

int main() {
    set_utf8();

    while (true) {
        int lab_ID = select_option("Выберите лабораторную", menuLabs, 5);
        if (lab_ID == 4 || lab_ID == -1) break; // Выход

        while (true) {
            int task_ID = select_option("Выберите задачу", menuTasks, 4);
            if (task_ID == 3 || task_ID == -1) break; // Назад

            system("cls");
            Labs[lab_ID][task_ID](lab_ID + 1, task_ID + 1);
        }
    }

    cout << "Выход из программы...\n";
    return 0;
}