if(NOT BOOST_ROOT)
  message(FATAL_ERROR "Please set the BOOST_ROOT")
endif()

include_directories(${BOOST_ROOT})
link_directories(${BOOST_ROOT}/stage/lib)

set(LIBS boost_serialization)
