cmake_minimum_required ( VERSION 3.9.6 )

project ( VulkanEngine )
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# For windows we use our bundled binaries.
if(WIN32)
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/external/embree2")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/external/glfw3")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/external/glew")
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/external/glm")
endif(WIN32)

macro(config_build_output)
    if(MSVC)
        set(DLL_DIRECTORIES "${CMAKE_SOURCE_DIR}/external/bin")
        set(MSVC_RUNTIME_DIR "${CMAKE_SOURCE_DIR}/bin")
        set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY                "${MSVC_RUNTIME_DIR}" )
        set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG          "${MSVC_RUNTIME_DIR}" )
        set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE        "${MSVC_RUNTIME_DIR}" )
        set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${MSVC_RUNTIME_DIR}" )
        set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL     "${MSVC_RUNTIME_DIR}" )
        set(vs_user_file "${PROJECT_BINARY_DIR}/${PROJECT_NAME}.vcxproj.user")
        string(REGEX REPLACE "v([0-9][0-9])([0-9])" "\\1.\\2" "VS_TOOLSET_VERSION" "${CMAKE_VS_PLATFORM_TOOLSET}")
        configure_file("${CMAKE_SOURCE_DIR}/VSUserTemplate.user" "${vs_user_file}" @ONLY)
    endif(MSVC)
endmacro(config_build_output)



add_definitions(-DGLM_ENABLE_EXPERIMENTAL)
set ( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set ( CMAKE_BUILD_TYPE DEBUG )
add_definitions ( -std=c++11 )

add_subdirectory ( Helper )
add_subdirectory ( Engine )