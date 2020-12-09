//
// Created by student on 12/8/20.
//

#include "factory/executor/CpuCoreFactory.h"
#include "factory/executor/CudaCoreFactory.h"
factory::executor::CpuCoreFactory::CpuCoreFactory(int threads) : threads(threads){}

std::shared_ptr<factory::executor::Core> factory::executor::CpuCoreFactory::create(std::string type)
{

    if(type=="anisotropic")
        return std::make_shared<AnisotropicCpuCore>(threads);
    if(type=="elastic")
        return std::make_shared<ElasticCpuCore>(threads);
    if(type=="acoustic")
        return std::make_shared<AcousticCpuCore>(threads);

    throw std::runtime_error("Unsupported Cuda core type: "+type);
}