/*
 * Copyright 2023 Babit Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef BMF_PULL_STREAM_MODULE_H
#define BMF_PULL_STREAM_MODULE_H

#include "common.h"

#include "packet.h"
#include "video_frame.h"
#include "task.h"
#include "module.h"
#include "audio_frame.h"
#include "module_registry.h"
#include <fstream>

USE_BMF_SDK_NS

class PullStreamModule : public Module {
  public:
    PullStreamModule(int node_id, JsonParam option);

    ~PullStreamModule() {}

    virtual int process(Task &task);
    std::string input_path_;
    std::ifstream f_data;
    std::ifstream f_size;
    std::ifstream f_pts;
    AVFormatContext *input_fmt_ctx_;
    std::string pts_file_path_;
    int stream_index_;
    int64_t pts_ = 28774 - 66;
    int timestamp_ = 0;
};

#endif
