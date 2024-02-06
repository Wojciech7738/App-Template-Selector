#ifndef WINDOWORGANISER_H
#define WINDOWORGANISER_H

#pragma once

#include <string>
#include <vector>
#include <QApplication>
#include <QVBoxLayout>
#include "../mainwindow.h"
#include "Views/LangSelectWindow.h"
#include "Models/IJsonReaderWriter.h"
#include "Models/ReaderWriterFactory.h"
#include "Utils/pathvalidator.h"
#include "Utils/globals.h"


class WindowOrganiser
{
public:
    WindowOrganiser();
    ~WindowOrganiser();
    int scan_for_templates();
    void show_Gui();
private:
    std::vector<std::string> languages;
    std::vector<std::tuple<std::string, std::vector<std::tuple<std::string, std::vector<std::string>>>>> languages_tree;
    std::string show_lang_select_window(const std::string& window_name, const std::string& window_title, std::vector<std::string> languages);
    void show_main_window(const std::string& window_name, const std::string& window_title, std::string selected_language, std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents);
    std::vector<std::tuple<std::string, std::vector<std::string>>> get_dir_contents(const std::string& lang);
};

#endif
