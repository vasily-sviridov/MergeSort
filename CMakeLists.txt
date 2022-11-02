cmake_minimum_required(VERSION 3.16)
project(sorts VERSION 1.0)

add_library(Sorts INTERFACE)

set(CMAKE_CXX_STANDARD 17)

add_library(utils::sorts ALIAS Sorts)

install(DIRECTORY include DESTINATION include)
install(TARGETS Sorts EXPORT SortsConfig)
install(EXPORT SortsConfig NAMESPACE utils:: DESTINATION share/Sorts/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/SortsConfigVersion.cmake"
    VERSION
    ${PROJECT_VERSION}
    COMPATIBILITY
    AnyNewerVersion)

install(FILES "${PROJECT_BINARY_DIR}/SortsConfigVersion.cmake" DESTINATION share/Sorts/cmake)

if (TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	if(SANITIZERS)
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address,undefined")
	endif()

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Werror")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
	if(BENCHMARKS)
		add_subdirectory(benchmark)
	endif()

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif()