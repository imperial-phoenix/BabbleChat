set(TARGET_NAME "Client")

add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE nlohmann_json::nlohmann_json)
