#ifndef AIRCRAFT_HANDLER_HPP
#define AIRCRAFT_HANDLER_HPP

#include <memory>
#include <string>
#include <utility>
#include <iostream>
#include "nlohmann/json.hpp"
#include "Entities/Aircraft.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Aircraft_Serializer.hpp"
#include "Input_Handler.hpp"

#define REMOVE_ADD_OPTION false
class aircrafthandler
{
private:
  std::unique_ptr<FileHandler> fileHandler;
  InputHandler inputHandler;

public:
  aircrafthandler();

  Aircraft searchaircraft(const std::string &aircraftType, int totalSeats);
  void addaircraft(Aircraft &aircraft);
  Aircraft chooseaircraft(bool allowAddOption = true);
  void updateaircraft(const Aircraft &aircraft);
  void removeaircraft(const Aircraft &aircraft);
  void viewAllaircrafts();
};

#endif