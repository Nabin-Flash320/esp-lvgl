

#include "esp_err.h"
#include "esp_log.h"
#include "lvgl/lvgl.h"
#include "esp_lcd_panel_commands.h"
#include "ili9486_drv.h"


#define TFT_HORIZONTAL_RESOLUTION 480
#define TFT_VERTICAL_RESOLUTION 320


static void tft_display_driver_flush_callback(lv_disp_drv_t *driver, const lv_area_t *area, lv_color_t *color_map)
{
    ESP_LOGI(__FILE__, "Function is %s", __func__);
}


void app_main()
{

    static lv_disp_drv_t display_driver;
    static lv_disp_draw_buf_t display_draw_buffer;


    ESP_LOGI(__FILE__, "HERE!!");

    lv_init();


    lv_color16_t *first_buffer = (lv_color16_t*)lv_mem_alloc(TFT_HORIZONTAL_RESOLUTION* 100 * sizeof(lv_color16_t));
    lv_color16_t *second_buffer = (lv_color16_t*)lv_mem_alloc(TFT_HORIZONTAL_RESOLUTION * 100 * sizeof(lv_color16_t));

    if((NULL != first_buffer) && (NULL != second_buffer))
    {
        ESP_LOGI(__FILE__, "No null buffers!!");
        lv_disp_draw_buf_init(&display_draw_buffer, first_buffer, second_buffer, 100 * TFT_HORIZONTAL_RESOLUTION);

        lv_disp_drv_init(&display_driver);
        display_driver.hor_res = TFT_HORIZONTAL_RESOLUTION;
        display_driver.ver_res = TFT_VERTICAL_RESOLUTION;
        display_driver.flush_cb = tft_display_driver_flush_callback;
        display_driver.draw_buf = &display_draw_buffer;
        display_driver.user_data = NULL;
    }


}

