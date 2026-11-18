#pragma once
#include <stdexcept>
#include <string>

class FleetError : public std::runtime_error {
public:
  FleetError(std::string messeng)
  : std::runtime_error(messeng) {}
};

class InspectionError : public FleetError {
public:
  InspectionError()
  : FleetError("Не прошел тех осмотр") {}
};

class CommandError : public FleetError {
public:
  CommandError(std::string messeng)
  : FleetError(messeng) {}
};

class RegistryError : public FleetError, public std::overflow_error {
public:
    RegistryError(const std::string& msg)
        : FleetError(msg), std::overflow_error(msg) {}
};
