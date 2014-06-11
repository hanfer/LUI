macro(CreateVSDir)
	foreach(FILE ${ARGV}) 
		get_filename_component(PARENT_DIR "${FILE}" PATH)

		string(REGEX REPLACE "${CMAKE_CURRENT_LIST_DIR}(\\/)?(src|include)?/?" "" GROUP "${PARENT_DIR}")
		string(REPLACE "/" "\\" GROUP "${GROUP}")
 
		# group into "Source Files" and "Header Files"
		if ("${FILE}" MATCHES ".*\\.cpp")
			set(GROUP "Source Files\\${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.h")
			set(GROUP "Header Files\\${GROUP}")
		endif()

		source_group("${GROUP}" FILES "${FILE}")
	endforeach()
endmacro()