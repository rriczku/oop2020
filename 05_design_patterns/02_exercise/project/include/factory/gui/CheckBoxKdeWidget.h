//
// Created by student on 12/8/20.
//
#pragma once
#include "Widget.h"

namespace factory {
    namespace gui {
        class CheckBoxKdeWidget : public Widget {
        public:

            explicit CheckBoxKdeWidget(int KdeVersion);

            void draw() override;

        private:
            int KdeVersion;
        };
    }
}