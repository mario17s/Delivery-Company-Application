#pragma once
#include <string>
#include <vector>

class Package {
private:
	std::string recipient;
	std::vector<std::string> address;
	std::vector<int> location;
	bool status;
public:
	Package(std::string r, std::vector<std::string> a, std::vector<int> l, bool s) : recipient{ r }, address{ a }, location{ l }, status{ s } {}
	Package() = default;
	std::string getREcipient() { return this->recipient; }
	std::vector<std::string> getAddress() { return this->address; }
	std::vector<int> getLocation() { return this->location; }
	bool getStatus() { return this->status; }
	void setStatus() { this->status = true; }
	friend std::istream& operator>>(std::istream& is, Package& p);
	friend std::ostream& operator<<(std::ostream& os, const Package& p);
	std::string getString();
};