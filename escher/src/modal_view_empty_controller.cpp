#include <assert.h>
#include <escher/i18n.h>
#include <escher/modal_view_empty_controller.h>

#include "apps/theme_gestion/themeGestion.h"

namespace Escher {


KDGlyph::Format ModalViewEmptyController::ModalViewEmptyView::k_format(){return {
        .style = {.backgroundColor = Theme::ThemeGestion::getColor("WallScreen"), .font = k_font},
        .horizontalAlignment = KDGlyph::k_alignCenter,
        .verticalAlignment = KDGlyph::k_alignCenter};}

void ModalViewEmptyController::ModalViewEmptyView::drawRect(KDContext *ctx,
                                                            KDRect rect) const {
  ctx->fillRect(bounds(), Theme::ThemeGestion::getColor("WallScreen"));
  drawBorderOfRect(ctx, bounds(), Theme::ThemeGestion::getColor("GrayBright"));
}

void ModalViewEmptyController::ModalViewEmptyView::layoutSubviews(bool force) {
  setChildFrame(&m_messageTextView, bounds(), force);
}

}  // namespace Escher
