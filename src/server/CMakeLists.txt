project(lwg_server)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
find_package(Qt6 COMPONENTS
        HttpServer
        REQUIRED)

set(SOURCES
        main.cpp
        WebApplication.cpp
        dto/request/ListDirReqDto.cpp
        common/abstract/AbstractRequestDto.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        Qt::HttpServer
        lwg_base
)