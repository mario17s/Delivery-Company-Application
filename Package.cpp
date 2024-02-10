#include "Package.h"
#include <sstream>
using namespace std;

std::istream& operator>>(std::istream& is, Package& p)
{
    // TODO: insert return statement here
    string line;
    getline(is, line);
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ';'))
        tokens.push_back(token);
    if (tokens.size() != 4)
        return is;
    p.recipient = tokens[0];
    stringstream addStream(tokens[1]);
    string elem;
    p.address.clear();
    while (getline(addStream, elem, ','))
        p.address.push_back(elem);
    stringstream locStream(tokens[2]);
    string coord;
    p.location.clear();
    while (getline(locStream, coord, ','))
        p.location.push_back(stoi(coord));
    if (tokens[3] == "false" or tokens[3] == "0")
        p.status = false;
    else if (tokens[3] == "true" or tokens[3] == "1")
        p.status = true;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Package& p)
{
    // TODO: insert return statement here
    os << p.recipient << ";";
    for (int i = 0; i < p.address.size(); i++)
    {
        os << p.address[i];
        if (i != p.address.size() - 1)
            os << ",";
    }
    os << ";";
    for (int i = 0; i < p.location.size(); i++)
    {
        os << p.location[i];
        if (i != p.location.size() - 1)
            os << ",";
    }
    os << ";" << p.status << "\n";
    return os;
}

std::string Package::getString()
{
    string pack = "";
    pack = pack + this->recipient + ";";
    for (int i = 0; i < this->address.size(); i++)
    {
        pack = pack + this->address[i];
        if (i != this->address.size() - 1)
            pack = pack + ",";
    }
    pack = pack + ";";
    for (int i = 0; i < this->location.size(); i++)
    {
        pack = pack + to_string(this->location[i]);
        if (i != this->location.size() - 1)
            pack = pack +  ",";
    }
    if(this->status == true)
        pack = pack + ";" + "true";
    else
        pack = pack + ";" + "false";
    return pack;
}
