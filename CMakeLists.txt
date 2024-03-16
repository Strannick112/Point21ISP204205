cmake_minimum_required(VERSION 3.26)
project(untitled35 C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled35 main.c
        game/Card.h
        game/Card.c
        game/Rang.c
        game/Mast.h
        game/Mast.c
        game/Deck.h
        game/Deck.c
        game/Hand.h
        game/Hand.c
        game/Player.h
        game/Player.c
        game/Game.c)
