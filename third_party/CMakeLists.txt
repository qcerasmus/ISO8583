include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.11.0 
)
FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
    message("Downloading spdlog")
    FetchContent_Populate(spdlog)
endif()
add_library(spdlog INTERFACE)
target_include_directories(spdlog INTERFACE ${spdlog_SOURCE_DIR}/include/spdlog)
set(spdlog_cmake_SOURCE_DIR ${spdlog_SOURCE_DIR}/include PARENT_SCOPE)

