#ifndef LAMBDA_CONTROLLER_H
#define LAMBDA_CONTROLLER_H

#include <escher/view_controller.h>
#include "lambda_view.h"

namespace LambdaApp{

class LambdaController : public Escher::ViewController{
    public:
        LambdaController();
        Escher::View * view() override;
        bool handleEvent(Ion::Events::Event event) override;

    private:
        LambdaView m_view;
};

}
#endif 