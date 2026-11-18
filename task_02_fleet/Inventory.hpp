#pragma once
#include <string>


class InventoryItem {
public:
  virtual std::string GetId() const = 0;
  virtual std::string GetName() const = 0;
  virtual long GetScore() const { return 0; }
  virtual ~InventoryItem() = default;
};

class EnergyConsumer {
public:
  virtual double GetDailyEnergy() const = 0;
  virtual ~EnergyConsumer() = default;
};
