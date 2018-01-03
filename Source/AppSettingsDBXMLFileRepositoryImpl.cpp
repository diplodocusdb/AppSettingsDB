/*
    Copyright (c) 2015-2018 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "AppSettingsDBXMLFileRepositoryImpl.h"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>

namespace DiplodocusDB
{

AppSettingsDBXMLFileRepositoryImpl::AppSettingsDBXMLFileRepositoryImpl()
{
}

AppSettingsDBXMLFileRepositoryImpl::~AppSettingsDBXMLFileRepositoryImpl()
{
}

void AppSettingsDBXMLFileRepositoryImpl::create(const VersionNumber& version, 
                                                const boost::filesystem::path& path)
{
    boost::filesystem::path pathDir(path);
    pathDir.remove_filename();
    boost::filesystem::create_directories(pathDir);
    boost::filesystem::ofstream file(path);

    m_rootNode = m_document.append_child("application-settings");
    if (m_rootNode)
    {
        pugi::xml_node versionNode = m_rootNode.append_child("version");
        versionNode.text().set(version.toString().c_str());

        m_document.save(file);
    }
}

void AppSettingsDBXMLFileRepositoryImpl::open(const boost::filesystem::path& path)
{
}

}
