#include "album_manager/app.hpp"
#include "album_manager/config.hpp"


/**
 * @brief Entry point of the program.
 */
int main(int argc, char* argv[]) {
  App app(argc, argv);

  // Initialize the config and app
  Config::init();
  app.init();

  // Run the app
  app.run();

  return 0;
}