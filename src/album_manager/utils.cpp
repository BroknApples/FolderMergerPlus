#include "utils.hpp"


/**********************************************************************/
/****************************** Functions *****************************/
/**********************************************************************/


namespace Utils {
  /**
   * @brief Trim leading and trailing characters from a string. (DEFAULT: Trim spaces)
   * @param str: String to trim
   * @param chars: Characters to trim
   */
  std::string trim(const std::string& str, const std::string& chars = " ") {
    auto start = str.find_first_not_of(chars);
    if (start == std::string::npos) return ""; // The string contains only chars to trim

    auto end = str.find_last_not_of(chars);
    return str.substr(start, end - start + 1);
  }


  /**
   * @brief Checks if a string could be converted to an integer.
   * (NOTE: Can optionally have a '-' or '+' as the first character to choose the sign value)
   * @param str: String to check
   * @returns bool: True if an int, False otherwise
   */
  bool isInt(const std::string& str) {
    // Attempt to process the value using istringstream
    std::istringstream iss(str);
    int f;
    char c;

    if (!(iss >> f)) {
      // Failed to parse int
      return false;        
    }

    if (iss >> c) {
      // Leftover characters after int
      return false;           
    }

    // No errors detected
    return true;
  }


  /**
   * @brief Checks if a string could be converted to an floating-point value.
   * (NOTE: Can optionally have a '-' or '+' as the first character to choose the sign value)
   * @param str: String to check
   * @returns bool: True if an float, False otherwise
   */
  bool isFloat(const std::string& str) {
    // Attempt to process the value using istringstream
    std::istringstream iss(str);
    float f;
    char c;

    if (!(iss >> f)) {
      // Failed to parse float
      return false;        
    }

    if (iss >> c) {
      // Leftover characters after float
      return false;           
    }

    // No errors detected
    return true;
  }


  /**
   * @brief Checks if a given string is a boolean value
   * @param str: String to check
   * @returns bool: True if a boolean value, False otherwise
   */
  bool isBool(const std::string& str) {
    std::string lower;
    lower.resize(str.size());
    std::transform(str.begin(), str.end(), lower.begin(), ::tolower);
    return (lower == "true" || lower == "false" || lower == "1" || lower == "0");
  }
}