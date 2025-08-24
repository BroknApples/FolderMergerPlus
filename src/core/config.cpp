#include "config.hpp"


/**********************************************************************/
/******************************* Private ******************************/
/**********************************************************************/

CSimpleIniA Config::_ini;


/**********************************************************************/
/********************** Constructors/Destructors **********************/
/**********************************************************************/


/**********************************************************************/
/******************************* Public *******************************/
/**********************************************************************/

/**
 * @brief Initializes the Config class
 */
void Config::init() {
  SI_Error rc = _ini.LoadFile(_CONFIG_FILE_PATH);
  if (rc < 0) {
    throw std::runtime_error("Could not load config file!");
  }
}


/**
 * @brief Save changes to the disk.
 */
void Config::save() {
  _ini.SaveFile(_CONFIG_FILE_PATH);
}


/**
 * @brief Removes the duplicate values of a given key in a section
 * @param section: Section to check
 * @param key: Key to remove duplicates of
 */
void Config::removeDuplicateValues(const char* section, const char* key) {
  // First get the values
  CSimpleIniA::TNamesDepend values;
  _ini.GetAllValues(section, key, values);
  if (values.size() <= 1) return;

  // Remove all occurences and only add the first one
  _ini.Delete(section, key);
  _ini.SetValue(section, key, values.begin()->pItem);
}


/**
 * @brief Get a value from the config as a string
 * @param section: Section to get the value from
 * @param key: Key within the section to get the value from
 * @returns: std::string: String of the value specified
 */
const std::string Config::getString(const char* section, const char* key) {
  bool multi_flag;

  // Read string
  std::string str = std::string(_ini.GetValue(section, key, _DEFAULT_GET_VALUE_STRING, &multi_flag));

  // If there are duplicate values, remove them, then continue
  if (multi_flag) removeDuplicateValues(section, key);

  // Return value without the extra quotation marks as specified in the ini style I am using
  return Utils::trim(str, "\"");
}


/**
 * @brief Set a value in the config file as a string
 * @param section: Section to set the value in
 * @param key: Key to change the value of
 * @param value: New value to be set
 */
void Config::setString(const char* section, const char* key, std::string& value) {
  // Add quotations at the beginning and end if they are missing
  if (value[0] != '\"') {
    value = "\"" + value;
  }
  if (value[value.length()-1] != '\"') {
    value += "\"";
  }

  // Actually set the value
  _ini.SetValue(section, key, value.c_str());
}


/**
 * @brief Get a value from the config as a string
 * @param section: Section to get the value from
 * @param key: Key within the section to get the value from
 * @returns: int: Integer of the value specified
 */
const long Config::getInt(const char* section, const char* key) {
  bool multi_flag;

  // Read string
  long num = _ini.GetLongValue(section, key, _DEFAULT_GET_VALUE_INT, &multi_flag);

  // If there are duplicate values, remove them, then continue
  if (multi_flag) removeDuplicateValues(section, key);

  // Return value without the extra quotation marks as specified in the ini style I am using
  return num;
}


/**
 * @brief Set a value in the config file as a string
 * @param section: Section to set the value in
 * @param key: Key to change the value of
 * @param value: New value to be set
 */
void Config::setInt(const char* section, const char* key, long value) {
  _ini.SetLongValue(section, key, value);
}


/**
 * @brief Get a value from the config as a string
 * @param section: Section to get the value from
 * @param key: Key within the section to get the value from
 * @returns: float: Float of the value specified
 */
const double Config::getFloat(const char* section, const char* key) {
  bool multi_flag;

  // Read string
  double num = _ini.GetDoubleValue(section, key, _DEFAULT_GET_VALUE_FLOAT, &multi_flag);

  // If there are duplicate values, remove them, then continue
  if (multi_flag) removeDuplicateValues(section, key);

  // Return value without the extra quotation marks as specified in the ini style I am using
  return num;
}


/**
 * @brief Set a value in the config file as a string
 * @param section: Section to set the value in
 * @param key: Key to change the value of
 * @param value: New value to be set
 */
void Config::setFloat(const char* section, const char* key, double value) {
  _ini.SetDoubleValue(section, key, value);
}


/**
 * @brief Get a value from the config as a string
 * @param section: Section to get the value from
 * @param key: Key within the section to get the value from
 * @returns: bool: Boolean of the value specified
 */
const bool Config::getBool(const char* section, const char* key) {
  bool multi_flag;

  // Read string
  bool truthy = _ini.GetBoolValue(section, key, _DEFAULT_GET_VALUE_BOOL, &multi_flag);

  // If there are duplicate values, remove them, then continue
  if (multi_flag) removeDuplicateValues(section, key);

  // Return value without the extra quotation marks as specified in the ini style I am using
  return truthy;
}


/**
 * @brief Set a value in the config file as a string
 * @param section: Section to set the value in
 * @param key: Key to change the value of
 * @param value: New value to be set
 */
void Config::setBool(const char* section, const char* key, bool value) {
  _ini.SetBoolValue(section, key, value);
}
