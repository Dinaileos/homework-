#include "Registry.h"
#include "ServiceCenter.h"
#include "Inventory.h"
#include <memory>
#include <unordered_map>
#include <vector>


class Fleet {
private:
  std::unordered_map<std::string, std::shared_ptr<InventoryItem> > items_;
  std::weak_ptr<InventoryItem> focus_;
public:
  Registry<std::string, 100> history;
  void AddItem(std::unique_ptr<InventoryItem> item);
  void List() const;
  void Energy() const;
  void Novice() const;
  void Remove(const std::string& id);
  void Focus(const std::string& id);
  void ShowFocus() const;
  void CountNovice() const;
};

class Builder {
public:
  std::unique_ptr<InventoryItem> Create(std::string kind);
};


