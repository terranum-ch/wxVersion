# CMAKE BUILD FILE FOR CMDLINETEST 
# (c) LUCIEN SCHREIBER 2020
cmake_minimum_required(VERSION 3.0)
PROJECT("cmdLineTest")

#search all source files
SET(SRC_FILES "main.cpp")
SOURCE_GROUP(source FILES ${SRC_FILES})

# FIND WXWIDGETS
# FOR WINDOWS, DO NOT FORGET TO DEFINE WXWIN VARIABLE
# FOR UNIX, SET ENVIRONNEMENT VAR : export WX_CONFIG=<path to wxconfig> before calling cmake
find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})

# #INCLUDE wxHGVERSION
INCLUDE("../../build/use_wxversion.cmake")

ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${WXVERSION_NAME} ${wxWidgets_LIBRARIES})
