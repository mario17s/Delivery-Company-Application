#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Deliver.h"

class Deliver : public QMainWindow
{
    Q_OBJECT

public:
    Deliver(QWidget *parent = nullptr);
    ~Deliver();

private:
    Ui::DeliverClass ui;
};
