cmake_minimum_required(VERSION 3.10)
project(HW11)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(HW11
        main.cpp
        Projectile.cpp
        Projectile.h
        ProjectileWithDrag.cpp
        ProjectileWithDrag.h
        vector2d.cpp
        vector2d.h)
