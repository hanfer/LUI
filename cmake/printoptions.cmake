
message("")
message("Config:")

function(printoption MESSAGE VAR)
    if(VAR)
        message("${MESSAGE} yes")
    else()
        message("${MESSAGE} no")
    endif()
endfunction()

printoption(">> Build examples:" ${BUILD_EXAMPLES})
printoption(">> Build static  :" ${BUILD_STATIC} OR ${BUILD_BOTH})
printoption(">> Build shared  :" ${BUILD_SHARED} OR ${BUILD_BOTH})

message("")
