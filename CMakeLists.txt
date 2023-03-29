cmake_minimum_required(VERSION 3.15)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Game.cpp Game.h
        GameFormat.cpp GameFormat.h
        Board.cpp Board.h
        Player.cpp Player.h
        Move.cpp Move.h
        Ship.cpp Ship.h
        InputValidation.cpp InputValidation.h
        HumanPlayer.cpp HumanPlayer.h
        AiPlayer.cpp AiPlayer.h
        CheatingAI.cpp CheatingAI.h
        RandomAI.cpp RandomAI.h
        SearchAndDestroyAI.cpp SearchAndDestroyAI.h)
target_compile_options(BattleShip PRIVATE -Wall -Wextra -Werror)
