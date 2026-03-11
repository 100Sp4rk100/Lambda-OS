#include <escher/transparent_image_view_moded.h>
extern "C" {
#include <assert.h>
}
#include <ion.h>

#include "apps/theme_gestion/themeGestion.h"

namespace Escher {

TransparentImageViewModed::TransparentImageViewModed() : View(), m_image(nullptr) {}

void TransparentImageViewModed::drawRect(KDContext *ctx, KDRect rect) const {
  if (m_image == nullptr) {
    return;
  }

  if (Theme::ThemeGestion::isSquareIcon()) {
    square(ctx, rect);
  }else{
    circle(ctx, rect);
  }
  
}

void TransparentImageViewModed::square(KDContext *ctx, KDRect rect) const {
  int width = bounds().width();
  int height = bounds().height();

  KDColor pixelBuffer[k_maxPixelBufferSize];
  int pixelBufferSize = width * height;

  assert(pixelBufferSize <= k_maxPixelBufferSize);
  assert(Ion::stackSafe());

  Ion::decompress(
      m_image->compressedPixelData(),
      reinterpret_cast<uint8_t *>(pixelBuffer),
      m_image->compressedPixelDataSize(),
      pixelBufferSize * sizeof(KDColor)
  );

  Theme::ThemeGestion::editImageWithDynamicColor(pixelBuffer, pixelBufferSize);

  KDColor screenBuffer[k_maxPixelBufferSize];
  ctx->getPixels(bounds(), screenBuffer);

  int cornerRadius = 10;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {

      int i = y * width + x;
      
      int distTopLeft = 0, distTopRight = 0, distBottomLeft = 0, distBottomRight = 0;
      
      if (x < cornerRadius && y < cornerRadius) {
        int dx = cornerRadius - x;
        int dy = cornerRadius - y;
        distTopLeft = dx * dx + dy * dy;
      }
      
      if (x >= width - cornerRadius && y < cornerRadius) {
        int dx = x - (width - cornerRadius - 1);
        int dy = cornerRadius - y;
        distTopRight = dx * dx + dy * dy;
      }
      
      if (x < cornerRadius && y >= height - cornerRadius) {
        int dx = cornerRadius - x;
        int dy = y - (height - cornerRadius - 1);
        distBottomLeft = dx * dx + dy * dy;
      }
      
      if (x >= width - cornerRadius && y >= height - cornerRadius) {
        int dx = x - (width - cornerRadius - 1);
        int dy = y - (height - cornerRadius - 1);
        distBottomRight = dx * dx + dy * dy;
      }
      
      int maxDist = cornerRadius * cornerRadius;
      
      bool isInCorner = (distTopLeft > maxDist && x < cornerRadius && y < cornerRadius) ||
                        (distTopRight > maxDist && x >= width - cornerRadius && y < cornerRadius) ||
                        (distBottomLeft > maxDist && x < cornerRadius && y >= height - cornerRadius) ||
                        (distBottomRight > maxDist && x >= width - cornerRadius && y >= height - cornerRadius);
      
      if (isInCorner) {
        pixelBuffer[i] = screenBuffer[i];
      }
    }
  }

  ctx->fillRectWithPixels(bounds(), pixelBuffer, nullptr);
}

void TransparentImageViewModed::circle(KDContext *ctx, KDRect rect) const {
  int width = bounds().width();
  int height = bounds().height();

  KDColor pixelBuffer[k_maxPixelBufferSize];
  int pixelBufferSize = width * height;

  assert(pixelBufferSize <= k_maxPixelBufferSize);
  assert(Ion::stackSafe());

  Ion::decompress(
      m_image->compressedPixelData(),
      reinterpret_cast<uint8_t *>(pixelBuffer),
      m_image->compressedPixelDataSize(),
      pixelBufferSize * sizeof(KDColor)
  );

  Theme::ThemeGestion::editImageWithDynamicColor(pixelBuffer, pixelBufferSize);

  KDColor screenBuffer[k_maxPixelBufferSize];
  ctx->getPixels(bounds(), screenBuffer);

  int cx = width / 2;
  int cy = height / 2;

  int radius = (width < height) ? width / 2 : height / 2;

  int radiusInner = radius - 1;
  int radiusOuter = radius + 1;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {

      int i = y * width + x;

      int dx = x - cx;
      int dy = y - cy;

      int dist2 = dx * dx + dy * dy;
      int innerDist2 = radiusInner * radiusInner;
      int outerDist2 = radiusOuter * radiusOuter;

      if (dist2 > outerDist2) {
        pixelBuffer[i] = screenBuffer[i];
      }

      else if (dist2 > innerDist2 && dist2 <= outerDist2) {
        int blendFactor = (outerDist2 - dist2) << 4;
        blendFactor = blendFactor / ((radiusOuter - radiusInner) * (radiusOuter - radiusInner));
        blendFactor = (blendFactor > 255) ? 255 : blendFactor;
        
        pixelBuffer[i] = KDColor::Blend(
            pixelBuffer[i],
            screenBuffer[i],
            static_cast<uint8_t>(blendFactor)
        );
      }
    }
  }

  ctx->fillRectWithPixels(bounds(), pixelBuffer, nullptr);
}

void TransparentImageViewModed::setImage(const Image *image) {
  if (image != m_image) {
    m_image = image;
    markWholeFrameAsDirty();
  }
}

}  // namespace Escher
