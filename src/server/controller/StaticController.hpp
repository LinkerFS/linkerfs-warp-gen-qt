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
#ifndef LINKERFS_WARP_GEN_QT_STATICCONTROLLER_HPP
#define LINKERFS_WARP_GEN_QT_STATICCONTROLLER_HPP

#include <QHttpServerResponse>
#include <QHttpServerRequest>
#include <QFileInfo>
#include <QUrl>

using namespace Qt::StringLiterals;
namespace Controller::Static {
    static QHttpServerResponse redirectStatic() {
        auto response = QHttpServerResponse(QHttpServerResponder::StatusCode::MovedPermanently);
        response.setHeader("Location", "/webui");
        return response;
    }

    static QHttpServerResponse staticFile(const QUrl &url) {
        QFileInfo file(QString("./dist/%1").arg(url.path()));
        if (file.exists() && file.isFile())
            return QHttpServerResponse::fromFile(u"./dist/"_s + url.path());
        else
            return QHttpServerResponse::fromFile("./dist/index.html");
    }
}
#endif //LINKERFS_WARP_GEN_QT_STATICCONTROLLER_HPP