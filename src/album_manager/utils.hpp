#ifndef UTILS_HPP
#define UTILS_HPP


#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>


namespace Utils {
  std::string trim(const std::string& str, const std::string& chars);
  bool isInt(const std::string& str);
  bool isFloat(const std::string& str);
  bool isBool(const std::string& str);
}


#endif // UTILS_HPP