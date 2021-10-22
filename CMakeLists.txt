cmake_minimum_required(VERSION 3.21.3)
project(search)

include_directories($({PROJECT_SOURCE_DIR}))

add_executable(search
	src/main.c
	src/node.c
	src/board.c
	src/search.c
	)

target_compile_options(search PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
