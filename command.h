#ifndef _COMMAND_H_
#define _COMMAND_H_
#include <iostream>
#include <string>
#include <vector>

class CommandInterpreter{
  std::string fullCommand;
  int commandIndex;
  int executeTimes;
public:
  CommandInterpreter(std::string command); //interprete specific command
  int getCommandIndex(); //getter function that return CommandIndex
  int getExecuteTimes(); //getter function that return ExecuteTimes
  bool isValid(); //predicate function that check command is valid
};

#endif
