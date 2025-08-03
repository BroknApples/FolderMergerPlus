#ifndef APP_HPP
#define APP_HPP


#include <string>
#include <algorithm>
#include <climits>
#include <QApplication>
#include <QMainWindow>
#include <QSize>
#include <QString>
#include "config.hpp"
#include "utils.hpp"
#include "pages/home_page.hpp"


/**
 * @brief Class which starts up the application GUI and setups up the program loop.
 */
class App {
  private:
    QApplication _app;
    QMainWindow* _window;
    bool _initialized;
    
  public:
    App(int argc, char* argv[]);
    ~App();

    void init();
    void run();
};


#endif // APP_HPP