#include "Things.hpp"
#include "Registry.hpp"
#include "ServiceCenter.hpp"
#include "Fleet.hpp"
#include "Errors.hpp"
#include "Transport.hpp"
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
        fleet.history.Add(item->GetId());
        fleet.AddItem(std::move(item));
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
        std::cout << "---история----" << "\n";
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
