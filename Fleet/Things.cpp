#include "Things.h"
#include <iostream>

Helmet::Helmet(std::string id, std::string name)
: id_(id), name_(name) {}

std::string Helmet::GetId() const {
  return id_;
}

std::string Helmet::GetName() const {
  return name_;
}

Dock::Dock(std::string id, std::string name, double daily_energy)
: id_(id), name_(name), daily_energy_(daily_energy) {}

std::string Dock::GetId() const {
  return id_;
}

std::string Dock::GetName() const {
  return name_;
}

double Dock::GetDailyEnergy() const {
  return daily_energy_;
}

