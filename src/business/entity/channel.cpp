//
// Created by CGR on 16/05/2020.
//

#include "channel.h"

namespace business {

    Channel::Channel(const wchar_t *channelName) {
        m_channelName = channelName;
    }

    bool Channel::isOfType(int type) {
        return type == 0;
    }

    const wchar_t *Channel::description() {
        return L"Channel";
    }

    const wchar_t *Channel::name() {
        return m_channelName.c_str();
    }

    int Channel::insertUser(User &user) {
        m_users.push_back(&user);
        return m_users.size() - 1;
    }

    void Channel::removeUser(User &user) {
        //TODO(CGR): A more elegant way to remove player from list
        auto it = m_users.begin();
        for (; it != m_users.end(); ++it) {
            User *u = *it;
            if (u == &user) {
                m_users.erase(it);
                return;
            }
        }
    }

    bool Channel::isUserIn(const wchar_t *userName) {
        return false;
    }

}