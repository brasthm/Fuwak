cmake_minimum_required(VERSION 3.17)
project(Fuwak)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuwak
        Fuwak/main.cpp
        src/System/easing.h
        src/System/Utils.cpp
        src/System/RessourceLoader.h
        src/System/RessourceLoader.cpp
        src/System/Utils.h
        src/System/easing.cpp
        src/System/Random.h
        src/System/Interpolable.h
        src/System/DJ.h
        src/Screen/ScreenTestAnim.cpp
        src/Screen/ScreenTestA.h
        src/Screen/ScreenManager.cpp
        src/Screen/ScreenTestC.h
        src/Screen/ScreenTestA.cpp
        src/Screen/ScreenTestB.h
        src/Screen/ScreenManager.h
        src/Screen/ScreenTestUI.cpp
        src/Screen/ScreenTestAnim.h
        src/Screen/ScreenEditMap.h
        src/Screen/ScreenTestB.cpp
        src/Screen/Screen.cpp
        src/Screen/ScreenTestUI.h
        src/Screen/ScreenEditMap.cpp
        src/Screen/ScreenTestC.cpp
        src/Screen/Screen.h
        src/Displayer/Displayer.h
        src/Displayer/CombatDisplayer.h
        src/Displayer/UIDisplayer.cpp
        src/Displayer/MasterDisplayer.h
        src/Displayer/MasterDisplayer.cpp
        src/Displayer/UIDisplayer.h
        src/Displayer/Displayer.cpp
        src/Displayer/ScreenEditMap.h
        src/Displayer/CombatDisplayer.cpp
        src/Displayer/ScreenEditMap.cpp
        src/Model/CombatModel.cpp
        src/Model/UIModel.cpp
        src/Model/CombatModel.h
        src/Model/Combat/BattleEntity.cpp
        src/Model/Combat/BattleEntity.h
        src/Model/Combat/Map.h
        src/Model/Combat/Map.cpp
        src/Model/UI/UIRichText.cpp
        src/Model/UI/UIDialog.cpp
        src/Model/UI/UIText.cpp
        src/Model/UI/UIRichText.h
        src/Model/UI/UIVerticalStacker.h
        src/Model/UI/UIContainer.cpp
        src/Model/UI/UIText.h
        src/Model/UI/UIHorizontalStacker.cpp
        src/Model/UI/UIDialog.h
        src/Model/UI/UIButton.cpp
        src/Model/UI/UIHorizontalStacker.h
        src/Model/UI/UIContainer.h
        src/Model/UI/UIPanel.cpp
        src/Model/UI/UIVerticalStacker.cpp
        src/Model/UI/UIPanel.h
        src/Model/UI/UIButton.h
        src/Model/UI/UIComponant.h
        src/Model/UI/UIComponant.cpp
        src/Model/UIModel.h
        src/main.h
        src/EventHandler/EventHandler.cpp
        src/EventHandler/SFMLEventHandler.h
        src/EventHandler/EventLogger.h
        src/EventHandler/Event.h
        src/EventHandler/EventDispatcher.h
        src/EventHandler/EventDispatcher.cpp
        src/EventHandler/EventReciever.h
        src/EventHandler/SFMLEventHandler.cpp
        src/EventHandler/EventLogger.cpp
        src/EventHandler/EventReciever.cpp
        src/EventHandler/EventHandler.h
        src/EventHandler/Event.cpp
        )

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Fuwak ${SFML_LIBRARIES} Threads::Threads)
endif()