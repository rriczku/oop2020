//
// Created by student on 12/8/20.
//

#include "factory/executor/CudaCoreFactory.h"
factory::executor::CudaCoreFactory::CudaCoreFactory(int gpuId) : gpuId(gpuId){}

std::shared_ptr<factory::executor::Core> factory::executor::CudaCoreFactory::create(std::string type)
{

    if(type=="anisotropic")
        return std::make_shared<AnisotropicCudaCore>(gpuId);
    if(type=="elastic")
        return std::make_shared<ElasticCudaCore>(gpuId);
    if(type=="acoustic")
        return std::make_shared<AcousticCudaCore>(gpuId);

    throw std::runtime_error("Unsupported Cuda core type: "+type);
}