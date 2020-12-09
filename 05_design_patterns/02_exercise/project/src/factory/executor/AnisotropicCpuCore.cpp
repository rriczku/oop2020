//
// Created by student on 12/8/20.
//

#include "factory/executor/AnisotropicCpuCore.h"
factory::executor::AnisotropicCpuCore::AnisotropicCpuCore(int threads):threads(threads){}

void factory::executor::AnisotropicCpuCore::execute()
{
    std::cout<<"factory::executor::AnisotropicCpuCore{threads: "<<threads<<"}"<<std::endl;
}