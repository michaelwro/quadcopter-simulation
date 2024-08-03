# Quadcopter Simulation


## Required Linting Tools

By default, we require the following to be set up:

- Clang-Format for C/C++ styling.
  - Enable the "format on save" setting is in your editor.
  - See `.clang-format` ofr the style.
- Trim trailing whitespaces.
  - Enable the "trim trailing whitespace on save" setting in your editor.
- Black 24.X.X and isort 5.X.X for Python formatting.

We have CI configured to enforce these on every push and pull request. The easiest way to follow with our style guide is to use Pre-Commit.

### Pre-Commit Setup

Set up a Python venv and install pre-commit.

```shell
# create venv
python3 -m venv .venv
source .venv/bin/activate

# install pre-commit
python3 -m pip install pre-commit

# install git hooks
pre-commit install
```

## Build Commands

There are two ways to build the code - CMake terminal commands or VS Code build tasks.

### Build w/ Terminal Commands

We use CMake 3.19+. We have CMake presets defined in `CMakePresets.json`.

```shell
# debug build
cmake --preset debug && cmake --build --preset debug

# release build
cmake --preset release && cmake --build --preset release
```

### Build w/ VS Code

Use `CTRL+SHIFT+B` to pull up the configured VS Code build tasks we set up.
