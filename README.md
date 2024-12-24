![screen-capture](https://github.com/user-attachments/assets/75026775-99e3-4f22-b6f4-9ef54125346e)

# Getting Started

## Build

Create a build directory and run CMake:

```bash
mkdir build
cd build
cmake ..
```

Compile the application:

```bash
cmake --build .
```

# Emscripten Web Target

## Setup emscripten

Install emscripten

```bash
brew install emscripten
```

Install SDK

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk

# Download and install the latest SDK tools.
./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes .emscripten file)
./emsdk activate latest

# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh
```

## Build for Web

```bash
mkdir build-web
cd build-web
```

Run CMake with Emscripten: Use Emscripten's emcmake wrapper for CMake:

```bash
emcmake cmake ..
```

Compile the Web Target: Build the project with:

```bash
cmake --build .
```

This will produce RaylibWeb.html, RaylibWeb.js, and RaylibWeb.wasm.

Example HTML shell

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Raylib Web</title>
</head>
<body>
    <script>
        var Module = {
            onRuntimeInitialized: function() {
                console.log('WASM loaded successfully!');
            }
        };
    </script>
    <script src="RaylibWeb.js"></script>
</body>
</html>
```
