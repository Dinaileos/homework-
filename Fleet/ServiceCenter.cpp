#pragma once
#include <iostream>
#include <string>
#include "Inventory.h"
#include "ServiceCenter.h"
#include "Errors.h"
#include <memory>

void ServiceCentr::Inspect (const std::unique_ptr<InventoryItem>& item) {
  if (item == nullptr) return;
  std::string string = item->GetName();
  for (char& letter : string) {
    letter = std::tolower(letter);
  }
  if (string.find("broken") != std::string::npos) {
    throw InspectionError();
  }
}


