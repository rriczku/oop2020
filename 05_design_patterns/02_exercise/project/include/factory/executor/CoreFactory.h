//
// Created by student on 12/8/20.
//

#pragma once
#include "Core.h"
#include <memory>

namespace factory{
    namespace executor{
        class CoreFactory{
        public:
            virtual ~CoreFactory()=default;

            virtual std::shared_ptr<Core> create(std::string equation)=0;
        };
    }
}