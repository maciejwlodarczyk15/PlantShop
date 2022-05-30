
project(Library)

#cpp biblioteki
set(SOURCE_FILES
        src/model/Client.cpp
        src/model/Order.cpp
        src/model/Product.cpp
        src/model/Seed.cpp
        src/model/Seedle.cpp

        src/repositories/ClientRepository.cpp
        src/repositories/OrderRepository.cpp
        src/repositories/ProductRepository.cpp

        src/exceptions/ClientException.cpp
        src/exceptions/OrderException.cpp
        src/exceptions/ProductException.cpp

        src/managers/ProductManager.cpp
        src/managers/OrderManager.cpp
        src/managers/ClientManager.cpp
        )

add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include include/model include/repositories)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#cpp testow
set(SOURCE_TEST_FILES
    test/ClientTest.cpp
    test/OrderTest.cpp
    test/master.cpp
    test/SeedleTest.cpp
    test/SeedTest.cpp
    test/ClientRepositoryTest.cpp
    test/ProductRepositoryTest.cpp
    test/OrderRepositoryTest.cpp
    test/ClientManagerTest.cpp
    test/ProductManagerTest.cpp
    test/OrderManagerTest.cpp
    )

add_executable (LibraryTest ${SOURCE_TEST_FILES})

target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})