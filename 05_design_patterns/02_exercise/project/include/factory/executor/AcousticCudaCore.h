//
// Created by student on 12/8/20.
//

#pragma once
#include "Core.h"

namespace factory{
    namespace executor{
        class AcousticCudaCore:public Core{
        public:
            explicit AcousticCudaCore(int gpuId);

            void execute() override;

        private:
            int gpuId;
        };
    }
}