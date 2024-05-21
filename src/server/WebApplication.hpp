/*
 * linkerfs_warp_gen_qt: warp configuration file generator backend for project linkerfs
 * Copyright (C) 2024  kaedeair <kaedeair@outlook.com>
 *
 * This file is part of linkerfs_warp_gen_qt.
 *
 * linkerfs_warp_gen_qt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * linkerfs_warp_gen_qt is distributed in the hope that it will be useful,but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with linkerfs_warp_gen_qt. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LINKERFS_WARP_GEN_QT_WEBAPPLICATION_HPP
#define LINKERFS_WARP_GEN_QT_WEBAPPLICATION_HPP

#include <QObject>
#include <QHttpServer>
#include <QHostAddress>

#include "base/template/InstanceManager.hpp"

class WebApplication : public QObject {
Q_OBJECT

    friend InstanceManager<WebApplication>;
public:
    static WebApplication *Instance() {
        if (instanceMgr.instance == nullptr)
            instanceMgr.instance = new WebApplication();
        return instanceMgr.instance;
    };

    void run(const QHostAddress &&address, const quint16 &&port = 0);

private:
    explicit WebApplication() {};

    ~WebApplication() override {
        QObject::~QObject();
    };
private:
    static InstanceManager<WebApplication> instanceMgr;
    QHttpServer httpServer;
};

#endif //LINKERFS_WARP_GEN_QT_WEBAPPLICATION_HPP