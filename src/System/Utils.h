//
// Created by cyril on 13/05/2022.
//

#ifndef MUSICMECH_SERVER_UTILS_H
#define MUSICMECH_SERVER_UTILS_H

#include <string>
#include <array>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

namespace Utils {
    int hash(std::string key);
    bool sequence_greater_than(sf::Uint16 s1, sf::Uint16 s2);
    std::vector<std::string> split(std::string s, char delim);
    sf::Vector2f normalize(const sf::Vector2f &x);
    float distance(sf::Vector2f a, sf::Vector2f b);
    float distance(const std::array<float, 4> &a, const std::array<float, 4> &b);
    sf::Vector2f remapLength(sf::Vector2f v, float fromMin, float fromMax, float toMin, float toMax, bool clamp = false);
    std::array<float, 4> RGBtoHSV(const sf::Color& color);
    sf::Color HSVtoRGB(const std::array<float, 4> &color);
    std::string paddLeft(std::string s, int nbPad, char padChar = ' ');
    std::array<float, 4> diff(const std::array<float, 4> &a, const std::array<float, 4> &b);
    bool sameSign(float a, float b);
    unsigned int stui(const std::string& str);

    float min(float a, float b);
    float max(float a, float b);
    float sign(float x);

    float sign(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);
    bool pointInTriangle(sf::Vector2f pt, sf::Vector2f v1, sf::Vector2f v2, sf::Vector2f v3);

    inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
    {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }
    inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
    {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }
    inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
    {
        return ltrim(rtrim(s, t), t);
    }
}


#endif //MUSICMECH_SERVER_UTILS_H
