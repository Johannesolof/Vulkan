cmake_minimum_required ( VERSION 3.9.6 )

project ( Engine )

# Build and link executable.
add_executable ( ${PROJECT_NAME}
    main.cpp
    Application.h
    Application.cpp
    Vertex.h
    )
target_link_libraries ( ${PROJECT_NAME} Helper )
config_build_output()
