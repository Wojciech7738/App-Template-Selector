#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void writeData(std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents);

private:
    Ui::MainWindow *ui;
    QStringListModel *listModel;
    std::vector<std::string> list_of_templates;
    std::vector<std::tuple<std::string, std::vector<std::string>>> dir_tree;
    void addTemplatesToList();
    void setListViewData(const QStringList& data);
};
#endif // MAINWINDOW_H
