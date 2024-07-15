//
// Created by cyril on 20/05/2024.
//

#ifndef TESTANIMATION_INTERPOLABLE_H
#define TESTANIMATION_INTERPOLABLE_H

#include "easing.h"

#include "SFML/System.hpp"

template <class T>
class Interpolable {
public:
    Interpolable(easing_functions type): type_(type), prev_(), target_() {
        timeToComplete_ = 1;
        startTime_.restart();
    };

    T get(){
        float fracTime = startTime_.getElapsedTime().asSeconds();

        if (timeToComplete_ != 0)
            fracTime /= timeToComplete_;
        else
            fracTime = 1;

        if(fracTime > 1)
            fracTime = 1;

        return prev_ + (target_ - prev_) * static_cast<float>(getEasingFunction(type_)(fracTime));
    };

    void set(T val, float timeToComplete){
        timeToComplete_ = timeToComplete;
        set(val);
    };

    void set(T val){
        prev_ = target_;
        target_ = val;

        startTime_.restart();
    };

    void setInstant(T val){
        prev_ = val;
        target_ = val;
    };

    void setEasingType(easing_functions type){
        type_ = type;
    };

private:
    easing_functions type_;
    T target_, prev_;
    float timeToComplete_;
    sf::Clock startTime_;
};

using IFloat = Interpolable<float>;
using IVector2f = Interpolable<sf::Vector2f>;



#endif //TESTANIMATION_INTERPOLABLE_H
