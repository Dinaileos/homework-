#include "Inventory.h"
#include <unordered_map>
#include "Fleet.h"
#include <string>
#include <iostream>
#include "Registry.h"
#include "Things.h"
#include "Transport.h"
#include "Errors.h"
#include <memory>
#include <iomanip>

std::unique_ptr<InventoryItem> Builder::Create(std::string kind) {
  if (kind == "helmet") {
    std::string id, name;
    std::cin >> id >> name;
    return std::make_unique<Helmet>(id, name);
  } else if (kind == "ebike") {
    std::string id, name;
    double daily_energy;
    long score;
    std::cin >> id >> name >> daily_energy >> score;
    return std::make_unique<EBike>(id, name, daily_energy, score);
  } else if (kind == "scooter") {
    std::string id, name;
    double daily_energy;
    long score;
    std::cin >> id >> name >> daily_energy >> score;
    return std::make_unique<Scooter>(id, name, daily_energy, score);
  } else if (kind == "dock") {
    std::string id, name;
    double daily_energy;
    std::cin >> id >> name >> daily_energy;
    return std::make_unique<Dock>(id, name, daily_energy);
  } else if (kind == "bike") {
    std::string id, name;
    double daily_energy;
    long score;
    std::cin >> id >> name >> score;
    daily_energy = 0;
    return std::make_unique<Bike>(id, name, daily_energy, score);
  } else if (kind == "monocycle") {
    std::string id, name;
    double daily_energy;
    long score;
    std::cin >> id >> name >> daily_energy >> score;
    return std::make_unique<Monocycle>(id, name, daily_energy, score);
}

  else {
    throw CommandError("Нет сей кобылы в стойлах");
  }
  return std::unique_ptr<InventoryItem>();
}

void Fleet::AddItem (std::unique_ptr<InventoryItem> item) {
  std::shared_ptr<InventoryItem> shared_item = std::move(item);
  items_[shared_item->GetId()] = shared_item;
  std::cout << "successfully added!!!\n";
}

void Fleet::List() const {
  for (const auto& item : items_) {
    std::cout << item.second;
  }
}

void Fleet::Energy() const {
  double sum = 0;
  for (const auto& item : items_) {
    auto element = std::dynamic_pointer_cast<EnergyConsumer>(item.second);
    if (element != nullptr) {
      sum += element->GetDailyEnergy();
    }
  }
  std::cout << std::fixed << std::setprecision(1) << sum << "\n";
}

void Fleet::Novice() const {
  for (const auto& item : items_) {
    if (item.second->GetScore() >= 6) {
      std::cout << item.second;
    }
  }
}

void Fleet::Remove(const std::string& id) {
  auto item = items_.find(id);
  if (item == items_.end()) {
    throw CommandError("не существует элемента с id: " + id);
  }
  items_.erase(id);
}

void Fleet::Focus(const std::string& id) {
  auto item = items_.find(id);
  if (item == items_.end()) {
    throw CommandError("не существует элемента с id: " + id);
  }
  focus_ = item->second;
}

void Fleet::ShowFocus() const {
  std::shared_ptr<InventoryItem> focus = focus_.lock();
  if (focus != nullptr) {
    std::cout << focus;
  } else {
    std::cout << "expired\n";
  }
}

void Fleet::CountNovice() const {
    int count = 0;
    for (const auto& pair : items_) {
        if (pair.second->GetScore() >= 6) count++;
    }
    std::cout << "детям доступно: " << count << "\n";
}
//
// Created by Леонид Наумов on 16.11.2026.
//

#include "Fleet.h"
