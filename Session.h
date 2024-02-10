#pragma once
#include "Subject.h"
#include "Package.h"

class Session : public Subject {
private:
	std::vector<Package> packages;
	std::string filename;
public:
	Session(std::string fn) : filename{ fn } { this->readFromFile(); }
	~Session() { this->writeToFile(); }
	void addPackage(Package p) {
		this->packages.push_back(p);
		this->notify();
	}
	void deliverPackage(Package p) {
		for (int i = 0; i < this->packages.size(); i++)
			if (p.getREcipient() == this->packages[i].getREcipient())
				this->packages[i].setStatus();
		this->notify();
	}
	std::vector<Package>& getPackages() { return this->packages; }
private:
	void readFromFile();
	void writeToFile();
};