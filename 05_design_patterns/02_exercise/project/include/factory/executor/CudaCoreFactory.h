//
// Created by student on 12/8/20.
//

#pragma once
#include "CoreFactory.h"
#include "AcousticCudaCore.h"
#include "ElasticCudaCore.h"
#include "AnisotropicCudaCore.h"

namespace factory{
    namespace executor{
        class CudaCoreFactory:public CoreFactory
        {
        public:
            explicit CudaCoreFactory(int gpuId);

            std::shared_ptr<Core> create(std::string type) override;
        private:
            int gpuId;
        };
    }
}

