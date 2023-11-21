set(TARGET_NAME "TestClient")

find_package(Qt6 COMPONENTS Network Core REQUIRED)

add_executable(${TARGET_NAME} main.cpp client.cpp)

target_link_libraries(${TARGET_NAME} Qt6::Core Qt6::Network)
