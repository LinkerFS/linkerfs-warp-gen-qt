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

#ifndef LINKERFS_WARP_GEN_QT_DIRDTO_HPP
#define LINKERFS_WARP_GEN_QT_DIRDTO_HPP

#include "common/abstract/AbstractRespDataDto.hpp"
#include "base/data/DirEntry.hpp"

class ListDirRespDto : public AbstractRespDataDto, public DirEntry {
public:
    explicit ListDirRespDto(DirEntry &&dirEntry) noexcept {
        dirPath = std::move(dirEntry.dirPath);
        dirList = std::move(dirEntry.dirList);
        fileList = std::move(dirEntry.fileList);
    };

    QJsonValue toJsonValue() override {
        QJsonObject object;
        QJsonArray dirArray;
        for (const auto &dir: dirList) {
            QJsonObject dirObject;
            dirObject.insert("name", dir.first);
            dirObject.insert("isEmpty", dir.second);
            dirArray.push_back(dirObject);
        }
        object.insert("dirPath", dirPath);
        object.insert("fileList", QJsonArray::fromStringList(fileList));
        object.insert("dirList", dirArray);
        return object;
    }
};

#endif //LINKERFS_WARP_GEN_QT_DIRDTO_HPP