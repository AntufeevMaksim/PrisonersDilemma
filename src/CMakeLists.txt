# Создаём исполняемый файл из исходников
add_executable(out.o
    main.cpp
    Simulator/input_data.cpp
    Simulator/prisoner_simulator.cpp
)

# Указываем, где искать заголовки
target_include_directories(out.o
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include/Strategies  # Путь к заголовкам
        ${CMAKE_SOURCE_DIR}/include/Simulator  # Путь к заголовкам
)

# Если нужны внешние библиотеки (например, Boost, OpenMP)
# target_link_libraries(my_app PRIVATE Boost::boost)