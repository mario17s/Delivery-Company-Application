#pragma once
#include <string>
#include <vector>
#include <tuple>

class Courier {
private:
	std::string name;
	std::vector<std::string> streets;
	std::vector<int> zone;
public:
	Courier(std::string n, std::vector<std::string> s, std::vector<int> z): name{n}, streets{s}, zone{z}{}
	Courier() = default;
	std::string getName() { return this->name; }
	std::vector<std::string> getStreets() { return this->streets; }
	std::vector<int> getZone() { return this->zone; }
	friend std::istream& operator>>(std::istream& is, Courier& c);
};