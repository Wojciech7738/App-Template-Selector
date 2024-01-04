#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Utils/macros.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listModel = new QStringListModel(this);
    ui->listView->setModel(listModel);
    ui->listView->editTriggers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::get_filename(std::string& file_path) {
    return QString::fromStdString(file_path.substr(file_path.find_last_of(PATH_SEP) + 1));
}

void MainWindow::write_data(std::vector<std::tuple<std::string, std::vector<std::string>>> dir_contents) {
    dir_tree = dir_contents;
    std::transform(dir_tree.begin(), dir_tree.end(), std::back_inserter(list_of_templates),
                   [](const auto& tuple) { return std::get<0>(tuple); });
    add_templates_to_list();
}

void MainWindow::add_templates_to_list() {
    QStringList data;
    for (const auto& template_name : list_of_templates) {
        const QString str = QString::fromStdString(template_name);
        data << str;
    }
    set_list_view_data(data);
}

void MainWindow::set_list_view_data(const QStringList& data)
{
    listModel->setStringList(data);
}

void MainWindow::on_pushButton_clicked()
{
    bool files_has_been_saved = true;
    QString destinationFilePath;
    std::string single_file_path = "";
    // File dialog for choosing the destination location
    QString destinationDirectoryPath = QFileDialog::getExistingDirectory(
        this, "Choose Destination Location", QDir::homePath());

    // Check if the user selected a location
    if (!destinationDirectoryPath.isEmpty()) {
        // Save all files from vector
        for (const auto& file_path : selected_template_files_paths) {
            QString filename = get_filename((std::string&)file_path);
            destinationFilePath = destinationDirectoryPath + PATH_SEP + filename;
            // Create QFile objects
            QFile sourceFile(QString::fromStdString(file_path));
            QFile destinationFile(destinationFilePath);

            // Check if opening files was successful
            if (sourceFile.open(QIODevice::ReadOnly) && destinationFile.open(QIODevice::WriteOnly)) {
                // Copy data
                QByteArray data = sourceFile.readAll();
                destinationFile.write(data);

                // Close files
                sourceFile.close();
                destinationFile.close();
            } else {
                // Set error flag
                files_has_been_saved = false;
                single_file_path = file_path;
                break;
            }
        }
        if (files_has_been_saved) {
            // Show success message
            QMessageBox::information(this, "Success", "File(s) copied successfully.");
        }
        else {
            // Show error message
            QString error_message = QString::fromStdString("Failed to copy the file \"" + single_file_path + "\".");
            QMessageBox::critical(this, "Error", error_message);
        }
    }
}

void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    static int previous_index = -1;
    int idx = index.row();
    if (previous_index != idx) {
        // Get the first file path assigned to given template.
        std::vector<std::string> files;
        files = std::get<std::vector<std::string>>(dir_tree.at(idx));
        selected_template_files_paths = files;
        current_template_file_index = 0;
        previous_index = idx;
        // Generate view of the first file
        show_file_preview(files.at(current_template_file_index));
        // Enable the button if there is more than one file in directory
        if (selected_template_files_paths.size() > 1) {
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_3->setDisabled(true);
        } else {
            ui->pushButton_4->setDisabled(true);
            ui->pushButton_3->setDisabled(true);
        }
    }
}

void MainWindow::show_file_preview(std::string& file_path) {
    QFile file(QString::fromStdString(file_path));
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "info", file.errorString());
    }
    QTextStream input_stream(&file);
    ui->textBrowser->setText(input_stream.readAll());
    // Set label text on file name
    ui->label->setText(get_filename(file_path));
}

// Show next file from the vector
void MainWindow::on_pushButton_4_clicked()
{
    current_template_file_index++;
    show_file_preview(selected_template_files_paths.at(current_template_file_index));
    ui->pushButton_3->setEnabled(true);
    if (current_template_file_index == selected_template_files_paths.size() - 1)
        ui->pushButton_4->setDisabled(true);
}

// Show previous file from the vector
void MainWindow::on_pushButton_3_clicked()
{
    current_template_file_index--;
    show_file_preview(selected_template_files_paths.at(current_template_file_index));
    ui->pushButton_4->setEnabled(true);
    if (current_template_file_index == 0)
        ui->pushButton_3->setDisabled(true);
}

