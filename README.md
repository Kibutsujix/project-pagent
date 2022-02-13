# About

A simple program to represent a library database using structures in C.

# Usage

- Download the relevant binary from the [releases](https://github.com/hyPnOtICDo0g/structdb/releases/latest) section.
- Run the executable.

# Build

## Dependencies

- GCC <=9.3.0 (linux)
- MinGW-w64 <=8.1.0 (windows)
- make
- git

> Building using other versions of GCC haven't been tested. Expect build errors.

## Procedure

- Clone the repo.

    ```
    git clone https://github.com/hyPnOtICDo0g/structdb --depth 1
    ```

- Navigate to the repo's folder.

    ```
    cd structdb
    ```

### Linux

```
make linux
````

### Windows

> Dependencies can be installed via [scoop](https://scoop.sh).

```
scoop install git mingw
make windows
```
