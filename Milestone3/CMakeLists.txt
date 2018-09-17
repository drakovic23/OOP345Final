cmake_minimum_required(VERSION 3.9)
project(Milestone3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Milestone3 csvDump.cpp Task.cpp Task.h TaskManager.cpp TaskManager.h Util.cpp Util.h Item.cpp Item.h Order.cpp Order.h ItemManager.cpp ItemManager.h OrderManager.cpp OrderManager.h)