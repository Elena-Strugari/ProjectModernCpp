cmake_minimum_required(VERSION 3.15)

# Numele proiectului
project(MyProject)

# Setarea standardului C++
set(CMAKE_CXX_STANDARD 17)

# Adăugăm subdirectoarele
add_subdirectory(server)
add_subdirectory(client)
