#pragma once
//    io/read.hpp - Input from files.
//
//    Copyright © 2013 Ben Longbons <b.r.longbons@gmail.com>
//
//    This file is part of The Mana World (Athena server)
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "fwd.hpp"

#include "dir.hpp"
#include "fd.hpp"

namespace tmwa
{
namespace io
{
    class ReadFile
    {
    private:
        FD fd;
        unsigned short start, end;
        char buf[4096];
    public:
        explicit
        ReadFile(FD fd);
        explicit
        ReadFile(ZString name);
        ReadFile(const DirFd& dir, ZString name);

        ReadFile& operator = (ReadFile&&) = delete;
        ReadFile(ReadFile&&) = delete;
        ~ReadFile();

        bool get(char&);
        size_t get(char *buf, size_t len);
        bool getline(AString&);

        bool is_open();
    };
} // namespace io
} // namespace tmwa
