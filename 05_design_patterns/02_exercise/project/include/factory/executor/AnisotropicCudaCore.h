//
// Created by student on 12/8/20.
//

#pragma once
#include "Core.h"

namespace factory{
    namespace executor{
        class AnisotropicCudaCore:public Core{
        public:
            explicit AnisotropicCudaCore(int gpuId);

            void execute() override;

        private:
            int gpuId;
        };
    }
}