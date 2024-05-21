project(lwg_base)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
find_package(Qt6 COMPONENTS
        Core
        REQUIRED)

set(SOURCES
        utils/File.cpp
)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt::Core
        PUBLIC
        liblinkerfs
)