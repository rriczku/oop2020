//
// Created by student on 12/8/20.
//
#pragma once

namespace observer {
        class Observer {
        public:
            virtual ~Observer() = default;
            virtual void notify(float)=0;
        };
}