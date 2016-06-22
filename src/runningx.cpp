/*
 * runningx - Test whether an X-Server is currently running or not.
 * Copyright © 2016 Till Smejkal <till.smejkal+runningx@ossmail.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>
#include <string>

#include <X11/Xlib.h>


bool is_X_running() {
    auto dsp = XOpenDisplay(nullptr);

    if (dsp) {
        XCloseDisplay(dsp);
        return true;
    } else {
        return false;
    }
}

void usage(const std::string& prog) {
    std::cout << "usage: " << prog << " [-h] [-q]" << std::endl
        << std::endl
        << "Check whether an X-server is running or not." << std::endl
        << std::endl
        << "optional arguments:" << std::endl
        << "  -h, --help       show this help message and exit" << std::endl
        << "  -q, --quiet      do not print any output" << std::endl;
}

int main(int argc, char *argv[])
{
    /* Possible arguments */
    bool quiet = false;

    /* Parse arguments */
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            std::string arg{argv[i]};

            if (arg == "--help" || arg == "-h") {
                usage(argv[0]);
                return 0;
            } else if (arg == "--quiet" || arg == "-q") {
                quiet = true;
            } else {
                std::cout << "Unknown argument: " << arg << std::endl;
                usage(argv[0]);
                return 2;
            }
        }
    }

    if (is_X_running()) {
        if (!quiet) {
            std::cout << "X is running." << std::endl;
        }

        return 0;
    } else {
        if (!quiet) {
            std::cout << "X is not running." << std::endl;
        }

        return 1;
    }
}
