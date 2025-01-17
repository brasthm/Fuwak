//
// Created by cyril on 13/05/2022.
//

#include "Utils.h"

#include <cmath>
#include <sstream>

int Utils::hash(std::string key) {
    const int PRIME_CONST = 2;

    int hashCode = 0;
    for (int i = 0; i < key.length(); i++) {
        hashCode += key[i] * pow(PRIME_CONST, i);
        hashCode = hashCode % 16777216;
    }

    return hashCode;
}

bool Utils::sequence_greater_than(sf::Uint16 s1, sf::Uint16 s2) {
    return ( ( s1 > s2 ) && ( s1 - s2 <= 32768 ) ) ||
           ( ( s1 < s2 ) && ( s2 - s1  > 32768 ) );

}

std::vector<std::string> Utils::split(std::string s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
        // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
    }
    return elems;
}

sf::Vector2f Utils::normalize(const sf::Vector2f& x)
{
    float norm = sqrt(x.x * x.x + x.y * x.y);
    return x / norm;
}

float Utils::distance(sf::Vector2f a, sf::Vector2f b) {
    auto diff = a - b;
    return std::sqrt(diff.x * diff.x + diff.y * diff.y);
}

sf::Vector2f Utils::remapLength(sf::Vector2f v, float fromMin, float fromMax, float toMin, float toMax, bool clamp)
{
    float length = std::sqrt(v.x * v.x + v.y * v.y);
    sf::Vector2f dir = (length > 0) ? v / length : v;
    length = (length - fromMin) / (fromMax - fromMin) * (toMax - toMin) + toMin;
    if (clamp)
        length = std::clamp(length, toMin, toMax);
    return dir * length;
}

std::array<float, 4> Utils::RGBtoHSV(const sf::Color &color) {
    float R = color.r / 255.f;
    float G = color.g / 255.f;
    float B = color.b / 255.f;
    float A = color.a;

    float M = std::max({ R, G, B });
    float m = std::min({ R, G, B });
    float C = M - m; // Chroma

    float H = 0.f; // Hue
    float S = 0.f; // Saturation
    float V = 0.f; // Value

    if (C != 0.f)
    {
        if (M == R)
            H = std::fmod(((G - B) / C), 6.f);
        else if (M == G)
            H = ((B - R) / C) + 2;
        else if (M == B)
            H = ((R - G) / C) + 4;

        H *= 60;
    }

    if (H < 0.f)
        H += 360;

    V = M;

    if (V != 0.f)
        S = C / V;

    return { H, S, V, A };
}

sf::Color Utils::HSVtoRGB(const std::array<float, 4> &color) {

    float H, S, V, A;
    H = color[0];
    S = color[1];
    V = color[2];
    A = color[3];

    float C = S * V; // Chroma
    float HPrime = std::fmod(H / 60, 6.f); // H'
    float X = C * (1 - std::fabs(std::fmod(HPrime, 2.f) - 1));
    float M = V - C;

    float R = 0.f;
    float G = 0.f;
    float B = 0.f;

    switch (static_cast<int>(HPrime))
    {
        case 0: R = C; G = X;        break; // [0, 1)
        case 1: R = X; G = C;        break; // [1, 2)
        case 2:        G = C; B = X; break; // [2, 3)
        case 3:        G = X; B = C; break; // [3, 4)
        case 4: R = X;        B = C; break; // [4, 5)
        case 5: R = C;        B = X; break; // [5, 6)
    }

    R += M;
    G += M;
    B += M;

    sf::Color color2;
    color2.r = static_cast<sf::Uint8>(std::round(R * 255));
    color2.g = static_cast<sf::Uint8>(std::round(G * 255));
    color2.b = static_cast<sf::Uint8>(std::round(B * 255));
    color2.a = A;

    return color2;
}

std::string Utils::paddLeft(std::string s, int nbPad, char padChar) {
    std::string res = s;
    if(nbPad > s.size())
        res = s.insert(0, nbPad - s.size(), padChar);
    return res;
}

std::array<float, 4> Utils::diff(const std::array<float, 4> &a, const std::array<float, 4> &b) {
    std::array<float, 4> res{0};
    for(int i = 0; i < res.size(); i++) {
        res[i] = a[i] - b[i];
    }
    return res;
}

float Utils::distance(const std::array<float, 4> &a, const std::array<float, 4> &b) {
    auto d = diff(a, b);
    float s = 0;
    for(float i : d) {
        s += i*i;
    }
    return std::sqrt(s);
}

bool Utils::sameSign(float a, float b) {
    return ((a<0) == (b<0));
}

unsigned int Utils::stui(const std::string& str)
{
    unsigned int x;
    std::stringstream ss;
    ss << std::hex << str;
    ss >> x;
    return x;
}

float Utils::min(float a, float b)
{
    return a < b ? a : b;
}

float Utils::max(float a, float b)
{
    return a > b ? a : b;
}

float Utils::sign(float x)
{
    if (x == 0) return 1;
    return abs(x)/x;
}

float Utils::sign(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool Utils::pointInTriangle(sf::Vector2f pt, sf::Vector2f v1, sf::Vector2f v2, sf::Vector2f v3)
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}
