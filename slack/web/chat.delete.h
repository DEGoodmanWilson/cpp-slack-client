//
// Copyright © 2015 D.E. Goodman-Wilson. All rights reserved.
//

#pragma once

#include <slack/types.h>
#include <slack/set_option.h>
#include <slack/base/response.h>
#include <string>
#include <vector>
#include <slack/optional.hpp>

namespace slack { namespace chat
{

class delete_it : public slack::base::response
{
public:
    //public interface
    delete_it(const std::string &token, const ts &ts, const channel_id &channel) :
            response{token}, ts_{ts}, channel_{channel}
    {
        initialize_();
    }

    //parameters
    struct parameter
    {

    };

    //errors
    struct error :
            public slack::base::error
    {
        static const std::string MESSAGE_NOT_FOUND;
        static const std::string CHANNEL_NOT_FOUND;
        static const std::string CANT_DELETE_MESSAGE;
        static const std::string COMPLIANCE_EXPORTS_PREVENT_DELETION;
        static const std::string NOT_AUTHED;
        static const std::string INVALID_AUTH;
        static const std::string ACCOUNT_INACTIVE;
    };

    //response
    std::experimental::optional<slack::channel_id> channel;
    std::experimental::optional<slack::ts> ts;

    //parameter setters

private:
    void initialize_();

    class ts ts_;
    channel_id channel_;
};

}} //namespace chat slack