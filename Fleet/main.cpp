#include "Things.h"
#include "Registry.h"
#include "ServiceCenter.h"
#include "Fleet.h"
#include "Errors.h"
#include "Transport.h"
#include <iostream>
#include <memory>

int main() {
  Fleet fleet;
  std::string cmd;
  ServiceCentr service;
  Builder builder;

  while (true) {
    std::cin >> cmd;
    if (cmd == "quit") break;
    try {
      if (cmd == "add") {
        std::string kind;
        std::cin >> kind;
        auto item = builder.Create(kind);
        service.Inspect(item);
        fleet.AddItem(std::move(item));
        fleet.history.Add(item->GetName());
      } else if (cmd == "list") {
        fleet.List();
      } else if (cmd == "energy") {
        fleet.Energy();
      } else if (cmd == "novice") {
        fleet.Novice();
      } else if (cmd == "remove") {
        std::string id;
        std::cin >> id;
        fleet.Remove(id);
      }else if (cmd == "focus") {
        std::string id;
        std::cin >> id;
        fleet.Focus(id);
      }else if (cmd == "show_focus") {
        fleet.ShowFocus();
      } else if(cmd == "history") {
        std::cout << "---история----";
        std::cout << fleet.history;
      } else if (cmd == "count_novice") {
        fleet.CountNovice();
      }
    } catch (const FleetError& e) {
      std::cout << "error:" << e.what() << "\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
