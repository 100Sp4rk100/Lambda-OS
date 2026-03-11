# You can override those settings on the command line

PLATFORM ?= device
DEBUG ?= 0
DEVELOPMENT ?= 0

EPSILON_VERSION ?= 23.2.6
EXTERNAL_APPS_API_LEVEL ?= 0
EPSILON_APPS ?= calculation graph code statistics distributions inference solver sequence regression elements finance settings off lambda
EPSILON_GETOPT ?= 0
ESCHER_LOG_EVENTS_BINARY ?= 0
ESCHER_LOG_EVENTS_NAME ?= $(DEBUG)
I18N_COMPRESS ?= 0
ASSERTIONS ?= $(DEBUG)
HWTEST_ALL_KEYS ?= 0
VALGRIND ?= 0

supported_locales := fr
EPSILON_I18N ?= $(supported_locales)

supported_countries := FR
EPSILON_COUNTRIES ?= $(supported_countries)

