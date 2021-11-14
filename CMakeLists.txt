cmake_minimum_required(VERSION 3.19)
project(RandomiesedPlaylist C)

set(CMAKE_C_STANDARD 99)

add_executable(RandomiesedPlaylist main.c library.h artists+songs.c check_artist.c convert_to_sec.c print_in_minutes.c print_playlist.c read.c selection.c shuffle.c sort.c sort_print.c)