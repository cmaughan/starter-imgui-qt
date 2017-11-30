
FILE(GLOB_RECURSE FOUND_TEST_SOURCES "*.test.cpp")

LIST(APPEND TEST_SOURCES
    ${FOUND_TEST_SOURCES}
    src/tests/main-tests.cpp
)


    
