#ifndef CODE_SCRIPT_TEMPLATE_H
#define CODE_SCRIPT_TEMPLATE_H

#include "script.h"

namespace Code {

class ScriptTemplate {
 public:
  constexpr ScriptTemplate(const char* name, const char* content)
      : m_name(name), m_content(content) {}
  static const ScriptTemplate* Empty();
  const char* name() const { return m_name; }
  const char* content() const { return m_content; }

  static const ScriptTemplate* Get();
  static const ScriptTemplate* Set();
  static const ScriptTemplate* Reset();

 private:
  const char* m_name;
  const char* m_content;
};

}  // namespace Code

#endif
