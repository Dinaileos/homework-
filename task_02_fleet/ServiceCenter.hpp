#pragma once
#include <iostream>
#include <string>
#include "Inventory.hpp"
#include <memory>

class ServiceCentr {
public:
  void Inspect (const std::unique_ptr<InventoryItem>& item);
};
