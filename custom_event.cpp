/*
 * Copyright (c) AppDynamics, Inc., and its affiliates
 * 2017
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "custom_event.hpp"

/**
 * @brief Fills a custom event structure and <br>
 * calls IoT CPP SDK API to add and send the event
 */
void send_custom_event(void)
{
  appd_iot_custom_event_t custom_event;
  appd_iot_error_code_t retcode;

  // TODO initialize the custom event struct

  custom_event.type = "Smart Car";
  custom_event.summary = "Events Captured in Smart Car";
  custom_event.timestamp_ms = ((int64_t)time(NULL) * 1000);
  custom_event.duration_ms = 10;
  custom_event.data_count = 6;
  custom_event.data = (appd_iot_data_t*)calloc(custom_event.data_count, sizeof(appd_iot_data_t));

  if (custom_event.data == NULL)
  {
    fprintf(stderr, "Error allocating memory for Custom Event Data\n");
    return;
  }

  // TODO add some data to the custom event. Use
  // appd_iot_data_set_string, _integer, _double, _boolean and _datetime.
  int64_t engine_start_time = ((int64_t)time(NULL) * 1000);

  // TODO send the custom event
  // retcode = 
  fprintf(stdout, "Add Custom Event Status :%s\n", appd_iot_error_code_to_str(retcode));

  free(custom_event.data);

  if (retcode == APPD_IOT_SUCCESS)
  {
    retcode = appd_iot_send_all_events();
    fprintf(stdout, "Send Custom Event Status :%s\n\n", appd_iot_error_code_to_str(retcode));
  }
}
