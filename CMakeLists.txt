cmake_minimum_required(VERSION 3.31.2) 
project(EssenseStream) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)
add_executable(Runnable Run.cpp) 
add_library(EssenseLibrary STATIC EssenseStream.cpp EssenseStream.h) 
target_link_libraries(Runnable EssenseLibrary)
target_include_directories(EssenseLibrary PUBLIC "${PROJECT_SOURCE_DIR}")