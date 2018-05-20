#include <sstream>
#include "command.h"
using namespace std;

//short command dictionary
const string knownCommandShort[21] = {
  "lef",      //left
  "ri",       //right
  "do",       //down
  "cl",       //clockwise
  "co",       //counterclockwise
  "dr",       //drop
  "levelu",   //levelup
  "leveld",   //leveldown
  "n",        //norandom
  "ra",       //random
  "s",        //sequence
  "re",       //restart
  "hi",       //hint
  // all blocks
  "I",
  "J",
  "O",
  "S",
  "Z",
  "T",
  "L",
  "ho"        //hold
};

//long command dictionary
const string knownCommandFull[21] = {
  "left",
  "right",
  "down",
  "clockwise",
  "counterclockwise",
  "drop",
  "levelup",
  "leveldown",
  "norandom",
  "random",
  "sequence",
  "restart",
  "hint",
  // all blocks
  "I",
  "J",
  "O",
  "S",
  "Z",
  "T",
  "L",
  "hold"
};

//return the minimum number between two integer
int min(int a, int b){
  if (a > b){
    return b;
  } else {
    return a;
  }
}

//find specific command
int findCommand(string command){
  int len = command.length();
  vector<string> commandList;
  for (int i = 0; i < 21; ++i){
    commandList.emplace_back(knownCommandShort[i]);
  }
  for (int i = 0; i < len; ++i){
    vector<string> temp;
    for (auto it: commandList){
      if (it[i] == command[i]){
        temp.emplace_back(it);
      }
    }
    if (temp.size() > 1){
      commandList = temp;
    } else if (temp.size() == 0){
      return -1;
    } else {
      int commandIndex;
      string matchedFullCommand;
      for (int i = 0; i < 21; ++i){
        if (temp[0] == knownCommandShort[i]){
          commandIndex = i;
          break;
        }
      }
      matchedFullCommand = knownCommandFull[commandIndex];
      if (command.length() > matchedFullCommand.length()){
      	return -1;
	  }
	  int minLength = min(command.length(), matchedFullCommand.length());
      for (int i = 0; i < minLength; ++i){
        if (command[i] != matchedFullCommand[i]){
          return -1;
        }
      }
      return commandIndex;
    }
  }
  return -1;
}

//interprete specific command
CommandInterpreter::CommandInterpreter(string command): executeTimes{0}{
  if (command[0] == '0'){
    command.erase(command.begin());
    int commandIndex = findCommand(command);
    if (commandIndex == -1){
      this->fullCommand = "invalid";
    } else {
      this->fullCommand = knownCommandFull[commandIndex];
    }
  } else {
    stringstream ss{command};
    int prefix;
    int prefixLength = 0;
    ss >> prefix;
    int checkLength = prefix;
    while(checkLength){
      ++prefixLength;
      checkLength = checkLength / 10;
    }
    command.erase(command.begin(), command.begin() + prefixLength);
    int commandIndex = findCommand(command);
    if (commandIndex == -1){
      this->fullCommand = "invalid";
    } else if (prefix > 0 && commandIndex != 0 && commandIndex != 1 && commandIndex != 2 && commandIndex != 3 && commandIndex != 4 && commandIndex != 5 && commandIndex != 6 && commandIndex != 7){
      this->fullCommand = knownCommandFull[commandIndex];
      this->executeTimes = 1;
      this->commandIndex = commandIndex;
    } else {
      this->fullCommand = knownCommandFull[commandIndex];
      if (prefixLength == 0){
        prefix = 1;
      }
      this->executeTimes = prefix;
      this->commandIndex = commandIndex;
    }
  }
}

//getter function that return ExecuteTimes
int CommandInterpreter::getExecuteTimes(){
  return this->executeTimes;
}

//getter function that return CommandIndex
int CommandInterpreter::getCommandIndex(){
  return this->commandIndex;
}

//predicate function that check command is valid
bool CommandInterpreter::isValid(){
  if (this->fullCommand == "invalid"){
    return false;
  } else {
    return true;
  }
}
