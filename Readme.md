# runningx

Small tool to determine whether an X-Server is currently running on the computer or
not. This tool is especially useful for mailcap options.

## Installation

To build and install the program just simply run the following commands:

```bash
mkdir build
cd build && cmake ..
make
make install
```

Or simply install the package provided by your distribution.

## Usage

The intention of this program is to use as 'test' in mailcap file rules as shown in
the example below.

```mailcap
text/html;          firefox %s;     test=runningx
text/html;          elinks %s;      nametemplate=%s.html
```

Accordingly, in the example firefox will only be used to show the html document if an
X-Server is currently running. Otherwise elinks is used to present the document.
