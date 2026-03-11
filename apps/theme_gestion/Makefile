.PHONY: create_background

create_background:
	@python3 -c "import PIL" 2>/dev/null || pip3 install Pillow
	@python3 apps/theme_gestion/pngToCArray.py

$(call object_for,apps/theme_gestion/backgroundGestion.cpp): create_background