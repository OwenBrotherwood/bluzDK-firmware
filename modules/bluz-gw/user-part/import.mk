USER_PART_MODULE_VERSION ?= 4
USER_PART_MODULE_PATH ?= $(PROJECT_ROOT)/modules/bluz-gw/user-part
include $(call rwildcard,$(USER_PART_MODULE_PATH)/,include.mk)

