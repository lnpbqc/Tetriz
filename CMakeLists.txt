cmake_minimum_required(VERSION 3.22)
project(Tetriz)

set(CXX_STANDARD 20)

# 将 . 目录下的源文件标记为src
aux_source_directory(. src)

add_executable(Tetriz ${src})