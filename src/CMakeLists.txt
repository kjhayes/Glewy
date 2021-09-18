cmake_minimum_required(VERSION 3.19)

add_library(GLEWY STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Content/stringserial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Content/file.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Content/data.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Content/serializable.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/abstraction.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/instance.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/root.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Debug/debugrendercalls.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Debug/debugline.cpp

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
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio/sound.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio/soundinstance.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Input/inputable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Input/mouse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Input/button.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/RayCollisions/aabbraychecker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/RayCollisions/raycollidable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/RayCollisions/raycollisiongroup.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/RayCollisions/aabbraycollider.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Shapes/line.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Sprite/sprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Sprite/spriteatlas.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Tilemap/tilemap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Tilemap/tile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Tilemap/tilemaprenderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/Tilemap/grid.cpp
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Standard/UtilAttachments/transformcontroller.cpp
    )

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${GLEWY_DEP_INC_DIRS})

#Test Executable
add_executable(GLEWY_TEST ${CMAKE_CURRENT_SOURCE_DIR}/Tests/TestSuite.cpp)

target_include_directories(GLEWY_TEST PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(GLEWY_TEST PUBLIC ${GLEWY_DEP_INC_DIRS})

target_link_libraries(GLEWY_TEST PUBLIC ${CMAKE_PROJECT_NAME})
target_link_libraries(GLEWY_TEST PUBLIC ${GLEWY_DEP_LIBS})