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

#include "WebApplication.hpp"
#include "controller/StaticController.hpp"
#include "controller/FileController.hpp"

InstanceManager<WebApplication> WebApplication::instanceMgr;

void WebApplication::run(const QHostAddress &&address, const quint16 &&port) {

    httpServer.route("/api/file/listDir", QHttpServerRequest::Method::Post, Controller::File::listDir);
    httpServer.route("/webui", QHttpServerRequest::Method::Get, Controller::Static::staticFile);
    httpServer.route("/", QHttpServerRequest::Method::Get, Controller::Static::redirectStatic);
    httpServer.listen(address, port);
    qInfo() << tr("Server is running at %1:%2").arg(address.toString()).arg(port);
}