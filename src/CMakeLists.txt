cmake_minimum_required(VERSION 3.19)

add_library(GLEWY STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Content/stringserial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Content/file.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Content/data.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/abstraction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/instance.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/root.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/material.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/renderable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/rendercalls.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/shaders.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/uniform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering/uvtable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/attachment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/component.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/entity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene/transformable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/sprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/spriteatlas.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Structures/dool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Structures/transform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Structures/tree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Structures/grid.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Structures/rect.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/readfile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/util.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio/sound.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio/soundinstance.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Input/inputable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Input/mouse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Input/button.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Tilemap/tilemap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Tilemap/tile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Tilemap/tilemaprenderer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/UtilAttachments/cameracontroller.cpp
    )

target_include_directories(GLEWY PUBLIC "${CMAKE_SOURCE_DIR}/include")

target_include_directories(GLEWY PUBLIC "C:/Program Files (x86)/GLEW/include")
target_include_directories(GLEWY PUBLIC "C:/Program Files (x86)/GLFW/include")
target_include_directories(GLEWY PUBLIC "C:/Program Files (x86)/SOIL/include")
target_include_directories(GLEWY PUBLIC "C:/Program Files (x86)/SoLoud_MA/include")