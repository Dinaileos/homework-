#pragma once
#include "Inventory.h"


class Helmet : public InventoryItem {
private:
  std::string id_;
  std::string name_;

public:
  Helmet(std::string id, std::string name);

  std::string GetId() const override;
  std::string GetName() const override;
};

class Dock : public InventoryItem, public EnergyConsumer {
private:
  std::string id_;
  std::string name_;
  double daily_energy_;
public:
  Dock(std::string id, std::string name, double daily_energy);

  std::string GetId() const override;
  std::string GetName() const override;
  double GetDailyEnergy() const override;
};
