add_library(CAN can/can.cc)
target_include_directories(CAN PUBLIC can)

add_library(CAN_INTERFACE can/caninterface.cc)
target_include_directories(CAN_INTERFACE PUBLIC can)

add_executable(write_speedometer write_speedomter.cc)

target_link_libraries(write_speedometer LINK_PUBLIC CAN CAN_INTERFACE)