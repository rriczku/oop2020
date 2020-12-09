//
// Created by student on 12/8/20.
//

#pragma once
#include <memory>
#include <iostream>
namespace factory {
    namespace executor {
        class Core {
        public:
            virtual ~Core() = default;
            virtual void execute()=0;
        };
    }

}