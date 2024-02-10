#include "CompanyWidget.h"
using namespace std;

CompanyWidget::CompanyWidget(Session& s, QWidget *parent)
	: QWidget(parent), session(s)
{
	ui.setupUi(this);
	this->session.registerObserver(this);
	this->update();
	ui.recipientLabel->setText(QString::fromStdString("Recipient"));
	ui.streetLabel->setText(QString::fromStdString("Street"));
	ui.numberLabel->setText(QString::fromStdString("Number"));
	ui.xLabel->setText(QString::fromStdString("X coordinate"));
	ui.yLabel->setText(QString::fromStdString("Y coordinate"));
	ui.addButton->setText(QString::fromStdString("Add"));
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &CompanyWidget::addPackage);
}

CompanyWidget::~CompanyWidget()
{
	this->session.unregisterObserver(this);
}

void CompanyWidget::update()
{
	ui.packagesListWidget->clear();
	vector<Package> packages = this->session.getPackages();
	for (auto pack : packages)
	{
		QListWidgetItem* it = new QListWidgetItem{ QString::fromStdString(pack.getString()) };
		if (pack.getStatus() == true)
			it->setBackground(QColor(Qt::green));
		ui.packagesListWidget->addItem(it);
	}
}

void CompanyWidget::addPackage()
{
	string recipient = ui.recipientLineEdit->text().toStdString();
	string street = ui.streetLineEdit->text().toStdString();
	string number = ui.numberLineEdit->text().toStdString();
	int xcor = stoi(ui.xLineEdit->text().toStdString());
	int ycor = stoi(ui.xLineEdit->text().toStdString());
	vector <string> address;
	address.push_back(street);
	address.push_back(number);
	vector<int> location;
	location.push_back(xcor);
	location.push_back(ycor);
	Package p(recipient, address, location, false);
	this->session.addPackage(p);
}
