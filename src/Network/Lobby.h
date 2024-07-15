//
// Created by cyril on 30/05/2022.
//

#ifndef SYNCHRONE_LOBBY_H
#define SYNCHRONE_LOBBY_H

#include <SFML/Network.hpp>
#include <string>

#include "PlayerInfo.h"
#include "../main.h"


enum LobbyStatus {
    LOBBY_AVAILABLE,
    LOBBY_FILLING,
    LOBBY_PLAYING,
    LOBBY_STARTING

};

class Lobby {

private:


public:
    Lobby();
    ~Lobby();

    Lobby(const Lobby&) = default;
    Lobby& operator=(const Lobby&) = default;

    std::string name;
    LobbyStatus status;
    std::vector<PlayerInfo*> players;
    sf::Uint8 nbIn, limit;
    sf::Uint64 startingTime;
    std::string id;

    void startGame();
    void updateGame(sf::Time elapsed);
    void load(const std::string &filename);
};


int findFirstAvailableLobby(const std::vector<Lobby> &lobbyList);
int findFirstAvailablePlayerSpot(const std::vector<Lobby> &lobbyList, int indLobby);
int findLobbyById(const std::vector<Lobby> &lobbyList, std::string id);
int findPlayerInLobby(const std::vector<Lobby> &lobbyList, int index, sf::IpAddress address, unsigned short port);

#endif //MUSICMECH_SERVER_LOBBY_H
