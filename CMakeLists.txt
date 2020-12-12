cmake_minimum_required(VERSION 3.14)
project(procjam2020)

set(CMAKE_CXX_STANDARD 20)
set(SFML_ROOT "${CMAKE_CURRENT_LIST_DIR}/external/SFML")

set (CMAKE_MODULE_PATH "${SFML_ROOT}/lib/cmake/")
find_package (SFML REQUIRED system window graphics network audio)

add_executable(procjam2020 main.cpp scenes/BaseScene.cpp scenes/BaseScene.h utilities/Singleton.h gameManagers/SceneManager.cpp gameManagers/SceneManager.h nodes/BaseNode.cpp nodes/BaseNode.h components/BaseComponent.cpp components/BaseComponent.h components/PositionComponent.cpp components/PositionComponent.h components/TransformComponent.cpp components/TransformComponent.h components/Holder.h nodes/Sprite.cpp nodes/Sprite.h gameManagers/ResourceManager.cpp gameManagers/ResourceManager.h components/TextureComponent.cpp components/TextureComponent.h utilities/Rect.h utilities/Events.cpp utilities/Events.h scenes/TestScene.cpp scenes/TestScene.h)
target_link_libraries(procjam2020 PRIVATE sfml-audio sfml-graphics sfml-network sfml-system sfml-window)
target_include_directories(procjam2020 PRIVATE ${CMAKE_CURRENT_LIST_DIR})

