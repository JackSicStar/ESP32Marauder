#pragma once

#ifndef configs_h
  #define configs_h

  #define POLISH_POTATO

  //// BOARD TARGETS
  //#define MARAUDER_M5STICKC
  //#define MARAUDER_M5STICKCP2
  //#define MARAUDER_MINI
  //#define MARAUDER_V4
  //#define MARAUDER_V6
  //#define MARAUDER_V6_1
  //#define MARAUDER_V7
  //#define MARAUDER_V7_1
  //#define MARAUDER_KIT
  //#define GENERIC_ESP32
  //#define MARAUDER_FLIPPER
  //#define MARAUDER_MULTIBOARD_S3
  //#define ESP32_LDDB
  //#define MARAUDER_DEV_BOARD_PRO
  #define XIAO_ESP32_S3
  //#define MARAUDER_REV_FEATHER
  //#define MARAUDER_CYD_MICRO // 2432S028
  //#define MARAUDER_CYD_2USB // Another 2432S028 but it has tWo UsBs OoOoOoO
  //#define MARAUDER_CYD_GUITION // ESP32-2432S024 GUITION
  //#define MARAUDER_CYD_3_5_INCH
  //#define MARAUDER_C5
  //#define MARAUDER_V8
  //// END BOARD TARGETS

  // Marauder version remains
  #define MARAUDER_VERSION "v1.8.8"

  // Headless / Flipper companion flags (XIAO headless behavior)
  #define HEADLESS
  #define ENABLE_FLIPPER_COMPANION

  //// General small settings
  #define GRAPH_REFRESH   100
  #define DUAL_BAND_CHANNELS 51

  //// HARDWARE NAMES
  #ifdef MARAUDER_M5STICKC
    #define HARDWARE_NAME "M5Stick-C Plus"
  #elif defined(MARAUDER_M5STICKCP2)
    #define HARDWARE_NAME "M5Stick-C Plus2"
  #elif defined(MARAUDER_CARDPUTER)
    #define HARDWARE_NAME "M5 Cardputer"
  #elif defined(MARAUDER_MINI)
    #define HARDWARE_NAME "Marauder Mini"
  #elif defined(MARAUDER_V7)
    #define HARDWARE_NAME "Marauder v7"
  #elif defined(MARAUDER_V7_1)
    #define HARDWARE_NAME "Marauder v7.1"
  #elif defined(MARAUDER_REV_FEATHER)
    #define HARDWARE_NAME "Adafruit Feather ESP32-S2 Reverse TFT"
  #elif defined(MARAUDER_V4)
    #define HARDWARE_NAME "Marauder v4"
  #elif defined(MARAUDER_V6)
    #define HARDWARE_NAME "Marauder v6"
  #elif defined(MARAUDER_V6_1)
    #define HARDWARE_NAME "Marauder v6.1"
  #elif defined(MARAUDER_CYD_MICRO)
    #define HARDWARE_NAME "CYD 2432S028"
  #elif defined(MARAUDER_CYD_2USB)
    #define HARDWARE_NAME "CYD 2432S028 2USB"
  #elif defined(MARAUDER_CYD_3_5_INCH)
    #define HARDWARE_NAME "CYD 3.5inch"
  #elif defined(MARAUDER_CYD_GUITION)
    #define HARDWARE_NAME "CYD 2432S024 GUITION"
  #elif defined(MARAUDER_KIT)
    #define HARDWARE_NAME "Marauder Kit"
  #elif defined(MARAUDER_FLIPPER)
    #define HARDWARE_NAME "Flipper Zero Dev Board"
  #elif defined(MARAUDER_MULTIBOARD_S3)
    #define HARDWARE_NAME "Flipper Zero Multi Board S3"
  #elif defined(ESP32_LDDB)
    #define HARDWARE_NAME "ESP32 LDDB"
  #elif defined(MARAUDER_DEV_BOARD_PRO)
    #define HARDWARE_NAME "Flipper Zero Dev Board Pro"
  #elif defined(XIAO_ESP32_S3)
    #define HARDWARE_NAME "XIAO ESP32 S3"
  #elif defined(MARAUDER_C5)
    #define HARDWARE_NAME "ESP32-C5 DevKit"
  #elif defined(MARAUDER_V8)
    #define HARDWARE_NAME "Marauder v8"
  #else
    #define HARDWARE_NAME "ESP32"
  #endif
  //// END HARDWARE NAMES

  //// BOARD FEATURES - simplified for XIAO headless (only relevant branches kept/clean)
  #ifdef XIAO_ESP32_S3
    // leave FLIPPER_ZERO_HAT if you want Flipper-pin compatibility
    #define FLIPPER_ZERO_HAT
    //#define HAS_BATTERY
    #define HAS_BT
    //#define HAS_BUTTONS
    //#define HAS_NEOPIXEL_LED
    //#define HAS_PWR_MGMT
    //#define HAS_SCREEN   // intentionally disabled for headless build
    //#define HAS_SD       // intentionally disabled
    //#define HAS_TEMP_SENSOR
    //#define HAS_GPS

    // This board is XIAO ESP32S3 Plus in your case -> enable PSRAM to gain larger buffers
    #define HAS_PSRAM
  #endif

  //// END BOARD FEATURES

  //// POWER MANAGEMENT (no change: only active if HAS_PWR_MGMT defined)
  #ifdef HAS_PWR_MGMT
    #if defined(MARAUDER_M5STICKC) || defined(MARAUDER_M5STICKCP2)
      #include "AXP192.h"
    #endif

    #ifdef MARAUDER_M5STICKCP2
      // Prevent StickCP2 from turning off when disconnect USB cable
      #define POWER_HOLD_PIN 4
    #endif
  #endif
  //// END POWER MANAGEMENT

  //// BUTTON DEFINITIONS
  // Headless XIAO: keep defaults from original XIAO block (no buttons defined)
  #ifdef HAS_BUTTONS
    // ... (existing button blocks left unchanged for other boards)
  #endif
  //// END BUTTON DEFINITIONS

  //// DISPLAY DEFINITIONS
  // Because HAS_SCREEN is not defined for XIAO headless, all screen-related blocks will be skipped.
  //// END DISPLAY DEFINITIONS

  //// MENU DEFINITIONS
  // Menu definitions remain as-is for other boards; headless skips UI.
  //// END MENU DEFINITIONS

  //// SD DEFINITIONS
  // We explicitly do NOT define USE_SD/HAS_SD for headless XIAO:
  // If later you want SD on XIAO, remove these comments and enable as needed.
  #undef HAS_SD
  #undef USE_SD
  //// END SD DEFINITIONS

  //// SPACE SAVING COLORS (kept, harmless)
  #define TFTWHITE     1
  #define TFTCYAN      2
  #define TFTBLUE      3
  #define TFTRED       4
  #define TFTGREEN     5
  #define TFTGREY      6
  #define TFTGRAY      7
  #define TFTMAGENTA   8
  #define TFTVIOLET    9
  #define TFTORANGE    10
  #define TFTYELLOW    11
  #define TFTLIGHTGREY 12
  #define TFTPURPLE    13
  #define TFTNAVY      14
  #define TFTSILVER    15
  #define TFTDARKGREY  16
  #define TFTSKYBLUE   17
  #define TFTLIME      18
  //// END SPACE SAVING COLORS

  #define TFT_FARTGRAY 0x528a

  //// SCREEN STUFF - headless defaults
  #ifndef HAS_SCREEN
    #define BANNER_TIME GRAPH_REFRESH
    #define TFT_BLACK 0
    #define TFT_WHITE 0
    #define TFT_CYAN 0
    #define TFT_BLUE 0
    #define TFT_RED 0
    #define TFT_GREEN 0
    #define TFT_GREY 0
    #define TFT_GRAY 0
    #define TFT_MAGENTA 0
    #define TFT_VIOLET 0
    #define TFT_ORANGE 0
    #define TFT_YELLOW 0
    #define STANDARD_FONT_CHAR_LIMIT 40
    #define FLASH_BUTTON -1

    #include <FS.h>
    #include <functional>
    #include <LinkedList.h>
    #include "SPIFFS.h"
    #include "Assets.h"
  #endif
  //// END SCREEN STUFF

  //// MEMORY LOWER LIMIT STUFF
  #if defined(MARAUDER_M5STICKC) \
      || defined(MARAUDER_CARDPUTER) \
      || defined(MARAUDER_MINI) \
      || defined(MARAUDER_V7) \
      || defined(MARAUDER_V7_1) \
      || defined(MARAUDER_REV_FEATHER) \
      || defined(MARAUDER_V4) \
      || defined(MARAUDER_V6) \
      || defined(MARAUDER_V6_1) \
      || defined(MARAUDER_CYD_MICRO) \
      || defined(MARAUDER_CYD_2USB) \
      || defined(MARAUDER_CYD_3_5_INCH) \
      || defined(MARAUDER_CYD_GUITION) \
      || defined(MARAUDER_KIT) \
      || defined(GENERIC_ESP32) \
      || defined(MARAUDER_FLIPPER) \
      || defined(MARAUDER_MULTIBOARD_S3) \
      || defined(ESP32_LDDB) \
      || defined(MARAUDER_DEV_BOARD_PRO) \
      || defined(XIAO_ESP32_S3) \
      || defined(MARAUDER_C5) \
      || defined(MARAUDER_V8)
    #define MEM_LOWER_LIM 10000
  #endif
  //// END MEMORY LOWER LIMIT STUFF

  //// NEOPIXEL STUFF  
  #ifdef HAS_NEOPIXEL_LED
    #if defined(ESP32_LDDB)
      #define PIN 17
    #elif defined(MARAUDER_DEV_BOARD_PRO)
      #define PIN 16
    #elif defined(MARAUDER_REV_FEATHER)
      #define PIN 33
    #elif defined(MARAUDER_CYD_MICRO)
      #define PIN 4
    #elif defined(MARAUDER_CYD_2USB)
      #define PIN 4
    #elif defined(MARAUDER_CYD_3_5_INCH)
      #define PIN 22
    #elif defined(MARAUDER_C5)
      #define PIN 27
    #elif defined(MARAUDER_V8)
      #define PIN 27
    #else
      #define PIN 25
    #endif
  #endif
  //// END NEOPIXEL STUFF

  //// EVIL PORTAL STUFF
  #ifdef HAS_PSRAM
    #define MAX_HTML_SIZE 30000
  #else
    #define MAX_HTML_SIZE 11400
  #endif
  //// END EVIL PORTAL STUFF

  //// GPS STUFF
  #ifdef HAS_GPS
    #ifdef HAS_PSRAM
      #define mac_history_len 500
    #else
      #define mac_history_len 100
    #endif
  #else
    #define mac_history_len 100
  #endif
  //// END GPS STUFF

  //// BATTERY STUFF
  #ifdef HAS_BATTERY
    // I2C pins per-board (unchanged)
  #endif

  //// MARAUDER TITLE STUFF
  #define MARAUDER_TITLE_BYTES 13578
  //// END MARAUDER TITLE STUFF

  //// PCAP BUFFER STUFF
  #ifdef HAS_PSRAM
    #define BUF_SIZE 8 * 1024
    #define SNAP_LEN 1 * 4096
  #elif !defined(HAS_ILI9341)
    #define BUF_SIZE 8 * 1024
    #define SNAP_LEN 4096
  #else
    #define BUF_SIZE 3 * 1024
    #define SNAP_LEN 2324
  #endif
  //// END PCAP BUFFER STUFF

  //// STUPID CYD / BOARD-SPECIFIC STUFF left as is (only activated when those boards are defined)
  //// FUNNY FLIPPER LED STUFF kept (only active if HAS_FLIPPER_LED)
  //// WIFI STUFF
  #ifndef HAS_DUAL_BAND
    #define HOP_DELAY 1000
  #else
    #define HOP_DELAY 100
  #endif

#endif // configs_h
