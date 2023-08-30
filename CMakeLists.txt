cmake_minimum_required(VERSION 3.14)

project(CADEx_test_task LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required Qt components
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Widgets 3DCore 3DExtras 3DRender 3DInput)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Widgets 3DCore 3DExtras 3DRender 3DInput)

# Find the native OpenGL and possibly GLUT libraries
find_package(OpenGL REQUIRED)
# Uncomment the next line if you're using GLUT
# find_package(GLUT REQUIRED)

# Create the library
add_library(CURVE_LIBRARY SHARED
    curves/curve.h
    curves/circle/circle.h curves/circle/circle.cpp
    curves/ellipse/ellipse.h curves/ellipse/ellipse.cpp
    curves/helix/helix.h curves/helix/helix.cpp
    curves/curves_container/curves_container.h curves/curves_container/curves_container.cpp
    curves/curves_container/curves_random_generator.cpp
    curves/curves_container/printCoordinatesAndDerivatives.cpp
    curves/curves_container/populateSpecificCurveType.cpp
    curves/curves_container/sort_container.cpp
    curves/curves_container/total_sum_of_radii.cpp
)

# Link the required Qt modules to the library
target_link_libraries(CURVE_LIBRARY PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui

)

# Create the executable
add_executable(CADEx_test_task
    main.cpp
    tests/test_curve_lib/test_curve_lib.h tests/test_curve_lib/test_curve_lib.cpp
    visualizer/curvewidget.h visualizer/curvewidget.cpp
    Task.md
)

# Link the libraries to the executable
target_link_libraries(CADEx_test_task PRIVATE
    CURVE_LIBRARY
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::3DCore
    Qt${QT_VERSION_MAJOR}::3DExtras
    Qt${QT_VERSION_MAJOR}::3DRender
    Qt${QT_VERSION_MAJOR}::3DRender
    Qt${QT_VERSION_MAJOR}::3DInput
)

link_directories(${CMAKE_CURRENT_BINARY_DIR})

include(GNUInstallDirs)
install(TARGETS CADEx_test_task CURVE_LIBRARY
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
