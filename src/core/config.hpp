#ifndef CONFIG_HPP
#define CONFIG_HPP


#include <iostream>
#include <stdexcept>
#include "simpleini/SimpleIni.h"
#include "utils.hpp"


/**
 * @brief Defines the different parameters for a config
 * 
 * -----------------------------------------------------------------
 * 
 * INI-STYLE
 * 
 * char: Same as strings but use single quotation marks  => ''
 *
 * Strings: Must have double quotation marks around itself => ""
 *
 * ints: Should just be plain text which CAN include a + or - in front of it
 *
 * float/doubles: Same as int, but there can be at most ONE period in it
 *
 * bool: Must be either "true" or "false" (with any capitalization) OR "1" or "0"
 */
class Config {
  private:
    /** Path to the config file */
    static constexpr inline const char* _CONFIG_FILE_PATH = "../cfg/config.ini";

    /** Default values for strings */
    static constexpr inline const char* _DEFAULT_GET_VALUE_STRING = "";
    static constexpr inline const char* _DEFAULT_SET_VALUE_STRING = "\"\"";

    /** Default values for integers */
    static const inline int _DEFAULT_GET_VALUE_INT = 0;
    static constexpr inline const char* _DEFAULT_SET_VALUE_INT = "0";

    /** Default values for floating-point numbers */
    static const inline double _DEFAULT_GET_VALUE_FLOAT = 0.00;
    static constexpr inline const char* _DEFAULT_SET_VALUE_FLOAT = "0.00";

    /** Default values for boolean values */
    static const inline bool _DEFAULT_GET_VALUE_BOOL = false;
    static constexpr inline const char* _DEFAULT_SET_VALUE_BOOL = "false";

    /** The actual ini parser */
    static CSimpleIniA _ini;

  public:
    // Static only class
    Config() = delete;

    static void init();
    static void save();

    static void removeDuplicateValues(const char* section, const char* key);

    static const std::string getString(const char* section, const char* key);
    static void setString(const char* section, const char* key, std::string& value);

    static const long getInt(const char* section, const char* key);
    static void setInt(const char* section, const char* key, long value);

    static const double getFloat(const char* section, const char* key);
    static void setFloat(const char* section, const char* key, double value);
    
    static const bool getBool(const char* section, const char* key);
    static void setBool(const char* section, const char* key, bool value);

    /**
     * @brief Defines each section in the "config.ini" file and their keys
     */
    struct Sections {
      /**
       * @brief This section defines settings for the window itself
       */
      struct WindowSettings {
        static constexpr const char* self = "WindowSettings";
        static constexpr const char* WINDOW_NAME = "window_name";
        static constexpr const char* WINDOW_WIDTH = "window_width";
        static constexpr const char* WINDOW_HEIGHT = "window_height";
        static constexpr const char* MINIMUM_WINDOW_WIDTH = "minimum_window_height";
        static constexpr const char* MINIMUM_WINDOW_HEIGHT = "minimum_window_height";
      };
    };
};


#endif // CONFIG_HPP