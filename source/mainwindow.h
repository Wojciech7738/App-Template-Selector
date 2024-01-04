#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QFileDialog>
#include <QMessageBox>

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
    void write_data(std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents);

private slots:
    void on_pushButton_clicked();
    void on_listView_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *listModel;
    int current_template_file_index;
    std::vector<std::string> selected_template_files_paths;
    std::vector<std::string> list_of_templates;
    std::vector<std::tuple<std::string, std::vector<std::string>>> dir_tree;
    void add_templates_to_list();
    void set_list_view_data(const QStringList& data);
    void show_file_preview(std::string& file_path);
    QString get_filename(std::string& file_path);
};
#endif // MAINWINDOW_H
