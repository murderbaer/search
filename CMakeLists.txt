cmake_minimum_required(VERSION 3.21.3)
project(search)

include_directories($({PROJECT_SOURCE_DIR}))

add_executable(search
	src/main.c
	src/node.c
	src/board.c
	src/search.c
	)

