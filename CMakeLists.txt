cmake_minimum_required(VERSION 2.6)
project(learncmake)

find_package(icpasz REQUIRED)

option(WITH_ICPASZ "use icp from icpasz" ON)

IF(WITH_ICPASZ)
  find_package(icpasz QUIET)
  IF(icpasz_FOUND)
    message(STATUS "Found icpasz ${icpasz_INCLUDE_DIRS}")
  endif(icpasz_FOUND)
endif(WITH_ICPASZ)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

IF(USE_SAVE_MAP)
  add_definitions(-D_USE_SAVE_MAP)
ENDIF()
   

IF(WITH_POINTMATCHER)
    find_package(libpointmatcher QUIET)
    IF(libpointmatcher_FOUND)
       MESSAGE(STATUS "Found libpointmatcher: ${libpointmatcher_INCLUDE_DIRS}")
    ENDIF(libpointmatcher_FOUND)
ENDIF(WITH_POINTMATCHER)

IF(NOT icpasz_FOUND)
   SET(ICPASZ "//")
else()
   SET(ICPASZ "")
   SET(CONF_DEPENDENCIES ${CONF_DEPENDENCIES} {${icpasz_LIBRARIES})
endif()

IF(icpasz_FOUND)
message(STATUS "Wiht icpasz                 =YES(License: BSD)")
else()
message(STATUS "With icpasz                 =NO(WITH_ICPASZ=OFF)")
endif()

CONFIGURE_FILE(version.h.in ${PROJECT_SOURCE_DIR}/core/Version.h @ONLY)

include_directories(${icpasz_INCLUDE_DIRS})

add_executable(learncmake main.cpp learncmake.cpp)

target_link_libraries(learncmake ${icpasz_LIBRARIES})

if(_USE_SAVE_MAP)
  target_compile_definitions(learncmake PUBLIC FUNC_USE_SAVE_MAP=1)
  target_compile_definitions(learncmake PUBLIC FUNC_MAP_SAVE_LOAD=1)
  message(STATUS "XXXXX ${FUNC_USE_SAVE_MAP}")
endif()



install(TARGETS learncmake RUNTIME DESTINATION bin)
