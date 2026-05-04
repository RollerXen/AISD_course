# Лабораторная работа 1: Бинарное дерево поиска

# Функция для тестирования одного студента
function(test_bst_student STUDENT_NAME STUDENT_PATH)
    # Проверяем наличие файлов
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT_PATH}/binTrees.h" AND 
       EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT_PATH}/binTrees.cpp")
        
        set(TEST_NAME bst_${STUDENT_NAME})
        
        add_executable(${TEST_NAME} 
            ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/${STUDENT_PATH}/binTrees.cpp
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
test_bst_student(Dekterev   "Dekterev")
test_bst_student(Kalimanov   "Kalimanov")
test_bst_student(Kiselev  "Kiselev")
test_bst_student(Kruglov   "Kruglov")
test_bst_student(Kulkov  "Kulkov")
test_bst_student(Nicolic  "Nicolic")
test_bst_student(Nunies  "Nunies")
test_bst_student(Sharaf  "Sharaf")
test_bst_student(Shebelov  "Shebelov")
test_bst_student(Teplov  "Teplov")
test_bst_student(Zhukov  "Zhukov")