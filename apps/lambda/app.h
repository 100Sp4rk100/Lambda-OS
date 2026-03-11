#ifndef LAMBDA_APP_H
#define LAMBDA_APP_H

#include <escher/app.h>
#include "lambda_controller.h"

namespace LambdaApp {

class App : public Escher::App {
 public:
  class Descriptor : public Escher::App::Descriptor {
   public:
    I18n::Message name() const override;
    I18n::Message upperName() const override;
    const Escher::Image * icon() const override;
  };
  class Snapshot : public Escher::App::Snapshot{
   public:
    App *unpack(Escher::Container *container) override;
    const Descriptor *descriptor() const override;
  };
  static App *app() { return static_cast<App *>(Escher::App::app()); }
  Snapshot *snapshot() const {
    return static_cast<Snapshot *>(Escher::App::snapshot());
  }

 private:
  App(Snapshot *snapshot);
  LambdaController m_lambdaController;
};

}

#endif
