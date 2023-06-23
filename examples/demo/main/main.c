/* Simple firmware for a ESP32 displaying a static image on an EPaper Screen.
 *
 * Write an image into a header file using a 3...2...1...0 format per pixel,
 * for 4 bits color (16 colors - well, greys.) MSB first.  At 80 MHz, screen
 * clears execute in 1.075 seconds and images are drawn in 1.531 seconds.
 */

#include "esp_heap_caps.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include "epd_driver.h"
#include "epd_highlevel.h"

// select the font based on display width
#if (EPD_WIDTH < 1000)
#include "firasans_12.h"
#define FONT FiraSans_12
#else
#include "firasans_20.h"
#define FONT FiraSans_20
#endif
#include "img_fairy.h"

#define WAVEFORM EPD_BUILTIN_WAVEFORM

#ifndef ARDUINO_ARCH_ESP32
void delay(uint32_t millis) { vTaskDelay(millis / portTICK_PERIOD_MS); }

uint32_t millis() { return esp_timer_get_time() / 1000; }
#endif

uint32_t t1, t2;

int temperature;
EpdiyHighlevelState hl;

}

void idf_loop() {

  enum EpdDrawError err;

  uint8_t* fb = epd_hl_get_framebuffer(&hl);

}

void idf_setup() {
  heap_caps_print_heap_info(MALLOC_CAP_INTERNAL);
  heap_caps_print_heap_info(MALLOC_CAP_SPIRAM);

  epd_init(EPD_LUT_1K);
  hl = epd_hl_init(WAVEFORM);

  // Default orientation is EPD_ROT_LANDSCAPE
  epd_set_rotation(EPD_ROT_LANDSCAPE);

  printf("Dimensions after rotation, width: %d height: %d\n\n", epd_rotated_display_width(), epd_rotated_display_height());
}

#ifndef ARDUINO_ARCH_ESP32
void app_main() {
  idf_setup();

  while (1) {
    idf_loop();
  };
}
#endif
