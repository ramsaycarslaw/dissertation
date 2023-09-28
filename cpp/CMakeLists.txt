FIND_PACKAGE (Boost 1.70 COMPONENTS context REQUIRED)

if (Boost_FOUND)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
  link_libraries (Boost::context)
  add_executable (unix main.cpp)
else()
  message (STATUS "Boost not found!")
endif()
