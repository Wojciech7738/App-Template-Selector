#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *layout;

public:
    std::string selected_language = "";
    Widget(QWidget *parent = nullptr);
    QVBoxLayout* create_buttons_from_vector(std::vector<std::string>& list);
    ~Widget();
};
#endif // WIDGET_H
