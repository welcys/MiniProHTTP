file(GLOB SRC_FILES
    threadpool/*.cpp
    main.cpp
)
add_executable(MiniProHTTP ${SRC_FILES})
