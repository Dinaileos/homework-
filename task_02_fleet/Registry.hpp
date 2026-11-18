#pragma once
#include <iostream>
#include <memory>
#include "Inventory.hpp"
#include "Errors.hpp"

inline std::ostream& operator<<(std::ostream& os, const std::shared_ptr<InventoryItem>& item) {
  std::cout << item->GetId() << " " << item->GetName() << "\n";
  return os;
}

inline bool operator<(std::shared_ptr<InventoryItem>& item_a, std::shared_ptr<InventoryItem>& item_b) {
  return item_a->GetId() < item_b->GetId();
}


template <typename T, int Cap>
class Registry {
private:
  T history_[Cap];
  long size_ = 0;

public:
  void Add(const T& item) {
    if (size_ >= Cap) {
      throw RegistryError("Registry is full");
    }
    history_[size_] = item;
    size_++;
  }
  long GetSize() const {
    return size_;
  }
  
  const T& operator[](size_t index) const {
    if (index >= size_) {
      throw RegistryError("Index out of range");
    }
    return history_[index];
  }
};
template <typename T, int Cap>
std::ostream& operator<<(std::ostream& os, const Registry<T, Cap>& registry) {
  for (long i = 0; i < registry.GetSize(); ++i) {
    os << registry[i] << "\n";
  }
  return os;
}
