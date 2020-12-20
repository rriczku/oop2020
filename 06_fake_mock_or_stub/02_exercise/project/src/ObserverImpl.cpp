//
// Created by student on 12/19/20.
//
#include <ObserverImpl.h>

#include "Observer.h"

void ObserverImpl::remember(std::string question, std::string answer) {

    answers[question] = answer;
}

std::string ObserverImpl::answer(std::string question) const {

    if (not answers.count(question)) {
        return "I do not know...";
    }

    return answers.at(question);
}
