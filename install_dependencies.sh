#!/bin/bash

if [[ -z $HYRISE_HEADLESS_SETUP ]]; then
    read -p 'This script installs the dependencies. It might upgrade already installed packages. Continue? [y|n] ' -n 1 -r < /dev/tty
else
    REPLY="y"
fi

echo
if echo $REPLY | grep -E '^[Yy]$' > /dev/null; then
    unamestr=$(uname)
    if [[ "$unamestr" == 'Darwin' ]]; then
        brew --version 2>/dev/null || /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

        echo "Installing dependencies (this may take a while)..."
        if brew update >/dev/null; then
            # check, for each program (aka. formula) individually with brew, whether it is already installed due to brew issues on macOS after system upgrade
            # NOTE: The Mac CI server does not execute the install_dependencies.sh - formulas need to be installed manually.
            for formula in cmake dos2unix parallel; do
                # if brew formula is installed
                if brew ls --versions $formula > /dev/null; then
                    continue
                fi
                if ! brew install $formula; then
                    echo "Error during brew formula $formula installation."
                    exit 1
                fi
            done

            if ! brew install llvm; then
                echo "Error during llvm/clang installation."
                exit 1
            fi

            if ! git submodule update --jobs 5 --init --recursive --depth 1; then
                echo "Error during git fetching submodules."
                exit 1
            fi
        else
            echo "Error during installation."
            exit 1
        fi
    else
        echo "Unsupported operating system $unamestr."
        exit 1
    fi
fi

echo "Dependencies installed successfully."
exit 0