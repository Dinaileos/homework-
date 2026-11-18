#include "Transport.hpp"
#include <string>

EBike::EBike(std::string id, std::string name, double daily_energy, long score)
: id_(id), name_(name), daily_energy_(daily_energy), score_(score) {}

std::string EBike::GetId() const {
  return id_;
}

std::string EBike::GetName() const{
  return name_;
}

double EBike::GetDailyEnergy() const {
  return daily_energy_;
}

long EBike::GetScore() const {
  return score_;
}

Scooter::Scooter(std::string id, std::string name, double daily_energy, long score)
: id_(id), name_(name), daily_energy_(daily_energy), score_(score) {}

std::string Scooter::GetId() const {
  return id_;
}

std::string Scooter::GetName() const {
  return name_;
}

double Scooter::GetDailyEnergy() const {
  return daily_energy_;
}

long Scooter::GetScore() const {
  return score_;
}

Bike::Bike(std::string id, std::string name, double daily_energy, long score)
: id_(id), name_(name), daily_energy_(daily_energy), score_(score) {}

std::string Bike::GetId() const {
  return id_;
}

std::string Bike::GetName() const {
  return name_;
}

double Bike::GetDailyEnergy() const {
  return daily_energy_;
}

long Bike::GetScore() const {
  return score_;
}

Monocycle::Monocycle(std::string id, std::string name, double daily_energy, long score)
: id_(id), name_(name), daily_energy_(daily_energy), score_(score) {}

std::string Monocycle::GetId() const {
  return id_;
}

std::string Monocycle::GetName() const {
  return name_;
}

double Monocycle::GetDailyEnergy() const {
  return daily_energy_;
}

long Monocycle::GetScore() const {
  return score_;
}
