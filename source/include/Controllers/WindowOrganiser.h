#ifndef WINDOWORGANISER_H
#define WINDOWORGANISER_H

#pragma once

#include <string>
#include <vector>
#include <QApplication>
#include <QVBoxLayout>
#include "Views/LangSelectWindow.h"
#include "../mainwindow.h"


class WindowOrganiser
{
public:
    WindowOrganiser();
    ~WindowOrganiser();
    void run(int argc, char** argv);
private:
    std::string show_lang_select_window(const std::string& window_name, const std::string& window_title, std::vector<std::string> languages, int argc, char** argv);
    void show_main_window(const std::string& window_name, const std::string& window_title, int argc, char** argv, std::string selected_language, std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents);
};

#endif
