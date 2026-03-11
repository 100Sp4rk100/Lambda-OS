apps += LambdaApp::App
app_headers += apps/lambda/app.h

app_lambda_src = $(addprefix apps/lambda/,\
  app.cpp \
  lambda_controller.cpp \
  lambda_view.cpp \
  lambda_text.cpp \
)

apps_src += $(app_lambda_src)

i18n_files += $(call i18n_without_universal_for,lambda/i18n/base)

$(eval $(call depends_on_image,apps/lambda/app.cpp,apps/lambda/lambda_icon.png))