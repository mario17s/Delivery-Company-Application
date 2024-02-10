#pragma once
#include "Observer.h"
#include <vector>

class Subject {
private:
	std::vector<Observer*> observers;
public:
	void registerObserver(Observer* o) { this->observers.push_back(o); }
	void unregisterObserver(Observer* o) {
		this->observers.erase(std::find(this->observers.begin(), this->observers.end(), o));
	}
	void notify() {
		for (auto obs : this->observers)
			obs->update();
	}
};