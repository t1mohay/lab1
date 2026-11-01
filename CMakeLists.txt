cmake_minimum_required(VERSION 3.25)
project(lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab1 src/main.cpp)

if(MSVC)
    # /utf-8: исходник в UTF-8, иначе MSVC прочитает кириллицу как cp1251.
    target_compile_options(lab1 PRIVATE /W4 /utf-8)

    # Программе с MSVC ASan нужна DLL рантайма санитайзера. Она лежит
    # рядом с cl.exe, поэтому копируем её к lab1.exe после сборки.
    if(CMAKE_CXX_FLAGS MATCHES "/fsanitize=address")
        get_filename_component(msvc_bin_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
        add_custom_command(TARGET lab1 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${msvc_bin_dir}/clang_rt.asan_dynamic-x86_64.dll"
                $<TARGET_FILE_DIR:lab1>)
    endif()
else()
    target_compile_options(lab1 PRIVATE -Wall -Wextra)
endif()

# Каждый сценарий с ошибкой - отдельный тест, чтобы ctest показал,
# какая именно проверка упала.
enable_testing()
foreach(scenario array uaf overflow leak)
    add_test(NAME ${scenario} COMMAND lab1 ${scenario})
endforeach()
