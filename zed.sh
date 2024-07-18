#!/usr/bin/env sh
set -eu

# Remove Zed application directories
rm -rf ~/.local/zed*

# Remove the binary link
rm -f ~/.local/bin/zed

# Remove the desktop entries
rm -f ~/.local/share/applications/dev.zed.Zed*.desktop

# Verify and clean up remaining files or directories related to Zed
find ~/.local -name "*zed*" -exec rm -rf {} +

echo "Zed has been successfully uninstalled."
