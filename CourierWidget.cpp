#include "CourierWidget.h"
#include <cmath>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include "qpainter.h"

using namespace std;

CourierWidget::CourierWidget(Courier c, Session& s, QWidget *parent)
	: QWidget(parent), courier{c}, session{s}
{
	ui.setupUi(this);
	ui.fixedEdit->setText(QString::fromStdString(to_string(courier.getZone()[0]) + " " + to_string(courier.getZone()[1]) + " " + to_string(courier.getZone()[2])));
	this->session.registerObserver(this);
	ui.deliverButton->setText(QString::fromStdString("Deliver"));
	ui.deliverButton->setEnabled(false);
	ui.mapButton->setText(QString::fromStdString("Map"));
	this->update();
	vector<Package> packages = this->session.getPackages();
	for (auto p : packages)
	{
		string street = p.getAddress()[0];
		bool found = false;
		for (auto st : this->allStreets)
			if (st == street)
				found = true;
		if (!found)
			this->allStreets.push_back(street);
	}
	for (auto street : this->allStreets)
	{
		ui.comboBox->addItem(QString::fromStdString(street));
	}
	QObject::connect(ui.comboBox, &QComboBox::currentIndexChanged, this, &CourierWidget::populateCombo);
	QObject::connect(ui.deliverButton, &QPushButton::clicked, this, &CourierWidget::deliver);
	QObject::connect(ui.undeliveredListWidget, &QListWidget::clicked, this, &CourierWidget::enableDeliver);
	QObject::connect(ui.mapButton, &QPushButton::clicked, this, &CourierWidget::drawMap);
}

CourierWidget::~CourierWidget()
{
	this->session.unregisterObserver(this);
}

void CourierWidget::update()
{
	ui.undeliveredListWidget->clear();
	vector<Package> packages = this->session.getPackages();
	for (auto p : packages)
		if(p.getStatus() == false)
	{
			//ui.undeliveredListWidget->addItem(QString::fromStdString(p.getString()));
			int courierX = courier.getZone()[0];
			int courierY = courier.getZone()[1];
			int packageX = p.getLocation()[0];
			int packageY = p.getLocation()[1];
			double distance = sqrt((packageX - courierX) * (packageX - courierX) + (packageY - courierY) * (packageY - courierY));
			
			string street = p.getAddress()[0];
			bool found = false;
			for (auto stree : courier.getStreets())
				if (stree == street)
					found = true;
			if (found == true || distance < courier.getZone()[2])
			{
				ui.undeliveredListWidget->addItem(QString::fromStdString(p.getString()));
				ownPackages.push_back(p);
			}
	}
		
}

void CourierWidget::populateCombo()
{
	int index = ui.comboBox->currentIndex();
	string street = this->allStreets[index];
	QWidget* w = new QWidget{};
	QHBoxLayout* layy = new QHBoxLayout{};
	QListWidget* packk = new QListWidget{};

	vector<Package> packages = this->session.getPackages();
	for (auto p : packages)
		if (p.getAddress()[0] == street)
			packk->addItem(QString::fromStdString(p.getString()));

	layy->addWidget(packk);
	w->setLayout(layy);
	w->setVisible(true);
}

void CourierWidget::deliver()
{
	QModelIndexList lst = ui.undeliveredListWidget->selectionModel()->selectedIndexes();
	int index = lst[0].row();
	Package p = ownPackages[index];
	this->session.deliverPackage(p);
}

void CourierWidget::enableDeliver()
{
	ui.deliverButton->setEnabled(true);
}

void CourierWidget::drawMap()
{
	QWidget* mapp = new QWidget{};
	QPainter* painter = new QPainter{};
	mapp->setVisible(true);
	//painter->drawRect(0, 0, 50, 50);
	//QPaintEvent* event = new QPaintEvent{painter};
	//mapp->paintEvent(painter);
}
