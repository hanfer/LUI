option(BUILD_EXAMPLES "Do you want to build the example programs?" 0)
option(BUILD_SHARED   "Do you want to build a shared lib?"         0)
option(BUILD_STATIC   "Do you want to build a static lib?"         0)
option(BUILD_BOTH     "Do you want to build both lib types?"       0)

if(NOT BUILD_SHARED AND NOT BUILD_BOTH)
    if(NOT BUILD_STATIC)
        set(BUILD_SHARED 1)
    endif()
endif()
