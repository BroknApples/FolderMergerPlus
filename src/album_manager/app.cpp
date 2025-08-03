#include "app.hpp"


/**********************************************************************/
/******************************* Private ******************************/
/**********************************************************************/


/**********************************************************************/
/********************** Constructors/Destructors **********************/
/**********************************************************************/


/**
 * @brief Setup app with argc and argv from the entry-point
 */
App::App(int argc, char* argv[])
  : _app(argc, argv)
  , _initialized(false) {}


/**
 * @brief Cleanup
 */
App::~App() {
  delete _window;
}


/**********************************************************************/
/******************************* Public *******************************/
/**********************************************************************/


/**
 * @brief Initialize the application with a config file.
 */
void App::init() {
  // Create main window widget
  _window = new QMainWindow();

  // Create a short path to the window settings section
  using ws = Config::Sections::WindowSettings;

  // Get window settings
  const std::string WINDOW_NAME = Config::getString(ws::self, ws::WINDOW_NAME);
  const int WINDOW_WIDTH = std::clamp(static_cast<int>(Config::getInt(ws::self, ws::WINDOW_WIDTH)), 0, std::numeric_limits<int>::max());
  const int WINDOW_HEIGHT = std::clamp(static_cast<int>(Config::getInt(ws::self, ws::WINDOW_HEIGHT)), 0, std::numeric_limits<int>::max());
  const int WINDOW_MINIMUM_WIDTH = std::clamp(static_cast<int>(Config::getInt(ws::self, ws::MINIMUM_WINDOW_WIDTH)), 0, std::numeric_limits<int>::max());
  const int WINDOW_MINIMUM_HEIGHT = std::clamp(static_cast<int>(Config::getInt(ws::self, ws::MINIMUM_WINDOW_HEIGHT)), 0, std::numeric_limits<int>::max());

  // Apply settings
  _window->setWindowTitle(QString(WINDOW_NAME.c_str()));
  _window->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
  _window->setMinimumSize(QSize(WINDOW_MINIMUM_WIDTH, WINDOW_MINIMUM_HEIGHT));

  // TODO: setup sub-widgets here
  _window->setCentralWidget(new HomePage());
  
  // Set initialized flag to true
  _initialized = true;
}


/**
 * @brief Run the program loop
 */
void App::run() {
  _window->show();
  _app.exec();
}
