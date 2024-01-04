#include <QPushButton>
#include <QVBoxLayout>
#include "Views/LangSelectWindow.h"

// TODO: refactor the code in order to apply Factory pattern

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{}

QVBoxLayout* Widget::create_buttons_from_vector(std::vector<std::string>& list) {
    layout = new QVBoxLayout;
    for (const auto &language : list) {
        QPushButton *button = new QPushButton(QString::fromStdString(language));
        layout->addWidget(button);
        QObject::connect(button, &QPushButton::clicked, [=, this]() {
            // Code executed when the button is clicked
            selected_language = language.c_str();
            Widget::close();
        });
    }
    return layout;
}

Widget::~Widget() {
    delete layout;
}
