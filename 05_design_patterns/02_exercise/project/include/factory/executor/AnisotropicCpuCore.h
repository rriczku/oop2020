//
// Created by student on 12/8/20.
//

#pragma once
#include "Core.h"

namespace factory{
    namespace executor{
        class AnisotropicCpuCore:public Core{
        public:
            explicit AnisotropicCpuCore(int threads);

            void execute() override;

        private:
            int threads;
        };
    }
}