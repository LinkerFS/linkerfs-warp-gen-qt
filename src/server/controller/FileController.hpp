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
#ifndef LINKERFS_WARP_GEN_QT_FILECONTROLLER_HPP
#define LINKERFS_WARP_GEN_QT_FILECONTROLLER_HPP

#include <QHttpServerResponse>
#include <QHttpServerRequest>
#include "dto/request/ListDirReqDto.hpp"
#include "dto/response/ListDirRespDto.hpp"
#include "dto/ResponseDto.hpp"
#include "base/utils/File.hpp"

namespace Controller::File {
    QHttpServerResponse listDir(const QHttpServerRequest &request) {
        auto dto = std::make_unique<ListDirReqDto>();
        QString errMsg;
        if (dto->convertRequest(request.body(), errMsg)) {
            QDir dir(dto->getDirPath());
            if (dir.exists()) {
                ListDirRespDto resp(Utils::File::listDir(std::move(dir)));
                return ResponseDto::success(resp.toJsonValue());
            } else {
                return ResponseDto::fail(QString("Dir: %1 is not found!").arg(dto->getDirPath()));
            }
        } else {
            return ResponseDto::fail(std::move(errMsg));
        }
    }
}
#endif //LINKERFS_WARP_GEN_QT_FILECONTROLLER_HPP