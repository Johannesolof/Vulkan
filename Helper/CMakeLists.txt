cmake_minimum_required ( VERSION 3.9.6 )

project ( Helper )

# External libraries which need to be built.
add_subdirectory ( ${CMAKE_SOURCE_DIR}/external_src/imgui-1.51 ${CMAKE_CURRENT_BINARY_DIR}/imgui )
set_target_properties(imgui PROPERTIES FOLDER external)

find_package ( GLFW3 REQUIRED )
find_package ( glm REQUIRED )
find_package ( Vulkan REQUIRED )

# Build and link library.
add_library ( ${PROJECT_NAME} 
    helper.cpp
	helper.h
    )

target_include_directories( ${PROJECT_NAME} 
    PUBLIC
    ${CMAKE_SOURCE_DIR}/Helper
    ${CMAKE_SOURCE_DIR}/external_src/stb-master
    ${CMAKE_SOURCE_DIR}/external_src/tinyobjloader-1.0.6
    ${GLFW3_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${Vulkan_INCLUDE_DIRS}
    )

target_link_libraries ( ${PROJECT_NAME} 
    PUBLIC
    imgui
    ${GLFW3_LIBRARIES}
    ${Vulkan_LIBRARY}
    )
