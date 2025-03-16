#include "server.h"
#include "esp_http_server.h"
#include "motor_control.h"

static esp_err_t control_handler(httpd_req_t *req) {
    char buf[100];
    int ret = httpd_req_recv(req, buf, sizeof(buf));
    if (ret <= 0) return ESP_FAIL;

    buf[ret] = '\0';
    move_robot(buf); // Execute movement command
    httpd_resp_send(req, "OK", 2);
    return ESP_OK;
}

void start_web_server() {
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;
    httpd_start(&server, &config);
    httpd_uri_t uri = {
        .uri = "/control",
        .method = HTTP_GET,
        .handler = control_handler,
        .user_ctx = NULL
    };
    httpd_register_uri_handler(server, &uri);
}
