# Лабораторная работа 1: Бинарное дерево
# Файлы студентов: binTrees.h, binTrees.cpp

function(is_student_folder FOLDER_NAME RESULT)
    if(FOLDER_NAME STREQUAL "tests" OR 
       FOLDER_NAME STREQUAL "build" OR 
       FOLDER_NAME STREQUAL ".github" OR
       FOLDER_NAME MATCHES "\\.")
        set(${RESULT} FALSE PARENT_SCOPE)
    else()
        set(${RESULT} TRUE PARENT_SCOPE)
    endif()
endfunction()

# Получаем список всех подпапок
file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
set(STUDENT_FOLDERS "")

foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${SUBDIR})
        is_student_folder(${SUBDIR} IS_STUDENT)
        if(IS_STUDENT)
            list(APPEND STUDENT_FOLDERS ${SUBDIR})
        endif()
    endif()
endforeach()

message(STATUS "lab1_binTree: Found students: ${STUDENT_FOLDERS}")

# Для каждого студента создаём тест
foreach(STUDENT ${STUDENT_FOLDERS})
    set(STUDENT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT})
    
    # Проверяем наличие файлов binTrees.h и binTrees.cpp
    if(EXISTS ${STUDENT_PATH}/binTrees.h AND EXISTS ${STUDENT_PATH}/binTrees.cpp)
        set(TEST_NAME bintree_${STUDENT})
        
        add_executable(${TEST_NAME} 
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_binTree.cpp
            ${STUDENT_PATH}/binTrees.cpp
        )
        
        target_include_directories(${TEST_NAME} PRIVATE 
            ${STUDENT_PATH}
        )
        
        target_link_libraries(${TEST_NAME} 
            GTest::gtest_main
            GTest::gmock
        )
        
        add_test(NAME BinTree_${STUDENT} COMMAND ${TEST_NAME})
        
        message(STATUS "  ✅ Added tests for ${STUDENT}")
    else()
        message(WARNING "  ⚠️ Student ${STUDENT} missing binTrees.h or binTrees.cpp - skipping")
    endif()
endforeach()

list(LENGTH STUDENT_FOLDERS STUDENT_COUNT)
if(STUDENT_COUNT EQUAL 0)
    message(WARNING "lab1_binTree: No student folders found!")
endif()