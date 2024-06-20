# linkerfs-warp-gen-qt

a warp configuration file generator backend for project linkerfs powered by Qt.

## Repository Status

This repository is **Abandoned** at current, just as an example to use Qt::Httpserver.

## Features

1. api implement: list dir

> Request:
> ```json
> {
>     "dirPath":"<path>"
> }
> ```
> Response:
> ```json
> {
>   "code": 200,
>   "data": {
>     "dirPath": "<path>",
>     "fileList": [
>       {
>         "name": "<fileName>",
>         "size": 0
>       }
>     ],
>     "dirList": [
>       {
>         "name": "<dirName>",
>         "isEmpty": false
>       }
>     ]
>   },
>   "msg": "Success"
> }
> ```

2. serve a directory `dist` build by webpack at working directory with `/webui` base prefix
3. server is running at `0.0.0.0:8080`

## Build

```shell
mkdir build && cd build
cmake ..
make
```

## Credits

[Qt](https://www.qt.io/) License: [GPLv3](http://www.gnu.org/licenses/gpl-3.0.html)


