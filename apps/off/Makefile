apps += Off_screen::App
app_headers += apps/off/app.h

app_off_src = $(addprefix apps/off/,\
  app.cpp \
  off_controller.cpp \
  off_view.cpp \
)

apps_src += $(app_off_src)

i18n_files += $(call i18n_without_universal_for,off/i18n/base)

$(eval $(call depends_on_image,apps/off/app.cpp,apps/off/off_icon.png))
$(eval $(call depends_on_image,apps/off/app.cpp,apps/off/off_icon_epsilon.png))