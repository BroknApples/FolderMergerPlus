# Create project
cmake_minimum_required(VERSION 3.16)
project("Album Manager")

# Set CPP standard
set(CMAKE_CXX_STANDARD 17)

# Find Qt (adjust Qt6 or Qt5 as needed)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.1/mingw_64") # TODO: Change this to your local path to Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Setup source code
set (SOURCES
  # Main
  src/main.cpp

  # Core
  src/core/config.cpp
  src/core/utils.cpp

  # UI
  src/ui/app.cpp

  # UI - Pages
  src/album_manager/pages/home_page.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add the thirdparty directory as an include dir
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/thirdparty)

# Link Qt6 to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)