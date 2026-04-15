
# ──────────────────────────────────────────────────────────────────────────────
# Theos Makefile — GameMenuUI.dylib
# ──────────────────────────────────────────────────────────────────────────────
#
# วิธีใช้:
#   1. ติดตั้ง Theos  →  https://theos.dev/docs/installation
#   2. export THEOS=/opt/theos
#   3. วาง folder นี้แล้วรัน:  make
#   4. ไฟล์ที่ได้อยู่ใน .theos/obj/debug/GameMenuUI.dylib
#
# หรือ compile ด้วย clang ตรงๆ (ไม่ต้อง Theos):
#   clang -arch arm64 -isysroot $(xcrun --sdk iphoneos --show-sdk-path) \
#         -framework UIKit -framework Foundation \
#         -dynamiclib -o GameMenuUI.dylib src/GameMenuUI.m
# ──────────────────────────────────────────────────────────────────────────────

TARGET  := iphone:clang:latest:14.0
INSTALL_TARGET_PROCESSES := SpringBoard

include $(THEOS)/makefiles/common.mk

# ─── Library (dylib) ─────────────────────────────────────────────────────────
LIBRARY_NAME := GameMenuUI

GameMenuUI_FILES    := src/GameMenuUI.m
GameMenuUI_CFLAGS   := -fobjc-arc -Wall -Wextra -O2
GameMenuUI_LDFLAGS  := -framework UIKit -framework Foundation -framework QuartzCore

include $(THEOS_MAKE_PATH)/library.mk
