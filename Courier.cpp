#include "Courier.h"
#include <sstream>
using namespace std;

std::istream& operator>>(std::istream& is, Courier& c)
{
    // TODO: insert return statement here
    string line;
    getline(is, line);
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ';'))
        tokens.push_back(token);
    if (tokens.size() != 3)
        return is;
    c.name = tokens[0];
    stringstream streetsStream(tokens[1]);
    string street;
    c.streets.clear();
    while (getline(streetsStream, street, ','))
        c.streets.push_back(street);
    stringstream zoneStream(tokens[2]);
    string number;
    c.zone.clear();
    while (getline(zoneStream, number, ','))
        c.zone.push_back(stoi(number));
    return is;
}
