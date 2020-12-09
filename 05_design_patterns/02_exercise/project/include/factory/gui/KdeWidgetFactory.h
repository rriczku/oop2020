//
// Created by student on 12/8/20.
//

#pragma once
#include "WidgetFactory.h"
#include "ListKdeWidget.h"
#include "CheckBoxKdeWidget.h"
#include "ButtonKdeWidget.h"

namespace factory{
    namespace gui{
    class KdeWidgetFactory:public WidgetFactory
    {
    public:
        explicit KdeWidgetFactory(int kdeVersion);

        std::shared_ptr<Widget> create(std::string type) override;
    private:
        int kdeVersion;
    };
    }
}

