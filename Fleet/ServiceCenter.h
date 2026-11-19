#pragma once
#include <iostream>
#include <string>
#include "Inventory.h"
#include <memory>

class ServiceCentr {
public:
  void Inspect (const std::unique_ptr<InventoryItem>& item);
};
