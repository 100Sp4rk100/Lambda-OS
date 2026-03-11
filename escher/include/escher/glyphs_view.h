#ifndef ESCHER_GLYPHS_VIEW_H
#define ESCHER_GLYPHS_VIEW_H

#include <escher/cell_widget.h>
#include <escher/menu_cell.h>
#include <escher/palette.h>
#include <escher/view.h>

#include "apps/theme_gestion/themeGestion.h"

namespace Escher {

class GlyphsView : public View, public CellWidget {
 public:
  GlyphsView(KDGlyph::Format format = {}) { setGlyphFormat(format); }

  KDFont::Size font() const { return m_glyphFormat.style.font; }

  void setGlyphFormat(KDGlyph::Format format);
  void setFont(KDFont::Size font);
  void setTextColor(KDColor textColor);
  void setBackgroundColor(KDColor backgroundColor);
  void setAlignment(float horizontalAlignment, float verticalAlignment);

  // CellWidget
  const View* view() const override { return this; }
  void setHighlighted(bool highlighted) override {
    setBackgroundColor(AbstractMenuCell::BackgroundColor(highlighted));
  }
  bool alwaysAlignWithLabelAsAccessory() const override { return true; }
  bool preventRightAlignedSubLabel(Type type) const override {
    return type == Type::Accessory;
  }

  static KDGlyph::Format k_defaultLabel();
  static KDGlyph::Format k_defaultSubLabel();
  static KDGlyph::Format k_defaultAccessory();

  static KDGlyph::Format FormatForWidgetType(CellWidget::Type type) {
    return type == CellWidget::Type::Label
               ? k_defaultLabel()
               : (type == CellWidget::Type::SubLabel ? k_defaultSubLabel()
                                                     : k_defaultAccessory());
  }

  void defaultInitialization(CellWidget::Type type) override {
    setGlyphFormat(FormatForWidgetType(type));
  }

 protected:
  KDGlyph::Format m_glyphFormat;
};

}  // namespace Escher
#endif
