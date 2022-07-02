# About

A simple simulation of a library database using structures in C.

# Usage

- Download the relevant binary from the [releases](https://github.com/hyPnOtICDo0g/structdb/releases/latest) section.
- Run the executable.

# Build

## Dependencies

- GCC (linux)
- MinGW-w64 (windows)
- make
- git
- [gow](https://github.com/bmatzelle/gow) (windows)

> Dependencies can be installed via [scoop](https://scoop.sh). (Windows only)
```
scoop install git gow mingw-winlibs
```

## Procedure

- Clone the repo.

    ```
    git clone https://github.com/hyPnOtICDo0g/structdb --depth=1
    ```

- Navigate to the repo's folder.

    ```
    cd structdb
    ```

- Build.
    ```
    make build
    ```

# Credits

- [LekKit](https://github.com/LekKit) - C [Implementation](https://github.com/LekKit/sha256) of the SHA-256 hashing algorithm
