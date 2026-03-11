#include "lambda_controller.h"

namespace LambdaApp{

    LambdaController::LambdaController():
        ViewController(nullptr),
        m_view(){}

    Escher::View* LambdaController::view(){
        return &m_view;
    }

bool LambdaController::handleEvent(Ion::Events::Event event) {
  if (event == Ion::Events::OK || event == Ion::Events::EXE|| event == Ion::Events::Right) {
    m_view.loadMenu();
    return true;
  }
  if (event == Ion::Events::Up) {
    m_view.decreaseRow();
    return true;
  }
  if (event == Ion::Events::Down) {
    m_view.increaseRow();
    return true;
  }
  if (event == Ion::Events::Left || event == Ion::Events::Back) {
    return m_view.PreviousMenu();
  }
  return false;
}
}