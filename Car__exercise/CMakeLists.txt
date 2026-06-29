cmake_minimum_required(VERSION 3.15)

# 1. Name your project and set the language
project(Car__exercise LANGUAGES C++)

# 2. Specify the C++ standard (e.g., C++17 or C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Explicitly list your source files 
# Replace these placeholder names with your actual file names
set(PROJECT_SOURCES
    main.cpp
    Car.cpp
    ElectricCar.cpp
    Observer.cpp
    SportsCar.cpp
    VehicleUtils.cpp
)

# 4. Explicitly list your header files (4 header files)
# Including headers here makes them show up nicely in the Visual Studio Solution Explorer
set(PROJECT_HEADERS
    Car.h
    ElectricCar.h
    Observer.h
    SportsCar.h
    VehicleUtils.h
)

# 5. Define the executable and combine sources and headers
add_executable(${PROJECT_NAME} 
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

# 6. Tell CMake where to look for header files (usually the current directory ".")
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})