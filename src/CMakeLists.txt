CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)

FIND_PACKAGE(Boost COMPONENTS system filesystem REQUIRED)

set(PULSEWAVES_INCLUDES_DIR ${PROJECT_SOURCE_DIR}/includes)

include_directories( ${Boost_INCLUDE_DIRS} ) 
include_directories( ${PULSEWAVES_INCLUDES_DIR} )

file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/includes/*.h)
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
link_directories( ${PULSEWAVES_SOURCE_DIR}/src)

add_executable(pulsewaves ${SOURCES} ${HEADERS})

target_link_libraries(pulsewaves ${Boost_LIBRARY_DIR} ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY})
