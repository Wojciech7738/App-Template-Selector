#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listModel = new QStringListModel(this);
    ui->listView->setModel(listModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeData(std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents) {
    dir_tree = dir_contents;
    std::transform(dir_tree.begin(), dir_tree.end(), std::back_inserter(list_of_templates),
                   [](const auto& tuple) { return std::get<0>(tuple); });
    addTemplatesToList();
}

void MainWindow::addTemplatesToList() {
    QStringList data;
    for (const auto& template_name : list_of_templates) {
        const QString str = QString::fromStdString(template_name);
        data << str;
    }
    setListViewData(data);
}

void MainWindow::setListViewData(const QStringList& data)
{
    listModel->setStringList(data);
}
