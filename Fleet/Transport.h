#include "Inventory.h"
#include <string>

class EBike : public InventoryItem, public EnergyConsumer {
private:
  std::string id_;
  std::string name_;
  double daily_energy_;
  long score_;
public:
  EBike(std::string id, std::string name, double daily_energy, long score);

  std::string GetId() const override;
  std::string GetName() const override;
  double GetDailyEnergy() const override;
  long GetScore() const override;
};

class Scooter : public InventoryItem, public EnergyConsumer {
private:
  std::string id_;
  std::string name_;
  double daily_energy_;
  long score_;
public:
  Scooter(std::string id, std::string name, double daily_energy, long score);

  std::string GetId() const override;
  std::string GetName() const override;
  double GetDailyEnergy() const override;
  long GetScore() const override;
};

class Bike : public InventoryItem, public EnergyConsumer {
private:
  std::string id_;
  std::string name_;
  double daily_energy_;
  long score_;
public:
  Bike(std::string id, std::string name, double daily_energy, long score);

  std::string GetId() const override;
  std::string GetName() const override;
  double GetDailyEnergy() const override;
  long GetScore() const override;
};

class Monocycle : public InventoryItem, public EnergyConsumer {
  std::string id_, name_;
  double daily_energy_;
  long score_;
public:
  Monocycle(std::string id, std::string name, double energy, long score);

  std::string GetId() const override;
  std::string GetName() const override;
  double GetDailyEnergy() const override;
  long GetScore() const override;
};
