#pragma once

#include <QWidget>
#include "ui_CourierWidget.h"
#include "Courier.h"
#include "Session.h"
#include "Observer.h"

class CourierWidget : public QWidget, public Observer
{
	Q_OBJECT

public:
	CourierWidget(Courier c, Session& s, QWidget *parent = nullptr);
	~CourierWidget();
	void update() override;
	void populateCombo();
	void deliver();
	void enableDeliver();
	void drawMap();
private:
	Ui::CourierWidgetClass ui;
	Courier courier;
	Session& session;
	std::vector<std::string> allStreets;
	std::vector<Package> ownPackages;
};
