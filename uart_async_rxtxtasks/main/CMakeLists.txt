idf_component_register(SRC_DIRS "src"
                    INCLUDE_DIRS "include"
                    PRIV_REQUIRES "toolbox"
                    )


set_source_files_properties("${app_sources}"
                    PROPERTIES COMPILE_FLAGS
                    -Wall -Wextra -Werror
)


