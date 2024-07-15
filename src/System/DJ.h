//
// Created by cyril on 22/05/2022.
//

#ifndef MUSICMECH_CLIENT_DJ_H
#define MUSICMECH_CLIENT_DJ_H

#include <SFML/Audio.hpp>


#include "RessourceLoader.h"

static constexpr int DJ_NB_MAX_MUSIC = 5;
static constexpr int DJ_NB_MAX_SOUND = 100;

class DJ {
private:
    std::vector<sf::Sound> sounds_;
    std::vector<sf::Music> musics_;

    sf::Clock clock_;
    sf::Time elapsed_;

    int currentSound_;
    int currentMusic_;

    inline static DJ *djInstance_;

    DJ() : sounds_(DJ_NB_MAX_SOUND), musics_(DJ_NB_MAX_MUSIC){
        currentSound_ = 0;
        currentMusic_ = 0;
        clock_.restart();

        for (int i = 0; i < DJ_NB_MAX_SOUND; i++) {
            sounds_[i].setVolume(10);
        }
    };

    inline ~DJ() {
        delete djInstance_;
    };

    inline static DJ *getDjInstance() {
        if (!djInstance_)
            djInstance_ = new DJ();
        return djInstance_;
    };



    int playSound_(const std::string& path) {
        
        if(clock_.getElapsedTime() > sf::milliseconds(30)) {
            clock_.restart();

            int returnval = currentSound_;

            sounds_[currentSound_].setBuffer(RessourceLoader::getSoundBuffer(path));
            sounds_[currentSound_].play();

            currentSound_++;
            currentSound_  = currentSound_ % DJ_NB_MAX_SOUND;

            return returnval;
        }


        return 0;
    };

    int playMusic_(const std::string& path) {
        int returnval = currentSound_;

        musics_[currentSound_].openFromFile(RessourceLoader::getPath(path));
        musics_[currentSound_].play();

        currentMusic_++;
        currentMusic_  = currentMusic_ % DJ_NB_MAX_MUSIC;

        return returnval;
    };


public:
    inline static int playSound(const std::string& path) {
        return getDjInstance()->playSound_(path);
    };

    inline static int playMusic(const std::string& path) {
        return  getDjInstance()->playMusic_(path);
    };


    DJ(const DJ&) = delete;
    DJ& operator= (const DJ) = delete;

};


#endif //MUSICMECH_CLIENT_DJ_H
