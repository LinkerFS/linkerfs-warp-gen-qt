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

#ifndef LINKERFS_WARP_GEN_QT_RESPONSEDTO_HPP
#define LINKERFS_WARP_GEN_QT_RESPONSEDTO_HPP

#include <QtTypes>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHttpServerResponse>

#include "common/enum/ResponseStatus.hpp"

class ResponseDto {

public:
    static QHttpServerResponse success(QJsonValue &&jsonValue) {
        ResponseDto responseDto(ResponseStatus::ResponseStatus_OK, QObject::tr("Success"), std::move(jsonValue));
        auto resp = QHttpServerResponse("application/json;charset=UTF-8", responseDto.toByteArray(),
                                        QHttpServerResponse::StatusCode::Ok);
        return std::move(resp);
    }

    static QHttpServerResponse fail(QString &&msg) {
        ResponseDto responseDto(ResponseStatus::ResponseStatus_Fail, std::move(msg),
                                QJsonValue(QJsonValue::Type::Null));
        auto resp = QHttpServerResponse("application/json;charset=UTF-8", responseDto.toByteArray(),
                                        QHttpServerResponse::StatusCode::Ok);
        return std::move(resp);
    }

    static QHttpServerResponse success() {
        return success(QJsonValue(QJsonValue::Type::Null));
    }

private:
    explicit ResponseDto(int &&code, QString &&msg, QJsonValue &&data) : code(code), msg(msg), data(data) {}

    QByteArray toByteArray() {
        QJsonObject jsonObject;
        jsonObject.insert("code", code);
        jsonObject.insert("data", data);
        jsonObject.insert("msg", msg);
        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);
        return jsonDocument.toJson(QJsonDocument::Compact);
    }

    int code;
    QString msg;
    QJsonValue data;

};

#endif //LINKERFS_WARP_GEN_QT_RESPONSEDTO_HPP