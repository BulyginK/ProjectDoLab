add_executable(05 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

target_include_directories(05 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(05 PUBLIC cxx_std_17)
target_compile_definitions(05 PRIVATE SFML_STATIC)

target_link_libraries(05 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})