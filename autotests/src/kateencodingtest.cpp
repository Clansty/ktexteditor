/*
    This file is part of the Kate project.
    SPDX-FileCopyrightText: 2010 Christoph Cullmann <cullmann@kde.org>
    SPDX-FileCopyrightText: 2010-2018 Dominik Haumann <dhaumann@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "katetextbuffer.h"
#include <kateglobal.h>

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    // construct core app
    QCoreApplication app(argc, argv);

    // test mode
    KTextEditor::EditorPrivate::enableUnitTestMode();

    // get arguments
    QString encoding = app.arguments().at(1);
    QString inFile = app.arguments().at(2);
    QString outFile = app.arguments().at(3);

    Kate::TextBuffer buffer(nullptr);

    // set codec
    buffer.setFallbackTextCodec(QTextCodec::codecForName("ISO 8859-15"));
    buffer.setTextCodec(QTextCodec::codecForName(encoding.toLatin1()));

    // switch to Mac EOL, this will test eol detection, as files are normal unix or dos
    buffer.setEndOfLineMode(Kate::TextBuffer::eolMac);

    // load file
    bool encodingErrors = false;
    bool tooLongLines = false;
    int longestLineLoaded;
    if (!buffer.load(inFile, encodingErrors, tooLongLines, longestLineLoaded, false) || encodingErrors) {
        return 1;
    }

    // save file
    if (!buffer.save(outFile)) {
        return 1;
    }

    return 0;
}
