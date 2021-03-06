//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include <cstdio>
#include <string>

#include "ngraph/distributed.hpp"
#include "ngraph/except.hpp"

namespace ngraph
{
    namespace distributed
    {
        class NullDistributedInterface : public DistributedInterface
        {
            const std::string& get_name() const override { return m_name; }
            int get_size() override { return 0; }
            int get_rank() override { return 0; }
            void log_print(const std::string& timestamp, const std::vector<char>& buf) override
            {
                std::printf("%s: %s\n", timestamp.c_str(), buf.data());
            }
            void
                all_reduce(void* in, void* out, element::Type_t element_type, size_t count) override
            {
                throw ngraph_error("Distributed Library not supported/mentioned");
            }

            void broadcast(void* in, element::Type_t element_type, size_t count) override
            {
                throw ngraph_error("Distributed Library not supported/mentioned");
            }

        protected:
            std::string m_name{"NULL"};
        };
    }
}
