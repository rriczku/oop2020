//
// Created by student on 12/8/20.
//
#pragma once
#include "CoreFactory.h"
#include "AcousticCpuCore.h"
#include "ElasticCpuCore.h"
#include "AnisotropicCpuCore.h"

namespace factory{
    namespace executor{
        class CpuCoreFactory:public CoreFactory
        {
        public:
            explicit CpuCoreFactory(int threads);

            std::shared_ptr<Core> create(std::string type) override;
        private:
            int threads;
        };
    }
}
