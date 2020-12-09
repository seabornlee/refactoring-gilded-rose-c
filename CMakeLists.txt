cmake_minimum_required(VERSION 3.8)
project(refactor-gilded-rose-c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    # Check CppCheck version
    set(CPP_CHECK_CMD ${CMAKE_CXX_CPPCHECK} --version)
    execute_process(COMMAND ${CPP_CHECK_CMD}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE CPP_CHECK_RESULT
            OUTPUT_VARIABLE CPP_CHECK_VERSION
            ERROR_VARIABLE CPP_CHECK_ERROR)
    # Check if version could be extracted
    if (CPP_CHECK_RESULT EQUAL 0)
        # Get number of CPU cores
        include(ProcessorCount)
        ProcessorCount(CPU_CORES)
        # Append desired arguments to CppCheck
        list(
                APPEND CMAKE_CXX_CPPCHECK
                # Using the below template will allow jumping to any found error from inside Visual Studio output window by double click
                "--template \"${CMAKE_SOURCE_DIR}/{file}({line}): {severity} ({id}): {message}\""
                # Use all the available CPU cores
                "-j ${CPU_CORES}"
                # Only show found errors
                "--quiet"
                # Desired warning level in CppCheck
                "--enable=style"
                # Optional: suppression file stored in same directory as the top level CMake script
                "--suppressions-list=${CMAKE_SOURCE_DIR}/cppcheck_suppressions.txt"
                # Optional: Use inline suppressions
                "--inline-suppr"
                # Run CppCheck from the working directory, as specified in the add_custom_target command below
                "."
        )
        add_custom_target(ANALYZE_CPPCHECK DEPENDS my_project
                COMMAND ${CMAKE_CXX_CPPCHECK}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                COMMENT "Static code analysis using ${CPP_CHECK_VERSION}"
                )
    endif ()
endif ()
#    list(
#            APPEND CMAKE_CXX_CPPCHECK
#            "--enable=warning"
#            "--inconclusive"
#            "--force"
#            "--inline-suppr"
#            "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
#    )
#endif()