#include "app.h"

#include "apps/i18n.h"
#include "apps/apps_container.h"

namespace LambdaApp {
I18n::Message App::Descriptor::name() const { return I18n::Message::LambdaApp; }

I18n::Message App::Descriptor::upperName() const {
  return I18n::Message::LambdaAppCapital;
}

const Escher::Image* App::Descriptor::icon() const { 
  return Theme::ThemeGestion::getIconImage("LambdaIcon"); 
}

App* App::Snapshot::unpack(Escher::Container* container) {
  return new (container->currentAppBuffer()) App(this);
}

constexpr static App::Descriptor sDescriptor;

const App::Descriptor* App::Snapshot::descriptor() const {
  return &sDescriptor;
}

App::App(Snapshot* snapshot)
    : Escher::App(snapshot, &m_lambdaController),
      m_lambdaController() {}

}