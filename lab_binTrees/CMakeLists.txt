# Лабораторная работа 1: Бинарное дерево поиска

# Функция для тестирования одного студента
function(test_bst_student STUDENT_NAME STUDENT_PATH)
    # Проверяем наличие файлов
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT_PATH}/bst.h" AND 
       EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT_PATH}/bst.cpp")
        
        set(TEST_NAME bst_${STUDENT_NAME})
        
        add_executable(${TEST_NAME} 
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT_PATH}/binTree.cpp
        )
        
        target_include_directories(${TEST_NAME} PRIVATE 
            ${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT_PATH}
        )
        
        target_link_libraries(${TEST_NAME} 
            GTest::gtest_main
            GTest::gmock
        )
        
        add_test(NAME BST_${STUDENT_NAME} COMMAND ${TEST_NAME})
        
    endif()
endfunction()

# Регистрируем студентов для первой лабы
test_bst_student(ivanov   "ivanov")
test_bst_student(petrov   "petrov")
test_bst_student(sidorov  "sidorov")
test_bst_student(kozlov   "kozlov")
test_bst_student(smirnov  "smirnov")