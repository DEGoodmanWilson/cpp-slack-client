//
// engine
//
// Copyright © 2015–2016 D.E. Goodman-Wilson. All rights reserved.
//

#include "slack/web/chat.delete.h"
#include "private.h"

namespace slack { namespace chat
{

const std::string delete_it::error::MESSAGE_NOT_FOUND = std::string{"message_not_found"};
const std::string delete_it::error::CHANNEL_NOT_FOUND = std::string{"channel_not_found"};
const std::string delete_it::error::CANT_DELETE_MESSAGE = std::string{"cant_delete_message"};
const std::string delete_it::error::COMPLIANCE_EXPORTS_PREVENT_DELETION = std::string{
        "compliance_exports_prevent_deletion"};
const std::string delete_it::error::NOT_AUTHED = std::string{"not_authed"};
const std::string delete_it::error::INVALID_AUTH = std::string{"invalid_auth"};
const std::string delete_it::error::ACCOUNT_INACTIVE = std::string{"account_inactive"};


void delete_it::initialize_()
{
    auto params = default_params({
            {"ts",      ts_},
            {"channel", channel_}
    });

    auto result_ob = slack_private::get(this, "chat.delete", params);

    if(this->success())
    {
        if (result_ob["channel"].isObject()) channel = slack::channel_id{result_ob["channel"].asString()};
        if (result_ob["ts"].isObject()) ts = slack::ts{result_ob["ts"].asString()};
    }
}

}} //namespace channel slack