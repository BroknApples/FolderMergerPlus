# Create project
cmake_minimum_required(VERSION 3.16)
project("FolderMergerPlus")

# Set CPP standard
set(CMAKE_CXX_STANDARD 17)

# Find Qt (adjust Qt6 or Qt5 as needed)
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.1/mingw_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Setup source code
set (SOURCES
  # Main
  src/main.cpp

  # Application

)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Qt6 to the executable
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)