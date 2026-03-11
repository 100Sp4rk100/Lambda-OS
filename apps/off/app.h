#ifndef OFF_H
#define OFF_H

#include <escher/app.h>
#include "off_controller.h"

namespace Off_screen {

class App : public Escher::App 
{
public:
  class Descriptor : public Escher::App::Descriptor 
  {
  public:
    I18n::Message name() const override;
    I18n::Message upperName( )const override;
    const Escher::Image * icon() const override;
  };
  class Snapshot : public Escher::App::Snapshot 
  {
  public:
    App * unpack(Escher::Container * container) override;
    Descriptor * descriptor() const override;
  };
  virtual void willBecomeInactive();
private:
  App(Snapshot * snapshot);
  OffController m_offController;
  uint8_t bright;
};

}

#endif
