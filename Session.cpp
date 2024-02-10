#include "Session.h"
#include <fstream>

using namespace std;

void Session::readFromFile()
{
    ifstream fo(this->filename);
    Package p;
    while (fo >> p)
        this->packages.push_back(p);
    fo.close();
}

void Session::writeToFile()
{
    ofstream fout(this->filename);
    for (auto p : this->packages)
        fout << p;
    fout.close();
}
