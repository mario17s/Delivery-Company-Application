#include "Deliver.h"
#include <QtWidgets/QApplication>
#include "Courier.h"
#include "Package.h"
#include "CompanyWidget.h"
#include "Session.h"
#include <fstream>
#include "CourierWidget.h"
#include <assert.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ifstream f("couriers.txt");
    Courier c;
    vector<Courier> couriers;
    while (f >> c)
        couriers.push_back(c);
    f.close();
    //assert(couriers.size() == 3);
    //assert(couriers.at(0).getStreets()[1] == "Garbau");
    //assert(couriers.at(1).getZone()[2] == 4);
    //assert(couriers.at(2).getStreets()[1] == "Horea");
    Session ses{ "packages.txt" };
    CompanyWidget* cww  = new CompanyWidget{ ses };
    cww->setWindowTitle(QString::fromStdString("courier company"));
    cww->show();
    for (auto courier : couriers)
    {
        CourierWidget* cw = new CourierWidget{ courier, ses };
        cw->setWindowTitle(QString::fromStdString(courier.getName()));
        cw->show();
    }
    return a.exec();
}
