cmake_minimum_required(VERSION 3.18)
project(test-eos)

option(WITH_CONAN "Use conan for package management")

if(WITH_CONAN)
  include(conanbuildinfo.cmake)
  conan_basic_setup()
  set(LIBS ${CONAN_LIBS})
else()
  include(deps.cmake)
endif()

include_directories(deps/eos-portable-archive)

add_executable(test-eos main.cpp)
target_link_libraries(test-eos ${LIBS})
