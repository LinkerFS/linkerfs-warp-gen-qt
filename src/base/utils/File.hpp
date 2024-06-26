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

#ifndef LINKERFS_WARP_GEN_QT_FILE_HPP
#define LINKERFS_WARP_GEN_QT_FILE_HPP

#include <QDir>
#include "base/data/DirEntry.hpp"

namespace Utils::File {
    /**
     *
     * @param dir dirPath checked exist
     * @return
     */
    DirEntry listDir(QDir &&dir, QDir::Filter &&filter = QDir::Filter::NoFilter);

    DirEntry listDrivers();
}
#endif //LINKERFS_WARP_GEN_QT_FILE_HPP