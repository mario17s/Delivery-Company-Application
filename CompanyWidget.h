#pragma once

#include <QWidget>
#include "ui_CompanyWidget.h"
#include "Session.h"

class CompanyWidget : public QWidget, public Observer
{
	Q_OBJECT

public:
	CompanyWidget(Session& s, QWidget *parent = nullptr);
	~CompanyWidget();
	void update() override;
	void addPackage();
private:
	Ui::CompanyWidgetClass ui;
	Session& session;
};
