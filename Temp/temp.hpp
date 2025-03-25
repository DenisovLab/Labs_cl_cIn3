#ifndef TEMP_HPP
#define TEMP_HPP

#include <iostream>
#include <functional>
#include <string>

void printTask(int lab_N, int task_N, const std::string& task, const std::string& code, std::function<void()> solve);

#endif // TEMP_HPP
