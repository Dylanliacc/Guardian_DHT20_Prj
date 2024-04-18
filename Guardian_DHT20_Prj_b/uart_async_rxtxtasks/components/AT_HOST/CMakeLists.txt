FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/components/AT_HOST/**)
idf_component_register(SRCS "AT_HOST.c"  "${app_sources}"
                    INCLUDE_DIRS "include"
                    PRIV_REQUIRES "toolbox" "dht20"
                    )
set_source_files_properties("${app_sources}"
                    PROPERTIES COMPILE_FLAGS
                    -Wall -Wextra -Werror
)
