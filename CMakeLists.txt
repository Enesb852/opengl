cmake_minimum_required(VERSION 3.10)

project(opengl)

# C++ standardını belirleyin
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# GLFW kütüphanesini bulun
find_package(glfw3 REQUIRED)


# GLAD kaynak dosyasını ekleyin
add_library(glad STATIC link/glad/src/glad.c)


# Proje kaynak dosyalarını ekleyin
set(SOURCES
    src/main.cpp
    src/texture_manager.cpp
    src/shader.cpp
    src/stb_image.cpp

    # Diğer kaynak dosyalarınızı buraya ekleyin
)


include_directories(link/glad/include)
include_directories(link)



# Yürütülebilir hedefi oluşturun
add_executable(opengl ${SOURCES})

# Bağımlı kütüphaneleri hedefe bağlayın
target_link_libraries(opengl glfw glad)